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
printf("I am Server Waiting for connection...\n");
int VAR = sizeof(VAR);
VAR = accept(VAR, (struct VAR*)&VAR, &VAR);
printf("Got connection from the client..\n");

int VAR = 0;
char VAR[1024];
char *VAR = "";
while(VAR = read(VAR, VAR, sizeof(VAR)))
{
write(VAR, "ACK\n", 5);
}
close(VAR);
}
close(VAR);
return 0;
}
