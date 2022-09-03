


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_LEN 512
#define MAXPIPES 20
#define MAXARGS 10
#define ARGLEN 30

int execute(char *VAR[]);
int tokenize(char *);
char *read_cmd();
int check_input_redirection_ret_index(char **);
int check_output_redirection_ret_index(char **);
bool is_external(char **);
void execute_cd(char *);
void execute_exit(void);
void execute_help(void);
void execute_jobs(void);
void handleInput(char *);
int checkPipe(char *);
int checksemicolon(char *);
int checkvariable(char *);
int checkBackground(char *);
void makePipes(void);
void printvariablelist(void);
int semicolon(char *);
int checkvariableprint(char *);
int checkHistory(char *);
void create_pipe(int **, int);
int execPipes(char *VAR[], int, int, int);
int closePipefd(char *VAR[], int, int, int);

int VAR;
int VAR;
int VAR;
int VAR;
int VAR;
int VAR;
int VAR = 0;
char *VAR[MAXARGS];
char *arglist1[MAXARGS];
char *Inputlist[MAXARGS];
char *Outputlist[MAXARGS];
char *pipeslist[MAXPIPES];
char *semicolonlist[MAX_LEN];
char *backgroundlist[MAXARGS];
bool Background = VAR;
char VAR[MAX_LEN];
int VAR = 0;

void childsignalhandler(int VAR)
{
waitpid(-1, NULL, WNOHANG);
}

int main()
{
int VAR = read_history_range("history.txt", 0, -1);
VAR = history_length;




if (VAR != 0)
{
printf("Unable to Import history");
fflush(stdout);
}
VAR = dup(1);
VAR = dup(0);
char *VAR;
while ((VAR = read_cmd()) != NULL)
{
int VAR = semicolon(VAR);
if (VAR == 0)
{
handleInput(VAR);
}
}
printf("\n");
return 0;
}

int semicolon(char *VAR)
{
int semicolonStatus = checksemicolon(VAR);
if (semicolonStatus)
{
for (int VAR = 0; VAR < VAR; VAR++)
{
handleInput(semicolonlist[VAR]);
}
}
return semicolonStatus;
}

void handleInput(char *VAR)
{
int VAR;
Background = VAR;
int historyStatus = checkHistory(VAR);
int backgroundStatus = checkBackground(VAR);
int variableStatus = checkvariable(VAR);
int variablePrintStatus = checkvariableprint(VAR);
int pipeStatus = checkPipe(VAR);
if (backgroundStatus)
{
Background = VAR;
int VAR = tokenize(VAR);
VAR[VAR - 1] = '\0';
execute(VAR);
}
else if (variableStatus)
{
return;
}
else if (variablePrintStatus)
{
char *key, *rand;
rand = strsep(&VAR, " ");
if ((key = strsep(&VAR, " ")) != NULL)
{
if (getenv(key) != NULL)
{
printf("value : %s\n", getenv(key));
fflush(stdout);
return;
}
}
printf("variable not found!!!\n");
fflush(stdout);
return;
}
else if (pipeStatus)
{
makePipes();
}
else if (historyStatus)
{
HIST_ENTRY **history = history_list();
for (int VAR = 0; VAR < history_length; VAR++)
{
printf("%s\n", history[VAR]->line);
fflush(stdout);
}
}
else
{
VAR = tokenize(VAR);
if (VAR == 0)
{
return;
}
bool VAR = is_external(VAR);
if (VAR)
{
if (VAR == 1)
{
execute(VAR);
}
else if (VAR == 2)
{
execute(Inputlist);
}
}
}
}

void makePipes()
{
int VAR = VAR - 1;
int pipefd[VAR][2];

pipe(pipefd[0]);
tokenize(pipeslist[0]);

closePipefd(VAR, 0, -1, pipefd[0][1]);
for (int VAR = 1; VAR < VAR; VAR++)
{
pipe(pipefd[VAR]);
tokenize(pipeslist[VAR]);

closePipefd(VAR, 0, pipefd[VAR - 1][0], pipefd[VAR][1]);
}

tokenize(pipeslist[VAR]);

closePipefd(VAR, 1, pipefd[VAR - 1][0], -1);





}

int closePipefd(char *VAR[], int VAR, int VAR, int VAR)
{
int VAR = execPipes(VAR, VAR, VAR, VAR);
if (VAR != -1)
{
close(VAR);
}
if (VAR != -1)
{
close(VAR);
}
return VAR;
}

int execPipes(char *VAR[], int VAR, int VAR, int VAR)
{
int VAR;
int VAR = fork();
switch (VAR)
{
case -1:
perror("fork failed");
exit(1);
case 0:
if (VAR != -1)
{
dup2(VAR, 0);
}
if (VAR != -1)
{
dup2(VAR, 1);
}
execvp(VAR[0], VAR);
perror("Command not found...");
exit(1);
default:
wait(NULL);
return 0;
}
}

int execute(char *VAR[])
{
int VAR;
int VAR = fork();
switch (VAR)
{
case -1:
perror("fork failed");
exit(1);
case 0:
execvp(VAR[0], VAR);
perror("Command not found...");
exit(1);
default:
if (Background)
{
signal(SIGCHLD, childsignalhandler);



}
else
{
waitpid(VAR, &VAR, 0);
dup2(VAR, 1);
dup2(VAR, 0);
printf("child exited with VAR %d \n", VAR >> 8);
}
return 0;
}
}

int checkPipe(char *VAR)
{
VAR = 0;
int VAR;
for (VAR = 0; VAR < MAX_LEN; VAR++)
{
pipeslist[VAR] = strsep(&VAR, "|");
if (pipeslist[VAR] == NULL)
{
break;
}
VAR++;
}
if (pipeslist[1] == NULL)
return 0;
else
{
return 1;
}
}

int checkHistory(char *VAR)
{
char *VAR;
VAR = strstr(VAR, "history");
if (VAR)
{
return 1;
}
else
{
return 0;
}
}

int checksemicolon(char *VAR)
{
int VAR;
for (VAR = 0; VAR < MAX_LEN; VAR++)
{
semicolonlist[VAR] = strsep(&VAR, ";");
if (semicolonlist[VAR] == NULL)
{
VAR = VAR;
break;
}
}
if (semicolonlist[0] == NULL)
return 0;
else
{
VAR = VAR;
return 1;
}
}

int checkvariable(char *VAR)
{
char *key, *value, *temp;
key = strsep(&VAR, "=");
value = strsep(&VAR, "=");
if (key == NULL || value == NULL)
{
return 0;
}
else
{
if ((temp = strsep(&key, " ")) != NULL)
{
setenv(temp, value, 1);
}
else
{
setenv(key, value, 1);
}
return 1;
}
}

int checkvariableprint(char *VAR)
{
char *VAR;
VAR = strstr(VAR, "print");
if (VAR)
{
return 1;
}
else
{
return 0;
}
}

int checkBackground(char *VAR)
{
char *VAR;
VAR = strchr(VAR, '&');
if (VAR != NULL)
{
return 1;
}
else
{
return 0;
}
}

int tokenize(char *VAR)
{
if (VAR[0] == '\0')
return 0;
int VAR;
for (VAR = 0; VAR < MAXARGS; VAR++)
{
VAR[VAR] = strsep(&VAR, " ");
if (VAR[VAR] == NULL)
{
break;
}
if (strlen(VAR[VAR]) == 0)
{
VAR--;
}
}
VAR = VAR;
int VAR = check_input_redirection_ret_index(VAR);
int VAR = check_output_redirection_ret_index(VAR);
if (VAR == -1 && VAR == -1)
{
return 1;
}
else if (VAR >= 0 && VAR >= 0)
{
if (VAR < VAR)
{
int VAR;
for (VAR = 0; VAR < VAR; VAR++)
{
Inputlist[VAR] = VAR[VAR];
}
VAR = VAR;
return 2;
}
else if (VAR < VAR)
{
int VAR;
for (VAR = 0; VAR < VAR; VAR++)
{
Inputlist[VAR] = VAR[VAR];
}
VAR = VAR;
return 2;
}
}
else if (VAR >= 0 && VAR == -1)
{ 
int VAR;
for (VAR = 0; VAR < VAR; VAR++)
{
Inputlist[VAR] = VAR[VAR];
}
VAR = VAR;
return 2;
}
else if (VAR >= 0 && VAR == -1)
{ 
int VAR;
for (VAR = 0; VAR < VAR; VAR++)
{
Inputlist[VAR] = VAR[VAR];
}
VAR = VAR;
return 2;
}
}

char *read_cmd()
{
char *VAR;
char VAR[256];
char VAR[] = "~ ";
getcwd(VAR, sizeof(VAR));
VAR = readline(strcat(VAR, VAR));
if (strlen(VAR) != 0)
{
add_history(VAR);
strcpy(VAR, VAR);
return VAR;
}
}

bool is_external(char **VAR)
{
if (strcmp(VAR[0], "cd") == 0)
{
execute_cd(VAR[1]);
}
else if (strcmp(VAR[0], "exit") == 0)
{
execute_exit();
}
else if (strcmp(VAR[0], "help") == 0)
{
execute_help();
}
else if (strcmp(VAR[0], "jobs") == 0)
{
execute_jobs();
}
else
{
return VAR;
}
return VAR;
}

void execute_cd(char *VAR)
{
int VAR;
if ((VAR = chdir(VAR) != 0))
{
perror("Directory not found...");
}
}

void execute_exit()
{
int VAR = history_length - VAR;
int VAR = append_history(VAR, "history.txt");




if (VAR != 0)
{
printf("Unable to save History!!!");
fflush(stdout);
}
exit(0);
}

void execute_help()
{
printf("This is help for my shell\n");
return;
}

void execute_jobs()
{
system("jobs");
return;
}

int check_input_redirection_ret_index(char **VAR)
{
int VAR;
for (int VAR = 0; VAR < VAR; VAR++)
{
if ((strcmp(VAR[VAR], "<") == 0))
{
VAR = open(VAR[VAR + 1], O_RDONLY);
dup2(VAR, 0);
return VAR;
}
}
return -1;
}

int check_output_redirection_ret_index(char **VAR)
{
int VAR;
for (int VAR = 0; VAR < VAR; VAR++)
{
if ((strcmp(VAR[VAR], ">") == 0))
{
VAR = open(VAR[VAR + 1], O_RDWR | O_CREAT);
dup2(VAR, 1);
return VAR;
}
}
return -1;
}
