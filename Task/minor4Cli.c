#include <stdio.h>      /*  for printf() ... */
#include <stdlib.h>     /*  for atoi(), exit(), malloc(), free()*/
#include <netdb.h>      /*  for gethostby...() and getnet...() and getserver...()   */
#include <sys/socket.h> /*  for socket(), bind()  and connect()  */
#include <sys/types.h>  /*  for socket(), bind()  and connect()  */
#include <netinet/in.h> /*  for sockaddr_in and in_addr_t   */
#include <arpa/inet.h>  /*  for htonl, htons, ntohl and ntohs*/
#include <time.h>       /*  for clock() */
#include <signal.h>     /*  To  handle CTRL+C signal(sigint)    */
#include <stdbool.h>    /*  for use true/false and type bool */
#include <string.h>     /*  for memset()    */
#include <unistd.h>     /*  for close()     */


#define BUFFER_SIZE 100
#define INTERVAL_REQUEST 1000/* units: ms (2s)  Windows use 4sec() and Linux 1 for non-super user(Source: manual page(ping))*/
#define REQUEST "Ping : Request (8)\n"
#define REPLY "Ping : Reply (0)_______________________________________________\n"
#define MAX_PINGS_LOST 15

/*  Main data structure for make a ping request */
typedef struct ping{

    char * server_name;
    char * port;
    int socket;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int pings_sent,pings_lost, pings_rcv;
    ssize_t data_send, data_recv; //Units : bytes
    struct hostent * resolv;

} ping_t;

/*  Fuctions Declaration    */
volatile bool shouldKeep_pinging = true;
void CTRLDhandler(int a);
void Send_ping(ping_t * , char *, ssize_t *, clock_t * );
void waitReply(ping_t * ,ssize_t * , clock_t * );
int  IntervalTimer(clock_t * , clock_t *);
void StatisticsPing(ping_t *, char *,double);


int main(int argc, char * argv []){

    /*  Var.aux */
    ping_t pet_ping;
    char ping_request[]= {REQUEST};
    int timer_ms = 0;
    clock_t interval,init_send;
    ssize_t n_data_ = 0;
    time_t init,fin;
    time(&init);


    /*  ----    Here starts our program     ----  */

    /* Prepare CTRL+C exit */
    if(signal(SIGINT, &CTRLDhandler) == SIG_ERR){
        printf("Error: cannot set signal handler\n");
        exit(1);
    }

    /*  Check arg's   */
    if(argc > 3){
        printf("Error: Usage: %s <destination> <port>\n",argv[0]);
        exit(1);
    }else{

        /*  DNS query */
        pet_ping.resolv = gethostbyname(argv[1]);


        if((pet_ping.resolv) == NULL){
           printf("Error: cannot find Ip\n");
           exit(1);
        }else{

            pet_ping.pings_sent = 0;
            pet_ping.pings_rcv = 0;
            pet_ping.pings_lost=0;
            pet_ping.data_send = 0;
            pet_ping.data_recv = 0;
            pet_ping.server_name = pet_ping.resolv->h_addr_list[0];
            pet_ping.port = argv[2];

            /*
             *  Let's fill our socket addr with 0, for compatibility (struct sockaddr_in) - (struct sockaddr)
             *
             *  It'll be better explained in the readme or in the memory, still I don't know what I will do :s
             *
             */

            memset(&pet_ping.server, 0 , sizeof(struct sockaddr_in));
            pet_ping.server.sin_family = AF_INET;
            pet_ping.server.sin_port = htons(atoi(pet_ping.port)); /* To big Endian   */
            bcopy((char *)pet_ping.resolv->h_addr_list[0],(char *)&pet_ping.server.sin_addr.s_addr,pet_ping.resolv->h_length);


            /*  Create a stream socket - UDP */
            if((pet_ping.socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0){
                printf("Error: cannot create a socket() :L \n");
                exit(1);
            }


            /* First Ping */
            printf("\nPING %s (%s) with %ld bytes of data.\n",argv[1], inet_ntoa(*((struct in_addr *) pet_ping.resolv->h_addr_list[0])), sizeof(REQUEST));
            Send_ping(&pet_ping, ping_request, &n_data_,&init_send);

            while(shouldKeep_pinging){

                /*    Get Interval    */
                timer_ms = IntervalTimer(&interval,&init_send);

                /*  Should we ping again, the interval has reached? */
                if(timer_ms >= INTERVAL_REQUEST){

                    Send_ping(&pet_ping, ping_request, &n_data_,&init_send);

                /*  Just enter to receive if there are pings to receive,
                    we do not want it to be left waiting for pings that do not exist
                    (The server is a passive element, only responds)*/

                }else if(pet_ping.pings_sent > pet_ping.pings_rcv){

                    waitReply(&pet_ping,&n_data_,&init_send);

                /*  I consider that if 15 pings have been lost the server is not reachable  */
                }else if(pet_ping.pings_lost == MAX_PINGS_LOST){
                    break;
                }
            }

            /*  If user do CTRL+C : track fin time(Not too accurarte, just seconds of precision) , and show the statistics + close the connection */
            time(&fin);
            StatisticsPing(&pet_ping,argv[1],difftime(fin ,init));
            close(pet_ping.socket);
        }


    }

    return 0;
}

/*  Fuctions definitions   */

void CTRLDhandler(int a){

    shouldKeep_pinging = false;
}

void Send_ping(ping_t * pet, char * request, ssize_t * n_data_sent,clock_t * init_send){

    *(n_data_sent) = sendto(pet->socket, request,strlen(request), 0, (struct sockaddr *)&pet->server,sizeof(pet->server));
    *(init_send) = clock();
    if(*(n_data_sent) < 0){
        printf("Error: cannot send a request\n");
        exit(1);
    }else{
        pet->pings_sent++;
        pet->data_send += *(n_data_sent) ;
    }
}

void waitReply(ping_t * pet, ssize_t * n_data_recv,  clock_t * init_send){
    /*  Var.aux */
    size_t total_data_rcv = 0;
    clock_t aux_intv;
    /*
     *  Let's assume that if we don't receive a response before 80% of the send interval,
     *  the ping has been lost.
     *
     *  With this approach we try that there are no race conditions at the time of sending and receiving pings,
     *  and that the send interval is respected.
     *
     *  In addition, to not complicating the program anymore, otherwise we would have to add another counter
     *  that is responsible for establishing if a package is has lost.
     *
     *  :)
     *
     */

    while( total_data_rcv  < (strlen(REPLY)) ){

        *(n_data_recv) = recvfrom(pet->socket,pet->buffer,BUFFER_SIZE -1 , 0,(struct sockaddr *)0,(int *)0);

        if(*(n_data_recv) < 0){
            printf("Error: cannot recv data\n");
            exit(1);
        }

        total_data_rcv += *(n_data_recv);
        pet->buffer[*n_data_recv] = '\0';
        pet->data_recv += *(n_data_recv);

        if(IntervalTimer(&aux_intv,init_send) > (0.9*INTERVAL_REQUEST)){

            pet->pings_lost++;
            break;
        }
    }

    if(total_data_rcv  == (strlen(REPLY))){
        pet->pings_rcv++;
        printf("%ld bytes from %s (%s): num_seq=%d time=%d ms\n", total_data_rcv, pet->resolv->h_name,inet_ntoa(*((struct in_addr *) pet->resolv->h_addr_list[0])),pet->pings_rcv,IntervalTimer(&aux_intv,init_send));

    }
}

int  IntervalTimer(clock_t * interval, clock_t * init_send){
    *interval = clock() - *init_send;
    return (((*interval) * 1000) / CLOCKS_PER_SEC);
}

void StatisticsPing(ping_t * pet, char * name, double  tm){


    printf("\n--- %s ping statistics ---\n",name);
    printf("%d packets transmitted, %d received, %0.3f%c packet loss, total time %0.2f (s)\n\n",pet->pings_sent, (pet->pings_rcv), 100*((float)(pet->pings_lost)/pet->pings_sent),0x25,tm);
}