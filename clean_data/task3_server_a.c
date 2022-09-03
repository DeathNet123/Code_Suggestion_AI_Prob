#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<linux/limits.h>
#include<netdb.h>

int main(int VAR, char **VAR)
{

int VAR = socket(AF_INET, SOCK_STREAM, 0);
int VAR;

struct sockaddr_in VAR;
struct sockaddr_in VAR;


VAR.sin_family = AF_INET;
inet_aton("0.0.0.0", &VAR.sin_addr);
VAR.sin_port = htons(54154);
memset(&VAR.sin_zero, '\0', sizeof(VAR.sin_zero));


bind(VAR, (struct VAR*)&VAR, sizeof(VAR)); 
listen(VAR, 10); 


while(1)
{
char filename[PATH_MAX]; 
printf("I am Server Waiting for connection...\n");
int VAR = sizeof(VAR);
VAR = accept(VAR, (struct VAR*)&VAR, &VAR);
printf("Got connection from the client..\n");
int VAR = read(VAR, filename, PATH_MAX); 
filename[VAR - 1] = '\0';
int VAR = open(filename, O_RDONLY);
if(VAR == -1)
{
write(VAR, "Failed to open file\n", 21);
write(1, "Failed to open file\n", 21);
close(VAR);
continue;
}
int VAR = 0;
char VAR[1024];
while(VAR = read(VAR, VAR, sizeof(VAR)))
{
write(VAR, VAR, VAR);
}
close(VAR);
}
close(VAR);
return 0;
}
