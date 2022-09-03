#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<VAR.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>

extern int VAR;
int main(int VAR, char **VAR)
{

int VAR = socket(AF_INET, SOCK_DGRAM, 0);


struct sockaddr_in VAR;
VAR.sin_family = AF_INET;
inet_aton("0.0.0.0", &VAR.sin_addr);
VAR.sin_port = htons(54154);
memset(&VAR.sin_zero, '\0', sizeof(VAR.sin_zero));

while(1)
{
int VAR = 0;
char VAR[1024];
char VAR[1024];
memset(VAR, '\0', sizeof(VAR));
memset(VAR, '\0', sizeof(VAR));
VAR = read(0, VAR, sizeof(VAR)); 
sendto(VAR, VAR, VAR, 0, (struct VAR*)&VAR, sizeof(VAR)); 
int VAR = sizeof(VAR);
VAR = recvfrom(VAR, VAR, sizeof(VAR), 0, (struct VAR*)&VAR, &VAR);
write(1, VAR, VAR);
}
close(VAR);
return 0;
}
