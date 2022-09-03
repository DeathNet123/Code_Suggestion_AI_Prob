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

void search(char **VAR, char *VAR, struct VAR *VAR, int VAR, int VAR)
{
printf("%s", VAR);
for(int VAR = 0; VAR[VAR] != NULL; VAR++)
{
if(strstr(VAR[VAR], VAR) != NULL)
{
printf("I was here!\n");
int VAR = strlen(strstr(VAR[VAR], ",") + 1);
sendto(VAR, strstr(VAR[VAR], ",") + 1, VAR, 0, VAR, VAR);
return;
}
}
sendto(VAR, "RECORD NOT FOUND\n", 18, 0, VAR, VAR);
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

int VAR = socket(AF_INET, SOCK_DGRAM, 0);
struct sockaddr_in VAR;


VAR.sin_family = AF_INET;
inet_aton("0.0.0.0", &VAR.sin_addr);
VAR.sin_port = htons(54154);
memset(&VAR.sin_zero, '\0', sizeof(VAR.sin_zero));


bind(VAR, (struct VAR*)&VAR, sizeof(VAR)); 
while(1)
{
printf("I am Server Waiting for The roll no...\n");
char VAR[1024];
int VAR = sizeof VAR;
memset(VAR, '\0', sizeof(VAR));
int VAR = recvfrom(VAR, VAR, sizeof(VAR), 0, (struct VAR*)&VAR, &VAR); 
VAR[VAR - 1] = '\0';
if(VAR < 10)
{
sendto(VAR, "WRONG FORMAT\n", 14, 0, (struct VAR*)&VAR, VAR);
continue;
}
search(VAR, VAR, (struct VAR*)&VAR, VAR, VAR);
}
close(VAR);
return 0;
}
