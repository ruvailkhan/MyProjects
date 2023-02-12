#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE!TRUE
#define MAX_BUFFER_SIZE 512
#define MAX_ARG_LEN 100
#define MAX_ARG_COUNT 10
#define CMD_LEN 50
#define CMDLINE_LEN 512
#define MAX_PATH_LEN 255

if (pipe(pipe1) == -1)//call pipe command

           {

                perror("bad pipe1"); //display if fail to create pipe

                exit(1);

           }

           // fork command 1

           if ((pid = fork()) < -1)

           {

                perror("bad fork"); //display if fail to create children

                exit(1);

           }

           else if (pid == 0)

           {

                close(pipe1[0]); //close unused pipe

                dup2(pipe1[1], fileno(stdout) ); //instead of print out in file descriptor stdout, put the output in pipe

                close(pipe1[1]); //close when finish using

                //execute command 1

                exec(command[0]);

                exit(0);             

           }

           // parent

           else

           {

                do

                {

                      //wait until chidlren finish and terminate

                      wpid = waitpid(pid, &status, WUNTRACED);

                } while (!WIFEXITED(status) && !WIFSIGNALED(status));

                if ( WIFEXITED(status) )

                {

                      pid = fork();

                      if (pid < 0)

                      {

                           perror("bad fork"); //display if fail to fork

                           exit(1);

                      }

                      else if (pid == 0)

                      {

                           close(pipe1[1]); //close unsused pipe

                           dup2(pipe1[0], fileno(stdin) ); //read the output of the first command into pipe1, instead of stdin

                           close(pipe1[0]); //close when finish using

                           //execute command 2

                           exec(command[1]);

                           exit(0); //exit after done

                      }

                      else

                      {

                           close(pipe1[0]); //close unused pipe

                           close(pipe1[1]); //close unused pipe

                           //parent wait until the children terminate

                           do

                           {

                                 wpid = waitpid(pid, &status, WUNTRACED);

                           } while (!WIFEXITED(status) && !WIFSIGNALED(status));

                      }

                }

               

           }
