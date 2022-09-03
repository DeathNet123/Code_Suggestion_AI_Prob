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

int VAR = socket(AF_INET, SOCK_STREAM, 0);


struct sockaddr_in VAR;
VAR.sin_family = AF_INET;
inet_aton("0.0.0.0", &VAR.sin_addr);
VAR.sin_port = htons(54154);
memset(&VAR.sin_zero, '\0', sizeof(VAR.sin_zero));


int VAR = connect(VAR, (struct VAR*)&VAR, sizeof(VAR));
if(VAR == -1)
{
perror("connect");
exit(VAR);
}
FILE *file = fopen(VAR[1], "r");

char *VAR = NULL;
size_t VAR = 0;
char VAR[6];
int VAR = 0;
while(VAR = getline(&VAR, &VAR, file) != -1)
{   
write(VAR, VAR, VAR);
read(VAR, VAR, sizeof(VAR));
write(1, VAR, sizeof(VAR));
}
fclose(file);
free(VAR);
close(VAR);
return 0;
}
