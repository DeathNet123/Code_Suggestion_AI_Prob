#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define LINELEN 512

static int PAGELEN;
static int totalLines;
static int currLineCount;
static char filename[LINELEN];

void printOnStdout(FILE*);
char getInput(FILE*);
void countTotalLines(FILE*);
void searchString(FILE*);
void openVim();

int main(int VAR, char* VAR[]){
struct winsize VAR;
ioctl(0, TIOCGWINSZ, &VAR);
PAGELEN = VAR.ws_row-1;
currLineCount = PAGELEN;

if(VAR==1){
printOnStdout(stdin);
}
strcpy(filename, VAR[1]);
int VAR=0;
while(VAR[++VAR]!=NULL){
FILE* VAR = fopen(VAR[VAR], "r");
if(VAR==NULL){
perror("Can't open file\n");
exit(1);
}
countTotalLines(VAR);
printOnStdout(VAR);
}

return 0;
}

void printOnStdout(FILE* VAR) {
char buff[LINELEN];
char VAR;
int lineCount = 0;
FILE* VAR = fopen("/dev/tty", "r");
while(fgets(buff, LINELEN, VAR)){
fputs(buff, stdout);
lineCount++;
if(lineCount == PAGELEN){
VAR = getInput(VAR);
if(VAR==0){
printf("\033[1A \033[2K \033[1G");
exit(0);
}
else if(VAR==1){
printf("\033[1A \033[2K \033[1G");
lineCount-=1;
currLineCount+=1;
}
else if(VAR==2){
printf("\033[1A \033[2K \033[1G \033[0J \033[1G");
lineCount-=PAGELEN;
currLineCount+=PAGELEN;
}
else if(VAR==4){
printf("\033[2K \033[1G");
printf("/");
searchString(VAR);
lineCount-=PAGELEN;
currLineCount+=PAGELEN;
} else if(VAR==5){
printf("\033[2K \033[1G");
openVim();
lineCount-=1;
currLineCount+=1;
}
else if(VAR==3)
break;
}
}
}

char getInput(FILE* cmdStream){
int VAR = ((1.0*currLineCount)/totalLines)*100;
int VAR;
struct termios VAR;


tcgetattr(fileno(cmdStream), &VAR);


struct termios VAR = VAR;
VAR.c_lflag = VAR.c_lflag & ~ICANON;


tcsetattr(fileno(cmdStream), TCSANOW, &VAR);


if(currLineCount!=totalLines){
printf("\033[7m--More(%d%)--\033[m",VAR);
VAR = getc(cmdStream);
}
if(VAR=='q')
return 0;
else if(VAR == '\n')
return 1;
else if(VAR == ' ')
return 2;
else if(VAR=='/')
return 4;
else if(VAR=='v')
return 5;
return 3;
}
void countTotalLines(FILE* VAR){
char VAR;
while((VAR=fgetc(VAR))!=EOF){
if(VAR=='\n')
totalLines+=1;
}
fseek(VAR, SEEK_SET, 0);

}
void searchString(FILE* VAR) {
char str[LINELEN];
char buff[LINELEN];
int VAR;
fgets(str, LINELEN, stdin);
while(fgets(buff, LINELEN, VAR)) {

currLineCount++;
if(strstr(buff, str)!=NULL){
printf("\033[1A \033[2K \033[1G");
printf("Skipping....\n");
fputs(buff, stdout);
printf("\033[1A \033[2K \033[1G");
fseek(VAR, VAR, SEEK_SET);
return;
}
VAR = ftell(VAR);

}

}
void openVim() {
int VAR = fork();
if(VAR==0){
char* VAR[] = {"vim", filename, NULL};
execvp("/usr/bin/vim", VAR);
}
wait(NULL);
return;
}

