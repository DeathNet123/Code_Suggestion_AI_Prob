#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <grp.h>
#include <pwd.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>

extern int errno;
static bool flag = false;
static struct dirent **namelist;
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
void print_info(char *, struct stat);
int sorting(char *);
void color(char *, char);
void do_recursive(char *);
void deallocate(char **, int);

int main(int argc, char *argv[])
{
  ROWS = atoi(getenv("LINES"));
  COLUMNS = atoi(getenv("COLUMNS"));
  if (argc == 1)
  {
    int rv = sorting(".");
    do_ls(".", namelist, rv);
    exit(0);
  }
  else if (strcmp(argv[1], "-l") == 0)
  {
    flag = true;
    if (argc == 2)
    {
      int rv = sorting(".");
      do_ls(".", namelist, rv);
    }
    else
    {
      int i = 1;
      loop_through_args(argc, argv, i);
    }
    flag = false;
  }
  else if (strcmp(argv[1], "-R") == 0)
  {
    if (argc == 2)
    {
      int i = -10;
      do_recursive(".");
    }
    else
    {
      int i = 1;
      loop_through_args_rec(argc, argv, i);
    }
  }
  else if (strcmp(argv[1], "-l") != 0)
  {
    flag = false;
    int i = 0;
    loop_through_args(argc, argv, i);
  }
  return 0;
}

void do_ls(char *dirname, struct dirent **dir, int count_entries)
{
  for (int i = 0; i < count_entries; i++)
  {
    if (dir == NULL)
    {
      fprintf(stderr, "Cannot open directory:%s\n", dir[i]->d_name);
      return;
    }
    if (dir[i]->d_name[0] == '.')
    {
      continue;
    }
    if (flag)
    {
      do_complex_ls(dirname, dir[i]->d_name);
    }
    color(dir[i]->d_name, dir[i]->d_type);
    if (flag)
    {
      if (dir[i]->d_type == DT_LNK)
      {
        char buffer[100], link[100];
        snprintf(buffer, 100, "%s/%s", dirname, dir[i]->d_name);
        int count = readlink(buffer, link, sizeof(link));
        link[count] = '\0';
        printf(" -> %s", link);
      }
    }
    printf("\n");
  }
}

void do_complex_ls(char *dirname, char *dname)
{
  char buffer[100];
  snprintf(buffer, 100, "%s/%s", dirname, dname);
  struct stat buf;
  int rv = lstat(buffer, &buf);
  if (rv == -1)
  {
    perror("stat failed");
    exit(1);
  }
  else
  {
    char str[10];
    strcpy(str, "---------");
    fileType(buf.st_mode);
    ownerPermissions(buf.st_mode, str);
    groupPermissions(buf.st_mode, str);
    othersPermissions(buf.st_mode, str);
    specialPermissions(buf.st_mode, str);
    print_info(str, buf);
  }
}

void fileType(int mode)
{
  if ((mode & 0170000) == 0010000)
  {
    printf("p");
  }
  else if ((mode & 0170000) == 0020000)
  {
    printf("c");
  }
  else if ((mode & 0170000) == 0040000)
  {
    printf("d");
  }
  else if ((mode & 0170000) == 0060000)
  {
    printf("b");
  }
  else if ((mode & 0170000) == 0100000)
  {
    printf("-");
  }
  else if ((mode & 0170000) == 0120000)
  {
    printf("l");
  }
  else if ((mode & 0170000) == 0140000)
  {
    printf("s");
  }
  else
  {
    printf("Unknwon mode\n");
  }
}

void ownerPermissions(int mode, char *str)
{
  if ((mode & 0000400) == 0000400)
  {
    str[0] = 'r';
  }
  if ((mode & 0000200) == 0000200)
  {
    str[1] = 'w';
  }
  if ((mode & 0000100) == 0000100)
  {
    str[2] = 'x';
  }
}

void groupPermissions(int mode, char *str)
{
  if ((mode & 0000040) == 0000040)
  {
    str[3] = 'r';
  }
  if ((mode & 0000020) == 0000020)
  {
    str[4] = 'w';
  }
  if ((mode & 0000010) == 0000010)
  {
    str[5] = 'x';
  }
}

void othersPermissions(int mode, char *str)
{
  if ((mode & 0000004) == 0000004)
  {
    str[6] = 'r';
  }
  if ((mode & 0000002) == 0000002)
  {
    str[7] = 'w';
  }
  if ((mode & 0000001) == 0000001)
  {
    str[8] = 'x';
  }
}

void specialPermissions(int mode, char *str)
{
  if ((mode & 0004000) == 0004000)
  {
    str[2] = 's';
  }
  if ((mode & 0002000) == 0002000)
  {
    str[5] = 's';
  }
  if ((mode & 0001000) == 0001000)
  {
    str[8] = 't';
  }
}

void loop_through_args(int argc, char *argv[], int i)
{
  while (++i < argc)
  {
    printf("Printing Directory Listing of %s : \n", argv[i]);
    int rv = sorting(argv[i]);
    do_ls(argv[i], namelist, rv);
  }
}

void loop_through_args_rec(int argc, char *argv[], int i)
{
  while (++i < argc)
  {
    printf("Printing Directory Listing of %s : \n", argv[i]);
    do_recursive(argv[i]);
  }
}

void print_info(char *str, struct stat buf)
{
  int uid = buf.st_uid;
  int gid = buf.st_gid;
  struct passwd *u = getpwuid(uid);
  struct group *g = getgrgid(gid);
  printf("%-10s", str);
  printf("%3.1d\t", buf.st_nlink);
  printf("%-1.20s  ", u->pw_name);
  printf("%-1.20s", g->gr_name);
  printf("%8d", buf.st_size);
  long t = buf.st_mtime;
  char *ch = ctime(&t);
  printf("  %-12.12s  ", ch + 4);
}

int sorting(char *dirname)
{
  int count_entries = scandir(dirname, &namelist, NULL, alphasort);
  return count_entries;
}

void color(char *ch, char filetype)
{
  if (filetype == DT_BLK)
  {
    printf("%-1.20s", ch);
  }
  else if (filetype == DT_CHR)
  {
    printf("%-1.20s", ch);
  }
  else if (filetype == DT_DIR)
  {
    printf("\033[44m%-1.20s\033[40m", ch);
  }
  else if (filetype == DT_FIFO)
  {
    printf("%-1.20s", ch);
  }
  else if (filetype == DT_LNK)
  {
    printf("%-1.20s", ch);
  }
  else if (filetype == DT_REG)
  {
    printf("%-1.20s", ch);
  }
  else if (filetype == DT_SOCK)
  {
    printf("%-1.20s", ch);
  }
}

void do_recursive(char *dirname)
{
  struct dirent **list;
  int dir_count = scandir(dirname, &list, NULL, alphasort);
  if (dir_count <= 0)
  {
    return;
  }
  int count_non_empty = 0;
  char **dir = (char **)malloc(dir_count * sizeof(char *));
  for (int i = 0; i < dir_count; i++)
  {
    dir[i] = (char *)malloc(100 * sizeof(char));
  }
  do_ls(dirname, list, dir_count);
  for (int i = 0; i < dir_count; i++)
  {
    if (list[i]->d_name[0] == '.')
    {
      continue;
    }
    if (list[i]->d_type == DT_DIR)
    {
      snprintf(dir[count_non_empty++], 100, "%s/%s", dirname, list[i]->d_name);
    }
  }
  for (int i = 0; i < count_non_empty; i++)
  {
    do_recursive(dir[i]);
  }
  deallocate(dir, dir_count);
}

void deallocate(char **direc, int count)
{
  for (int i = 0; i < count; i++)
  {
    free(direc[i]);
  }
  free(direc);
}