#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include<errno.h>
#include<signal.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<time.h>
#include<wait.h>
#include<unistd.h>
#define MAXREQ 2048
#define MAXRES 2048

void reaper(int VAR)
{
waitpid(-1, NULL, 0);
}

void handle_body(char *VAR, int VAR)
{
struct stat VAR;
lstat(VAR, &VAR);
if(((VAR.st_mode & 0000100) != 0000100) && ((VAR.st_mode & 0170000) == 0100000))
{
int VAR = open(VAR, O_RDONLY);
char body[MAXREQ];
int VAR = 0;
while (VAR = read(VAR, body, MAXREQ ))
{
write(VAR, body, VAR);
}
close(VAR);
}
else if(((VAR.st_mode & 0000100) == 0000100) && ((VAR.st_mode & 0170000) == 0100000))
{
int VAR = fork();
if(VAR == 0)
{
dup2(VAR, 1);
execv(VAR, NULL);
}
else{
wait(NULL);
}

}
}

void handle_request(char *VAR, int VAR, int VAR)
{
time_t VAR;
time(&VAR);
char response[MAXRES];

char *VAR = strstr(VAR, "HTTP/");
strtok(VAR, "\r");
#ifdef DEBUG
char VAR[10];
int VAR = 0;
while ((VAR[VAR] >= 65 && VAR[VAR] <= 90) || VAR[VAR] == '/' || (VAR[VAR] >= 48 && VAR[VAR] <= 57) || VAR[VAR] == '.')
{
VAR[VAR] = VAR[VAR];
VAR++;
}
#endif


char *VAR = strstr(VAR, "GET");
strtok(VAR, " ");
char *VAR = strtok(NULL, " ");


size_t VAR = 25;
char hostname[VAR];
gethostname(hostname, VAR);

int VAR = access(VAR + 1, F_OK); 
if(VAR < 0)
{
int VAR = sprintf(response, "%s 404 NOT FOUND\nDate:%s\nServer:%s\n", VAR, strtok(ctime(&VAR), "\n"), hostname);
write(VAR, response, VAR);
}
else
{
int VAR = snprintf(response, MAXRES, "%s 200 OK\nDate:%s\nServer:%s\nContent-Type:text/html\n", VAR, strtok(ctime(&VAR), "\n"), hostname);
write(VAR, response, VAR); 
handle_body(VAR + 1, VAR);
}
return;

}

void add_logs(int VAR, char *VAR, int VAR, struct VAR VAR)
{
char log_entry[MAXREQ + 300];
time_t VAR;
time(&VAR);
int VAR = sprintf(log_entry, "%s:%s:%d\n%s", strtok(ctime(&VAR), "\n"), inet_ntoa(VAR.sin_addr), ntohs(VAR.sin_port), VAR);
write(VAR, log_entry, VAR);
}

int main(int VAR, char **VAR)
{
signal(SIGCHLD, reaper);
int VAR = socket(AF_INET, SOCK_STREAM, 0); 
int VAR; 
int VAR = open("log.txt", O_APPEND|O_RDWR); 

struct VAR VAR;
struct VAR VAR;

VAR.sin_family = AF_INET;
VAR.sin_port = htons(54154);
inet_aton(VAR[1], &VAR.sin_addr);
memset(&VAR.sin_zero, '\0', sizeof(VAR.sin_zero));
bind(VAR, (struct sockaddr *)&VAR, sizeof(VAR));
listen(VAR, 10);

while (1)
{
printf("Waiting for the Request...\n");
int VAR = sizeof(VAR);
VAR = accept(VAR, (struct sockaddr *)&VAR, &VAR);
printf("Request has been received..\n");
int VAR = fork();
if(VAR == 0)
{
close(VAR);
int VAR = 0;
char VAR[MAXREQ];
VAR = recv(VAR, VAR, MAXREQ, 0);
add_logs(VAR, VAR, VAR, VAR); 
handle_request(VAR, VAR, VAR);
close(VAR);
exit(0);
}
else
{
close(VAR);
continue;
}


}
close(VAR);
close(VAR);
return 0;
}
