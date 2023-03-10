// Name : Ruvail Shahzad
// EUID :rs0737

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
        pid_t pid;
        pid = fork();           // fork() system call creates child process

        if(pid == 0)            // child process
        {
                exit(0);
        }
        else if(pid > 0)     // parent process
        {
                sleep (3);
                system("ps -e -o pid,ppid,stat,user,cmd | grep $USER");
        }
        else
        {
                perror("fork error");
                exit(1);
        }
}
