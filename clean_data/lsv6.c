#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <VAR.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <VAR.h>
#include <VAR.h>
#include <time.h>
#include <string.h>

#define LINELEN 512

extern int VAR;

void listDir(char*);
void displayLongListed(char*,char*);
void uidToUser(int);
void gidToGroup(int);
void getTime(long);
void getFileType(int VAR);
void getPermissions(int);

int main(int VAR, char* VAR[]) {
if (VAR==1) {
printf("Directory listing of present directory:\VAR");
listDir(".");
} else if(VAR>=2){
for(int VAR=1; VAR<VAR; VAR++) {
printf("Directory listing of %s:\VAR", VAR[VAR]);
listDir(VAR[VAR]);
printf("\VAR");
}
}
return 0;
}

void listDir(char* VAR) {
struct dirent **VAR;
int VAR = scandir(VAR, &VAR, NULL, alphasort);
for(int VAR=0; VAR<VAR; VAR++) {
if(VAR[VAR]->d_name[0] != '.') {

displayLongListed(VAR, VAR[VAR]->d_name);
printf("\VAR");
}
}
}
void displayLongListed(char* VAR, char* VAR) {
char buffer[LINELEN];
snprintf(buffer, LINELEN, "%s/%s", VAR, VAR);
struct stat VAR;
int VAR = lstat(buffer, &VAR);
if (VAR == -1){
perror("stat failed");
exit(1);
}
getFileType(VAR.st_mode);
getPermissions(VAR.st_mode);
printf("%ld ", VAR.st_nlink);
uidToUser(VAR.st_uid);
gidToGroup(VAR.st_gid);
printf("%ld\t", VAR.st_size);
getTime(VAR.st_mtime);
if ((VAR.st_mode & 0170000) == 0010000) printf("%s\t", VAR);
else if ((VAR.st_mode & 0170000) == 0020000) printf("\033[7m%s\033[m\t", VAR);
else if ((VAR.st_mode & 0170000) == 0040000) printf("\e[0;34m %s \033[0m\t", VAR);
else if ((VAR.st_mode & 0170000) == 0060000) printf("\033[7m%s033[m\t", VAR);
else if ((VAR.st_mode & 0170000) == 0120000) printf("\033[35;6m%s \033[0m\t", VAR);
else if ((VAR.st_mode & 0170000) == 0140000) printf("%s\t", VAR);
else if ((VAR.st_mode & 0170000) == 0100000 && !strcmp(VAR,"a.out")) printf("\e[0;32m%s\033[0m\t", VAR);
else if ((VAR.st_mode & 0170000) == 0100000 ) printf("%s\t", VAR);
}
void uidToUser(int VAR){
struct passwd* VAR = getpwuid(VAR);
printf("%s ",VAR->pw_name);
}
void gidToGroup(int VAR){
struct group* VAR = getgrgid(VAR);
printf("%s ",VAR->gr_name);
}
void getTime(long VAR){
char *VAR = ctime(&VAR);
printf("  %-14.12s", VAR + 4);
}
void getPermissions(int VAR) {
char VAR[10];
strcpy(VAR, "---------");

if((VAR & 0000400) == 0000400) VAR[0] = 'r';
if((VAR & 0000200) == 0000200) VAR[1] = 'w';
if((VAR & 0000100) == 0000100) VAR[2] = 'x';

if((VAR & 0000040) == 0000040) VAR[3] = 'r';
if((VAR & 0000020) == 0000020) VAR[4] = 'w';
if((VAR & 0000010) == 0000010) VAR[5] = 'x';

if((VAR & 0000004) == 0000004) VAR[6] = 'r';
if((VAR & 0000002) == 0000002) VAR[7] = 'w';
if((VAR & 0000001) == 0000001) VAR[8] = 'x';

if((VAR & 0004000) == 0004000) VAR[2] = 's';
if((VAR & 0002000) == 0002000) VAR[5] = 's';
if((VAR & 0001000) == 0001000) VAR[8] = 't';
printf("%s ", VAR);
}
void getFileType(int VAR){
if ((VAR &  0170000) == 0010000) {

printf("p");
}
else if ((VAR &  0170000) == 0020000) {
printf("c");
}
else if ((VAR &  0170000) == 0040000) {
printf("d");
}
else if ((VAR &  0170000) == 0060000) {
printf("b");
}
else if ((VAR &  0170000) == 0100000) {
printf("-");
}
else if ((VAR &  0170000) == 0120000) {
printf("l");
}
else if ((VAR &  0170000) == 0140000) {
printf("s");
}
}
