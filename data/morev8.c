// Version 8 and 9 || Search String and Vim Edit a File 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	PAGELEN	= 20;
int	LINELEN	= 512;
char filename[500];

void do_more(FILE *); // Reach from command line argument file
int  get_input(FILE*); //File* as we want it to read from file we open dev/tty as io redirection changes stdin to file
int count_lines(char*);
void search(FILE* );

int total_lines;
int lines_done;

int main(int argc , char *argv[])
{
   int i=0;
   // Rows and Columns using environ variables using getenv which return char*
   PAGELEN = atoi(getenv("LINES"))-1;
   LINELEN = atoi(getenv("COLUMNS"));
   if (argc == 1){
      do_more(stdin); // IO rdirection if no argument then read from file 
   }
   FILE * fp;
   while(++i < argc){
      
      total_lines = count_lines(argv[i]); // count total lines for printing percentage calculation later
      fp = fopen(argv[i] , "r");
      if (fp == NULL){
         perror("Can't open file");
         exit (1);
      }
      strcpy(filename, argv[i]); // copy filename for using later in vim command call
      do_more(fp);
      fclose(fp);
   }  
   return 0;
}

void do_more(FILE *fp)
{
   int num_of_lines = 0;
   lines_done = 0;
   int rv;
   char buffer[LINELEN];
   FILE* fp_tty = fopen("/dev//tty", "r"); // terminal associated file to read from during IO redirection
   while (fgets(buffer, LINELEN, fp)){
      fputs(buffer, stdout);
      num_of_lines++;
      lines_done++;

      if (num_of_lines == PAGELEN){
         rv = get_input(fp_tty);		
         if (rv == 0){//user pressed q
            printf("\n");
            printf("\033[1A \033[2K \033[1G"); // erase one line above and move to start column
            exit(0);
         }
         else if (rv == 1){//user pressed space bar
            printf("\n"); //this line will add the newline when space bar is pressed so that line 59 can erase the --MORE--
            printf("\033[1A \033[2K \033[1G");
            num_of_lines -= PAGELEN;
         }
         else if (rv == 2){//user pressed return/enter
            printf("\033[1A \033[2K \033[1G");
	         num_of_lines -= 1; //show one more line
            }
         else if (rv == 4){ //Search character
            printf("\033[2K \033[1G");
            search(fp); // search character update file pointer or else show message
            num_of_lines = 1;
            continue;
         }
         else if (rv == 3){ //invalid character
            printf("\033[1A \033[2K \033[1G");
            break; 
         }
         else if (rv == 5){ // For VIM 
            printf("\033[1A \033[2K \033[1G");
            char cmd[LINELEN];
            strcpy(cmd, "vim ");
            strcat(cmd, filename);
            printf("%s", cmd);
            system(cmd);
            printf("\033[1B \033[2K \033[1G");
            printf("\033[1B \033[2K \033[1G");
            num_of_lines = 1;
         }
      }
  }
}

int get_input(FILE* cmdstream)
{
   int c;
   int percentage = ((float)lines_done/total_lines)*100;		
   printf("\033[7m --more--(%d %%) \033[m", percentage);
      system("stty -icanon"); // non canonical mode to ignore enters and some other keys
      c = getc(cmdstream);
      system("stty icanon");
      if(c == 'q')
	    return 0;
      if ( c == ' ' )			
	    return 1;
      if ( c == '\n' )	
	    return 2;
      if ( c == '/' )	
	    return 4;
      if ( c == 'v' )	
	    return 5;
      return 3;
   return 0;
}

// Count lines for percentage in reverse video and reset pointer
int count_lines(char filename[]){
   int total_lines = 0;
   FILE *fp = fopen(filename,"r");
   char buffer[LINELEN];
   while ( fgets(buffer, LINELEN, fp)){
      total_lines++;
   }
   fclose(fp);
   return total_lines;
}

void search(FILE* fp){
    system("stty icanon");
    printf("/");
    int temp;
    int flag = 1;
    int checkpoint = ftell(fp);
    char substr[LINELEN];
    fgets(substr, LINELEN, stdin);
    char buffer[LINELEN];
    int prev_lines = lines_done;
    while(fgets(buffer, LINELEN, fp)){
      lines_done++;
      if(strstr(buffer, substr) != NULL){
        printf("\033[1A \033[2K \033[1G"); 
        printf("Skipping.... \n");
        fputs(buffer, stdout);
        flag = 0;
        printf("\033[1A \033[2K \033[1G");
        fseek(fp, temp, SEEK_SET);
        return;
      }
      temp = ftell(fp);
    }
    if(flag){
        printf("\033[7m Pattern Not Found \033[m");
        printf("\n");
        lines_done = prev_lines;
        fseek(fp, checkpoint, SEEK_SET);
        return;
    }
}
