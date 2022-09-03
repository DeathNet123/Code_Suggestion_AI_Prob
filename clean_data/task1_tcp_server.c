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

void search(char **VAR, char *VAR, int VAR)
{
for(int VAR = 0; VAR[VAR] != NULL; VAR++)
{
if(strstr(VAR[VAR], VAR) != NULL)
{
int VAR = strlen(strstr(VAR[VAR], ",") + 1);
write(VAR, strstr(VAR[VAR], ",") + 1, VAR);
return;
}
}
write(VAR, "RECORD NOT FOUND\n", 18);
}
int main(int VAR, char **VAR)
{
char *VAR[6];
VAR[0] = "BCSF19M556,Arslan Ahmed Qureshi\n";
VAR[1] = "BCSF19M534,Rana Faran Abdullah\n";
VAR[2] = "BCSF19M513,Ali Raza mumtaz\n";
VAR[3] = "BCSF19M526,Sarmad Khalique\n";
VAR[4] = "BCSF19M550,Hadeed Butt\n";
VAR[5] = NULL;

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

while(VAR = read(VAR, VAR, sizeof(VAR)))
{
VAR[VAR - 1] = '\0';
if(VAR < 10)
{
write(VAR, "WRONG FORMAT\n", 14);
continue;
}

search(VAR, VAR, VAR);
}
close(VAR);
}
close(VAR);
return 0;
}
