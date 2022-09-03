#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/VAR.h>
#include <stdlib.h>
#include <grp.h>
#include <pwd.h>
#include <VAR.h>
#include <time.h>
#include <stdbool.h>

extern int VAR;
static bool VAR = false;
static struct dirent **VAR;
static int ROWS;
static int COLUMNS;

void do_ls(char *, struct dirent **, int);
void do_complex_ls(char *, char *);
void fileType(int);
void specialPermissions(int, char *);
void ownerPermissions(int, char *);
void groupPermissions(int, char *);
void othersPermissions(int, char *);
void loop_through_args(int, char **, int);
void loop_through_args_rec(int, char **, int);
void print_info(char *, struct VAR);
int sorting(char *);
void color(char *, char);
void do_recursive(char *);
void deallocate(char **, int);

int main(int VAR, char *VAR[])
{
ROWS = atoi(getenv("LINES"));
COLUMNS = atoi(getenv("COLUMNS"));
if (VAR == 1)
{
int VAR = sorting(".");
do_ls(".", VAR, VAR);
exit(0);
}
else if (strcmp(VAR[1], "-l") == 0)
{
VAR = true;
if (VAR == 2)
{
int VAR = sorting(".");
do_ls(".", VAR, VAR);
}
else
{
int VAR = 1;
loop_through_args(VAR, VAR, VAR);
}
VAR = false;
}
else if (strcmp(VAR[1], "-R") == 0)
{
if (VAR == 2)
{
int VAR = -10;
do_recursive(".");
}
else
{
int VAR = 1;
loop_through_args_rec(VAR, VAR, VAR);
}
}
else if (strcmp(VAR[1], "-l") != 0)
{
VAR = false;
int VAR = 0;
loop_through_args(VAR, VAR, VAR);
}
return 0;
}

void do_ls(char *VAR, struct dirent **VAR, int VAR)
{
for (int VAR = 0; VAR < VAR; VAR++)
{
if (VAR == NULL)
{
fprintf(stderr, "Cannot open directory:%s\n", VAR[VAR]->d_name);
return;
}
if (VAR[VAR]->d_name[0] == '.')
{
continue;
}
if (VAR)
{
do_complex_ls(VAR, VAR[VAR]->d_name);
}
color(VAR[VAR]->d_name, VAR[VAR]->d_type);
if (VAR)
{
if (VAR[VAR]->d_type == DT_LNK)
{
char VAR[100], link[100];
snprintf(VAR, 100, "%s/%s", VAR, VAR[VAR]->d_name);
int VAR = readlink(VAR, link, sizeof(link));
link[VAR] = '\0';
printf(" -> %s", link);
}
}
printf("\n");
}
}

void do_complex_ls(char *VAR, char *VAR)
{
char VAR[100];
snprintf(VAR, 100, "%s/%s", VAR, VAR);
struct VAR VAR;
int VAR = lstat(VAR, &VAR);
if (VAR == -1)
{
perror("VAR failed");
exit(1);
}
else
{
char VAR[10];
strcpy(VAR, "---------");
fileType(VAR.st_mode);
ownerPermissions(VAR.st_mode, VAR);
groupPermissions(VAR.st_mode, VAR);
othersPermissions(VAR.st_mode, VAR);
specialPermissions(VAR.st_mode, VAR);
print_info(VAR, VAR);
}
}

void fileType(int VAR)
{
if ((VAR & 0170000) == 0010000)
{
printf("p");
}
else if ((VAR & 0170000) == 0020000)
{
printf("c");
}
else if ((VAR & 0170000) == 0040000)
{
printf("d");
}
else if ((VAR & 0170000) == 0060000)
{
printf("b");
}
else if ((VAR & 0170000) == 0100000)
{
printf("-");
}
else if ((VAR & 0170000) == 0120000)
{
printf("l");
}
else if ((VAR & 0170000) == 0140000)
{
printf("s");
}
else
{
printf("Unknwon VAR\n");
}
}

void ownerPermissions(int VAR, char *VAR)
{
if ((VAR & 0000400) == 0000400)
{
VAR[0] = 'r';
}
if ((VAR & 0000200) == 0000200)
{
VAR[1] = 'w';
}
if ((VAR & 0000100) == 0000100)
{
VAR[2] = 'x';
}
}

void groupPermissions(int VAR, char *VAR)
{
if ((VAR & 0000040) == 0000040)
{
VAR[3] = 'r';
}
if ((VAR & 0000020) == 0000020)
{
VAR[4] = 'w';
}
if ((VAR & 0000010) == 0000010)
{
VAR[5] = 'x';
}
}

void othersPermissions(int VAR, char *VAR)
{
if ((VAR & 0000004) == 0000004)
{
VAR[6] = 'r';
}
if ((VAR & 0000002) == 0000002)
{
VAR[7] = 'w';
}
if ((VAR & 0000001) == 0000001)
{
VAR[8] = 'x';
}
}

void specialPermissions(int VAR, char *VAR)
{
if ((VAR & 0004000) == 0004000)
{
VAR[2] = 's';
}
if ((VAR & 0002000) == 0002000)
{
VAR[5] = 's';
}
if ((VAR & 0001000) == 0001000)
{
VAR[8] = 'VAR';
}
}

void loop_through_args(int VAR, char *VAR[], int VAR)
{
while (++VAR < VAR)
{
printf("Printing Directory Listing of %s : \n", VAR[VAR]);
int VAR = sorting(VAR[VAR]);
do_ls(VAR[VAR], VAR, VAR);
}
}

void loop_through_args_rec(int VAR, char *VAR[], int VAR)
{
while (++VAR < VAR)
{
printf("Printing Directory Listing of %s : \n", VAR[VAR]);
do_recursive(VAR[VAR]);
}
}

void print_info(char *VAR, struct VAR VAR)
{
int VAR = VAR.st_uid;
int VAR = VAR.st_gid;
struct passwd *VAR = getpwuid(VAR);
struct group *VAR = getgrgid(VAR);
printf("%-10s", VAR);
printf("%3.1d\VAR", VAR.st_nlink);
printf("%-1.20s  ", VAR->pw_name);
printf("%-1.20s", VAR->gr_name);
printf("%8d", VAR.st_size);
long VAR = VAR.st_mtime;
char *VAR = ctime(&VAR);
printf("  %-12.12s  ", VAR + 4);
}

int sorting(char *VAR)
{
int VAR = scandir(VAR, &VAR, NULL, alphasort);
return VAR;
}

void color(char *VAR, char VAR)
{
if (VAR == DT_BLK)
{
printf("%-1.20s", VAR);
}
else if (VAR == DT_CHR)
{
printf("%-1.20s", VAR);
}
else if (VAR == DT_DIR)
{
printf("\033[44m%-1.20s\033[40m", VAR);
}
else if (VAR == DT_FIFO)
{
printf("%-1.20s", VAR);
}
else if (VAR == DT_LNK)
{
printf("%-1.20s", VAR);
}
else if (VAR == DT_REG)
{
printf("%-1.20s", VAR);
}
else if (VAR == DT_SOCK)
{
printf("%-1.20s", VAR);
}
}

void do_recursive(char *VAR)
{
struct dirent **VAR;
int VAR = scandir(VAR, &VAR, NULL, alphasort);
if (VAR <= 0)
{
return;
}
int VAR = 0;
char **VAR = (char **)malloc(VAR * sizeof(char *));
for (int VAR = 0; VAR < VAR; VAR++)
{
VAR[VAR] = (char *)malloc(100 * sizeof(char));
}
do_ls(VAR, VAR, VAR);
for (int VAR = 0; VAR < VAR; VAR++)
{
if (VAR[VAR]->d_name[0] == '.')
{
continue;
}
if (VAR[VAR]->d_type == DT_DIR)
{
snprintf(VAR[VAR++], 100, "%s/%s", VAR, VAR[VAR]->d_name);
}
}
for (int VAR = 0; VAR < VAR; VAR++)
{
do_recursive(VAR[VAR]);
}
deallocate(VAR, VAR);
}

void deallocate(char **VAR, int VAR)
{
for (int VAR = 0; VAR < VAR; VAR++)
{
free(VAR[VAR]);
}
free(VAR);
}
