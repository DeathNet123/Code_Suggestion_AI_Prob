#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <ctype.h>

#define MAXLEN 512
#define MAXARGS 10
#define ARGLEN 30

static int semicolonsize = 0;
static int status;

bool isBuiltin(char**);
char* readCmd();
char** tokenize(char*);
void executeBuiltin(char**);
void execute(char**, char*);
bool executeMultiple(char**, char*);
void openHelp();
void changeDir(char*);
void IORedirect(char**);
bool parsePipes(char**, char*);
void executePiped(char**);
bool parseBackground(char**, char*);
void reapResources(int);
bool setVariable(char*);
bool getVariable(char*);

int main() {
    char* cmdline;
    char** arglist;
    char** semicolonlist = (char**)malloc(sizeof(char*) * (MAXARGS + 1));

    for (int i = 0; i < MAXARGS + 1; i++) {
        semicolonlist[i] = (char*)malloc(sizeof(char*) * ARGLEN);
        bzero(semicolonlist[i], ARGLEN);
    }

    while ((cmdline = readCmd()) != NULL) {
        bool isVariable = setVariable(cmdline);
        if (executeMultiple(semicolonlist, cmdline)) {
            for (int i = 0; i < semicolonsize; i++) {
                arglist = tokenize(semicolonlist[i]);
                if(isBuiltin(arglist)) {
                    executeBuiltin(arglist);
                } else {
                    execute(arglist, cmdline);
                }
            }
        } else if ((arglist = tokenize(cmdline)) != NULL) {
            if(isBuiltin(arglist)) {
                executeBuiltin(arglist);
            } else {
                execute(arglist, cmdline);
            }
        }
    }
    printf("\n");
    return 0;
}

bool isBuiltin(char** arglist) {
    if(strcmp(arglist[0], "cd") == 0 || strcmp(arglist[0], "help") == 0 || strcmp(arglist[0], "exit") == 0)
        return true;
    return false;
}

char* readCmd() {
    char* cmdline = (char*)malloc(sizeof(char) * MAXLEN);

    cmdline = readline("myshell$ ");

    if(strlen(cmdline)!=0) {
        add_history(cmdline);
    }

    return cmdline;
}

char** tokenize(char* cmdline) {
    char** arglist = (char**)malloc(sizeof(char*) * (MAXARGS + 1));
    for (int i = 0; i < MAXARGS; i++) {
        arglist[i] = (char*)malloc(sizeof(char*) * ARGLEN);
        bzero(arglist[i], ARGLEN);
    }

    if(cmdline[0] == '\0')
      return NULL;

    char* pos = cmdline;
    char* start;
    int len;
    int argnum = 0;

    while (*pos != '\0') {
        while (*pos == ' ' || *pos == '\t')
            pos++;
        start = pos;
        len = 1;
        while (*++pos != '\0' && !(*pos == ' ' || *pos == '\t'))
            len++;
        char* end = start + strlen(start) - 1;
        while(end > start && isspace((unsigned char)*end)) end--;

        // Write new null terminator character
        end[1] = '\0';

        strncpy(arglist[argnum], start, len);
        arglist[argnum][len] = '\0';
        argnum += 1;
    }
    arglist[argnum] = NULL;
    return arglist;
}

void executeBuiltin(char** arglist) {
    if (strcmp(arglist[0], "cd") == 0) {
        changeDir(arglist[1]);
    } else if (strcmp(arglist[0], "help") == 0) {
        openHelp();
    } else if (strcmp(arglist[0], "exit") == 0) {
        exit(0);
    }
}

void execute(char** arglist, char* cmdline) {

    char* pipeList[MAXARGS];
    char* backList[MAXARGS];

    if(parseBackground(backList, cmdline)) {

        char** parsedBack = tokenize(backList[0]);
        pid_t pid;

        pid = fork();

        switch(pid) {
            case -1: {
                printf("ERROR: Fork Failed!!\n");
                exit(1);
            }
            case 0: {
                execvp(parsedBack[0], parsedBack);
                exit(1);
            }
            default: {
                printf("\n");
            }
        }

    } else if(parsePipes(pipeList, cmdline)) {
        executePiped(pipeList);
    } else {
        int pid = fork();
        int status;
        switch (pid)
        {
        case 0: {
            IORedirect(arglist);
            execvp(arglist[0], arglist);
            printf("\n");
            exit(1);
            break;
        }
        case -1:
            perror("Fork Failed");
            exit(1);
            break;
        default:
            waitpid(pid, &status, 0);
            printf("return status is %d\n\n", status >> 8);
            break;
        }
    }
}

void openHelp() {
    printf("This is help page for my own LINUX GNU shell.\n"
        "You can execute all the external commands on this shell\n"
        "along with several internal commands like cd, exit, help.\n"
        "You can also execute multiple commands using ; at the end of the command.\n"
        "You can also redirect IO and can use pipe between commands.\n"
        "You can also run a process in the background using & sign at the end of command.\n\n"
    );
}

void changeDir(char* dir) {
    int n = chdir(dir);
    if (n == -1) {
        printf("No such Directory!!\n\n");
    }
}

bool executeMultiple(char** semicolonlist, char* cmdline) {
    int index;
    for (int i = 0; i < MAXLEN; i++) {
        semicolonlist[i] = strsep(&cmdline, ";");
        if (semicolonlist[i] == NULL) {
            semicolonsize = i;
            index = i;
            break;
        }
    }
    if (semicolonlist[1] == NULL) {
        return false;
    } else {
        semicolonsize = index;
        return true;
    }
}

void IORedirect(char** arglist) {
    int fd_out, fd_in;
    for (int i = 0; i < MAXARGS; i++) {
        if (arglist[i] != NULL) {
            if (strcmp(arglist[i], ">") == 0) {
                fd_out = open(arglist[i + 1], O_RDWR | O_CREAT | O_TRUNC, 0666);
                dup2(fd_out, 1);
                arglist[i] = NULL;
                arglist[i + 1] = NULL;
            } else if (strcmp(arglist[i], "<") == 0) {
                fd_in = open(arglist[i + 1], O_RDONLY);
                dup2(fd_in, 0);
                arglist[i] = NULL;
                arglist[i + 1] = NULL;
            }
        }
    }
}

bool parsePipes(char** pipeList, char* cmdline) {
    for (int i = 0; i < 2; i++) {
        pipeList[i] = strsep(&cmdline, "|");
        if (pipeList[i] == NULL) {
            break;
        }
    }
    if (pipeList[1] == NULL) {
        return false;
    } else {
        return true;
    }
}

void executePiped(char** pipeList) {
    char** parsed = tokenize(pipeList[0]);
    char** parsedPipe = tokenize(pipeList[1]);

    int pipe_fd[2];

    if(pipe(pipe_fd)<0) {
        printf("ERROR: Pipe cannot be initialized\n");
        fflush(stdout);
        return;
    }

    pid_t p1, p2;

    p1 = fork();

    if(p1==0) {
        close(pipe_fd[0]);
        dup2(pipe_fd[1], 1);
        close(pipe_fd[1]);
        execvp(parsed[0], parsed);
    } else {
        p2 = fork();
        if (p2 == 0) {
            close(pipe_fd[1]);
            dup2(pipe_fd[0], 0);
            close(pipe_fd[0]);
            execvp(parsedPipe[0], parsedPipe);
       }
       else {
            close(pipe_fd[0]);
            close(pipe_fd[1]);
            wait(NULL);
        }
    }
}

bool parseBackground(char** backList, char* cmdline) {
    signal(SIGCHLD, reapResources);
    for (int i = 0; i < MAXLEN; i++) {
        backList[i] = strsep(&cmdline, "&");
        if (backList[i] == NULL) {
            break;
        }
    }
    if (backList[1] == NULL) {
        return false;
    } else {
        return true;
    }
}

void reapResources(int sig) {
    waitpid(-1, &status, WNOHANG);
}

bool setVariable(char* cmdline){
    char* key;
    char* value;
    bool flag = true;

    bool savedVar = getVariable(cmdline);
    if(savedVar)
        return false;

    key = strsep(&cmdline, "=");
    value = strsep(&cmdline, "=");

    if (key == NULL || value == NULL) {
      flag = false;
    } else {
        char** args1 = tokenize(key);
        char** args2 = tokenize(value);
        setenv(args1[0], args2[0], 1);
    }

    return flag;
}

bool getVariable(char* cmdline){
    char *key;
    bool flag = false;

    char** varList = (char**)malloc(sizeof(char*) * (MAXARGS + 1));

    for (int i = 0; i < MAXLEN; i++) {
        varList[i] = strsep(&cmdline, "$");
        if (varList[i] == NULL) {
            break;
        }
    }

    key = varList[1];
    char* value = getenv(key);
    if(key != NULL && value != NULL) {
        printf("%s\n\n", value);
        flag = true;
    } 
    return flag;
}

