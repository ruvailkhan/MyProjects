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
char PS1[150];
char PATH[256];
char currentDir[MAX_PATH_LEN];
char * progName;
typedef enum {
PARSE,
EXIT,
CD,
ECHO,
CMD,
PWD
}
CMDTYPE;

void init() {
strcpy(PS1, "[batchFile] ");

if (getcwd(currentDir, MAX_PATH_LEN) == NULL)

{

perror("getcwd");
exit(1);
}
strcpy(PATH, "/bin");
}
void showPrompt()
{
printf("%s:%s", currentDir, PS1);
}
void parseCmdline(const char * cmdline, char * cmd, char ** * cmd_argv, int * cmd_argc)
{
int i = 0;
int temp_argc = 0;
int start_index;
char ** temp_argv = NULL;
while (cmdline[i] != ' ' && cmdline[i] != '\0' && i < CMD_LEN)
{
cmd[i] = cmdline[i];
i++;
}
if (i == CMD_LEN)
{
fprintf(stderr, "Cmd_buffer_overflow.\n");
exit(1);
}
cmd[i] = '\0';
temp_argv = malloc(sizeof(char * ));
temp_argv[temp_argc] = (char * ) malloc((strlen(cmd) + 1) * sizeof(char));
strcpy(temp_argv[temp_argc], cmd);
temp_argc++;
while (cmdline[i] != '\0')
{
while (cmdline[i] == ' ')
i++;
start_index = i;
while (cmdline[i] != ' ' && cmdline[i] != '\0')
i++;
if (temp_argv == NULL)
temp_argv = malloc(sizeof(char * ));
else
temp_argv = realloc(temp_argv, (temp_argc + 1) * sizeof(char * ));
temp_argv[temp_argc] = (char * ) malloc((i - start_index + 1) * sizeof(char));
strncpy(temp_argv[temp_argc], cmdline + start_index, (i - start_index));
temp_argv[temp_argc][i - start_index] = '\0';
temp_argc++;
}
temp_argv = realloc(temp_argv, (temp_argc + 1) * sizeof(char * ));
temp_argv[temp_argc] = NULL;
( * cmd_argv) = temp_argv;
( * cmd_argc) = temp_argc;
return;
}
void freeCmdArgs(char ** * cmd_argv, int * cmd_argc)
{
int i;
for (i = 0; i < ( * cmd_argc); i++)
free(( * cmd_argv)[i]);
if (( * cmd_argc) != 0)
free(( * cmd_argv));
( * cmd_argc) = 0;
}

CMDTYPE getCmdType(const char * cmd)
{
if (strcmp(cmd, "exit") == 0) return EXIT;
return CMD;
}
int main(int argc, char ** argv, char ** envp)
{
char cmdline[CMDLINE_LEN];
char cmd[CMD_LEN];
char ** cmd_argv = NULL;
int cmd_argc;
int i;
int closeShell = FALSE;
char tempPath[MAX_PATH_LEN];
progName = argv[0];
init();
while (closeShell != TRUE)
{
showPrompt();
gets(cmdline);
parseCmdline(cmdline, cmd, & cmd_argv, & cmd_argc);
#ifdef DEBU
for (i = 0; i < cmd_argc; i++)
printf("argv[%d] = %s\n", i, cmd_argv[i]);
#endif
if (getCmdType(cmd) == EXIT) {
closeShell = TRUE;
}
freeCmdArgs( & cmd_argv, & cmd_argc);
}
return 0;
}
