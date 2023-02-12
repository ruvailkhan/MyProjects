// Name : Ruvail Shahzad
// EUID :rs0737

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
   int ifp, ofp;

   if (argc == 4)
   {
       char *grep_args[] = {"grep", argv[1], NULL};
       ifp = open(argv[2], O_RDONLY);
       ofp = open(argv[3], O_WRONLY | O_TRUNC | O_CREAT, S_IRUSR | S_IRGRP | S_IWGRP | S_IWUSR);
          dup2(ifp,0);
          dup2(ofp,1);
          close(ifp);
          close(ofp);
       execvp("grep", grep_args);
   }
   else
   {
       printf("usage: %s text_pattern input_file output_file\n", argv[0]);
   }
}
