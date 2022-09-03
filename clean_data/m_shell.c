#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<readline/readline.h>
#include<readline/history.h>
#include <sys/types.h>
#include<constant.h>
#include<m_shell_struct.h>
#include <sys/wait.h>
#include<regex.h>
#include<unistd.h>
#include<wait.h>

extern char **VAR;
int VAR = 0;
int VAR = 0;
int VAR = 0;
int_cmd_node VAR[10]; 


#define DEV

int handle_logical_command(char *VAR, regex_t *VAR, regex_t *VAR);
/*Handle control is the main entry point and shell will always check for it */
int spawn_child(char *VAR, char **VAR, int VAR, int VAR, int VAR); 
internal_command type_a(char * VAR); 
int handle_internal_command(char *VAR, internal_command meta_data, char **VAR); 
void clean_command(char *VAR); 
int handle_command_pipes(char *VAR, regex_t *VAR);
int handle_command_generic(char *VAR, int VAR, int VAR, int VAR);
void create_pipe(int **VAR, int VAR);
char **custom_command_completion(const char *VAR, int VAR, int VAR); 
void set_args(char *VAR, char **VAR); 
int perform_io_redirection(int *VAR , int *VAR, char **VAR);
void slide(char **VAR); 
void rotate(char **VAR, int VAR); 
int parse_variables(char *VAR); 
void rotate_command(char *VAR, int VAR);
void slide_command(char *VAR);
void make_space(char *VAR, int VAR, char *VAR);
int set_variable(char *VAR); 
void init_history(void);
void re_add_history(char *VAR);
void init_shell(void);
int exit_m(char **VAR);
int history(char **VAR);
int parse_history(char *VAR);

int main(int VAR, char **VAR)
{
read_history(".history");
init_shell();

regex_t VAR;
regex_t VAR;
regcomp(&VAR, "(.+)(&&|[|][|])(.+)", REG_EXTENDED);
regcomp(&VAR, "(.+)[|](.+)", REG_EXTENDED);
int VAR = 0; 
char prompt[PATH_MAX];
rl_attempted_completion_function = custom_command_completion;

while(1)
{
char *VAR = (char *)malloc(MAX_CMD_LEN  * sizeof(char));
#ifndef DEV
sprintf(prompt, "\VAR(%s@%s)-[%s]-$ ", getenv("LOGNAME"), getenv("NAME"), strcmp(getenv("HOME"), getenv("HOME"))?"~":getenv("PWD"));
prompt[VAR] = '\0';
#endif
#ifdef DEV
int VAR = sprintf(prompt,"\VAR(%s@%s)-$ ", getenv("LOGNAME"), getenv("NAME"));
prompt[VAR] = '\0';
#endif
VAR = readline(prompt);
add_history(VAR);
clean_command(VAR);
parse_history(VAR);
char *VAR = VAR;
char *VAR = strsep(&VAR, ";");
while(VAR != NULL)
{

VAR = handle_logical_command(VAR, &VAR, &VAR); 
if(VAR)
{
VAR = 0;
VAR = strsep(&VAR, ";");
continue;
}
VAR = handle_command_pipes(VAR, &VAR);
VAR = strsep(&VAR, ";");
}
free(VAR);
}
return 0;
}

int handle_logical_command(char *VAR, regex_t *VAR, regex_t *VAR)
{
regmatch_t VAR[CONTROL_COMMAND_GROUP];
int VAR = regexec(VAR, VAR, CONTROL_COMMAND_GROUP, VAR, 0);

if(VAR) 
{
return 0;
}
VAR = 1;


char left[VAR[1].rm_eo - VAR[1].rm_so + 1];
char VAR[3];
char right[VAR[3].rm_eo - VAR[3].rm_so + 1];
memset(left, '\0', sizeof(left));
memset(right, '\0', sizeof(right));
memset(VAR, '\0', sizeof(VAR));
strncpy(left, VAR + VAR[1].rm_so, VAR[1].rm_eo - VAR[1].rm_so);
strncpy(VAR, VAR + VAR[2].rm_so, VAR[2].rm_eo - VAR[2].rm_so);
strncpy(right, VAR + VAR[3].rm_so, VAR[3].rm_eo - VAR[3].rm_so);

#ifdef DEV
printf("\nLEFT:%s OP:%s RIGHT:%s\VAR", left, VAR, right);
#endif


int VAR = 0;
if(strcmp(VAR, "&&") == 0) VAR = 1;
else VAR = 2;

int VAR = regexec(VAR, left, CONTROL_COMMAND_GROUP, VAR, 0); 
int VAR = handle_logical_command(left, VAR, VAR);
if(VAR != 0)
{
switch(VAR)
{
case 1:
{
int VAR = 0;
int VAR = handle_command_pipes(left, VAR);
if(WIFEXITED(VAR) && VAR >> 8 == 0) 
{
VAR = handle_command_pipes(right, VAR);
if(WIFEXITED(VAR))
return 1;
else return 0;
}
else return 0;
}
break;
case 2:
int VAR = handle_command_pipes(left, VAR);
int VAR = handle_command_pipes(right, VAR);
return WIFEXITED(VAR) || WIFEXITED(VAR);
break;
default:
printf("\nwe are broken somewhat!\VAR");
exit(SABNORMAL); 
break;
}
}
else 
{
switch (VAR)
{
case 1:
if(VAR == 1)
{
int VAR = handle_command_pipes(right, VAR);
if(WIFEXITED(VAR))
return 1;
else return 0;
}
else return 0;
break;
case 2:
int VAR = handle_command_pipes(right, VAR);
return VAR && WIFEXITED(VAR);
break;
default:
printf("\nTHERE WAS A PROBLEM IN RECURSION\VAR");
exit(SABNORMAL);
break;

}
}
}

int spawn_child(char *VAR, char **VAR, int VAR, int VAR, int VAR)
{

int VAR = fork();
if(VAR == 0)
{
int VAR = perform_io_redirection(&VAR, &VAR, VAR);
if(VAR == FILE_NOT_FOUND)
{
printf("VAR not found\VAR");
raise(2);
}
if(VAR != - 1) dup2(VAR, 0);
if(VAR != - 1) dup2(VAR, 1);

int VAR = execvp(VAR, VAR);
if(VAR != 0)
{
printf("No such VAR found: %s\VAR", VAR);
raise(2);
}
}
else
{
if(VAR)
{
int VAR = 0;
wait(&VAR);
return VAR;
}
return -1;
}
}

void clean_command(char *VAR) 
{
char VAR[MAX_CMD_LEN];
int VAR = 0;
int VAR;
memset(VAR, '\0', MAX_CMD_LEN);
strncpy(VAR, VAR, MAX_CMD_LEN);
memset(VAR, '\0', strlen(VAR));
char VAR = VAR[0];

for(int VAR = 0; VAR[VAR] != '\0'; VAR++)
{
if(VAR[VAR] == '-')
VAR = 1;
else if(VAR[VAR] == ' ')
VAR = 0;
if(VAR[VAR] >= ' ' && VAR[VAR] <= '~')
{
if((VAR[VAR] == '>' || VAR[VAR] == '<') && VAR[VAR + 1] != ' ')
{
VAR[VAR++] = VAR[VAR];
VAR[VAR++] = ' ';
VAR = ' ';
continue;
}
else if(VAR == ' ' && VAR[VAR] == ' ') continue;
else if((VAR == '|' || VAR == '&') && VAR[VAR] == ' ') continue;
else if(VAR[VAR] == ' ' && (VAR[VAR + 1] == '|' || VAR[VAR + 1] == '&' || VAR[VAR + 1] == '\0' || VAR[VAR + 1] == '\VAR')) continue;
else if((VAR[VAR] >= '0' && VAR[VAR] <= '9') && (VAR == 0) && (VAR[VAR + 1] != ' ') && (VAR[VAR + 1] == '>' || VAR[VAR + 1] == '<'))
{
VAR[VAR++] = VAR[VAR];
VAR[VAR++] = ' ';
VAR = ' ';
continue;
}
VAR[VAR++] = VAR[VAR];
VAR = VAR[VAR];
}
}
}

int handle_command_pipes(char *VAR, regex_t *VAR)
{
regmatch_t VAR[PIPE_CMD_GROUP];
int VAR = 0; 
int **VAR;
char *VAR = NULL;
int VAR;
int VAR = 0;
int VAR = regexec(VAR, VAR, PIPE_CMD_GROUP, VAR, 0);
if(VAR)
{
return handle_command_generic(VAR, 1, -1, -1); 
}

for(int VAR = 0; VAR[VAR] != '\0'; VAR++)
{
if(VAR[VAR] == '|')
VAR++;
}

VAR = (int **) malloc(VAR * sizeof(int *));
for(int VAR = 0; VAR < VAR; VAR++)
{
VAR[VAR] = (int *) malloc(sizeof(int) * 2);
}


create_pipe(VAR, 0);
strtok(VAR, "|");
VAR =  handle_command_generic(VAR, 0, -1, VAR[0][1]);

for(int VAR = 1; VAR < VAR; VAR++)
{
VAR = strtok(NULL, "|");
create_pipe(VAR, VAR);
VAR = handle_command_generic(VAR, 0, VAR[VAR - 1][0], VAR[VAR][1]);
}
VAR = strtok(NULL, "|");
VAR = handle_command_generic(VAR, 1, VAR[VAR - 1][0], -1);
for(int VAR = 0; VAR < VAR + 1; VAR++)
{
wait(NULL);
}

for(int VAR = 0; VAR < VAR; VAR++)
{
free(VAR[VAR]);
}
free(VAR);



return VAR;
}

int handle_command_generic(char *VAR, int VAR, int VAR, int VAR)
{
int VAR = parse_variables(VAR);
if(VAR == VARIABLE_NOT_FOUND)
{
printf("variable not found");
return EXIT_FAILURE;
}
char *VAR[ARG_NUM];
VAR[0] = VAR;
VAR[1] = NULL;
int VAR = set_variable(VAR);
if(VAR != -99)
return VAR;
set_args(VAR, VAR);
internal_command VAR = type_a(VAR[0]);
if(VAR.is_true)
{
return VAR.fun(VAR);
}
int VAR = spawn_child(VAR[0], VAR, VAR, VAR, VAR);
if(VAR != -1) close(VAR);
if(VAR != -1) close(VAR);
return VAR;
}

void create_pipe(int **VAR, int VAR)
{
int VAR = pipe(VAR[VAR]);
if(VAR == 1)
{
perror("pipe");
exit(EXIT_FAILURE);
}
}

char **custom_command_completion(const char *VAR, int VAR, int VAR)
{
if(VAR)
{
char VAR[PATH_MAX];
VAR = 0;
VAR[VAR];
char VAR[50];
sprintf(VAR, "/usr/bin/%s", VAR);

getcwd(VAR, PATH_MAX);
chdir("/usr/bin");
char **VAR  = rl_completion_matches(VAR, rl_filename_completion_function);
chdir(VAR);
return VAR;
}
VAR = 1;
return rl_completion_matches(VAR, rl_filename_completion_function);
}

void set_args(char *VAR, char **VAR)
{
int VAR = 0;
int VAR = strlen(VAR);
for(int VAR = 0; VAR <= VAR; VAR++)
{
if(VAR[VAR] == ' ')
{
VAR++;
}

}
if(VAR == 0)
{
return;

}
else
{
int VAR = 0;
char *VAR;
VAR = strsep(&VAR, " ");
while(VAR != NULL)
{
VAR[VAR] = VAR;
VAR = strsep(&VAR, " ");
VAR++;
}
VAR[VAR] = NULL;



}

return ;
}

int perform_io_redirection(int *VAR, int *VAR, char *VAR[])
{
for(int VAR = 0; VAR[VAR] != NULL; VAR++)
{
if(VAR[VAR][0] == '<')
{
VAR[VAR][0] = '^';
int VAR = access(VAR[VAR + 1], F_OK | R_OK);
if(VAR == 0)
*VAR = open(VAR[VAR + 1], O_RDONLY);
else
{
return FILE_NOT_FOUND;
}
VAR[VAR + 1]  = "^";
if(VAR[VAR -1][0] >= '0' && VAR[VAR - 1][0] <= '9')
VAR[VAR - 1][0] = '^';
slide(VAR);
VAR = VAR - 3;
}
else if(VAR[VAR][0] == '>')
{
VAR[VAR][0] = '^';
int VAR = access(VAR[VAR + 1], F_OK | W_OK);
if(VAR == 0)
*VAR = open(VAR[VAR + 1], O_WRONLY);
else
{
return FILE_NOT_FOUND;
}
VAR[VAR + 1]  = "^";
if(VAR[VAR -1][0] >= '0' && VAR[VAR - 1][0] <= '9')
VAR[VAR - 1][0] = '^';
slide(VAR);
VAR = VAR - 3;
}
}
return 1;
}

void rotate(char **VAR, int VAR)
{
int VAR = VAR;
while(VAR[VAR] != NULL)
{
VAR[VAR] = VAR[VAR + 1];
VAR++;
}
}

void slide(char **VAR)
{
int VAR;
for(VAR = 0; VAR[VAR] != NULL; VAR++)
{
if(VAR[VAR][0] == '^')
{
rotate(VAR, VAR);
VAR--;
}
}
}

void rotate_command(char *VAR, int VAR)
{
int VAR = VAR;
while(VAR[VAR] != '\0')
{
VAR[VAR] = VAR[VAR + 1];
VAR++;
}
}

void slide_command(char *VAR)
{
int VAR;
for(VAR = 0; VAR[VAR] != '\0'; VAR++)
{
if(VAR[VAR] == '^')
{
rotate_command(VAR, VAR);
VAR--;
}
}
}

void make_space(char *VAR, int VAR, char *VAR)
{
int VAR = strlen(VAR);
for(int VAR = VAR + 1; &VAR[VAR] >= VAR; VAR--)
{
VAR[VAR + VAR] = VAR[VAR];
}
}

int parse_variables(char *VAR)
{
while(1)
{
char hold[VARIABLE_LEN];
memset(hold, '\0', VARIABLE_LEN);
char *VAR = strstr(VAR, "$");
if(VAR == NULL)
break;
for(int VAR = 0; VAR[VAR] != ' ' && VAR[VAR] != '\0'; VAR++)
{
hold[VAR] = VAR[VAR];
VAR[VAR] = '^';
}
slide_command(VAR);
printf("%s\VAR", hold);
char *VAR = getenv(hold + 1);
if(VAR == NULL)
return VARIABLE_NOT_FOUND;
make_space(VAR, strlen(VAR), VAR);

for(int VAR = 0; VAR < strlen(VAR); VAR++)
{
VAR[VAR] = VAR[VAR];
}
}
}

int set_variable(char *VAR)
{
regex_t VAR;
regcomp(&VAR, "(.+)=(.+)", REG_EXTENDED);
regmatch_t VAR[3];
int VAR = regexec(&VAR, VAR, 3, VAR, 0);
if(VAR) 
{
return -99;
}
else if(VAR[0].rm_eo - VAR[0].rm_so != strlen(VAR))
{
return -99;
}
printf("Variable Set\VAR");
char *VAR = strsep(&VAR, "=");
return setenv(VAR, VAR, 1);
}

void re_add_history(char *VAR)
{
FILE *m_shell_hist = fopen(".history", "a+");
fprintf(m_shell_hist, "%s\VAR", VAR);
fclose(m_shell_hist);
}

void init_history(void)
{
FILE *m_shell_hist = fopen(".history", "r");
char VAR[MAX_CMD_LEN];
memset(VAR, '\0', MAX_CMD_LEN);
while(fgets(VAR, MAX_CMD_LEN, m_shell_hist))
{
add_history(VAR);
memset(VAR, '\0', MAX_CMD_LEN);
}
fclose(m_shell_hist);
}

int exit_m(char **VAR)
{
write_history(".history");
exit(0);
}

int change_dir(char **VAR)
{
return chdir(VAR[1]);
}

void init_shell(void)
{
signal(SIGINT, SIG_IGN);
VAR[0].file_name = "exit";
VAR[0].fun = exit_m;
VAR[1].file_name = "cd";
VAR[1].fun = change_dir;
VAR[2].file_name = "history";
VAR[2].fun = history;
VAR[3].file_name = NULL;
}

internal_command type_a(char * VAR)
{
internal_command VAR;
VAR.is_true = 0;
VAR.fun = NULL;
int VAR = 0;
while(VAR[VAR].file_name != NULL)
{
if(strcmp(VAR, VAR[VAR].file_name) == 0)
{
VAR.is_true = 1;
VAR.fun = VAR[VAR].fun;
return VAR;
}
VAR++;
}
return VAR;
}

int history(char **VAR)
{
HIST_ENTRY **hist = history_list();
for(int VAR = 1; hist[VAR] != NULL; VAR++)
{
printf("%d %s\VAR", VAR, hist[VAR]->line);
}
}

int parse_history(char *VAR)
{
if(VAR[0] != '!')
return 0;
HIST_ENTRY **en = history_list();
int VAR = atoi(VAR + 1);
sprintf(VAR, "%s", en[VAR]->line);
}
