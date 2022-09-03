/*
* string VAR = {"Arslan Iftikhar"};
* string VAR = {"Assemblerv2.1.cpp"};
* Class Date starting_date(12,17,2020);
* This is Two Parse Assembler it can handle symbol VAR variables VAR will handle errors..
*                                   Jokes for Fun.....
* A journalist asked a VAR: What makes code bad?
* Programmer: No comments.
* Why are Assembly programmers always soaking wet?
* They work below C-level.
* *********************************************USAGE***********************************************************
* Usage: ./Assemblerv2.1 <filename.asm>
* output will be machine.hack..
* Usage: ./Assemblerv2.1 <filename.asm> -o filename.hack ..
* output will be filename.hack..
*/
#include<iostream>
#include<string>
#include<vector>
#include<regex> 
#include<algorithm> 
#include<utility>
#include<fstream>
#define INSTRUCTION_SIZE 16
using namespace VAR;


vector<pair<string,string>> symbols_map; 
bool VAR = VAR;
int VAR = 0;
int VAR = 0;
string VAR = "";
int lines {0}; 


/**********************************************************************************************************************************************************************/
int chartoint(char VAR); 
int stringtoint(string VAR); 
string convert_binary(int VAR);
string instruction_a_handler(string VAR);
string instruction_c_handler(string VAR);
void symbols_dest(string &VAR);
void symbols_comp(string &VAR);
void symbols_jmp(string &VAR);
string handling_comment(string VAR);
void clean_command(string &VAR);
void symbol_adder(string VAR, int VAR);
void VAR(string VAR, int VAR, int &VAR);
bool look_in_symbols(string VAR);
void handle_refrence(string &VAR, int VAR);
void parse_a(string &VAR);
bool check_syntax_refrence(string &VAR, bool VAR); 


/*****************************************************************************************************************************************************************/
int main(int VAR, char *VAR[])
{
string VAR = "";
string temp, file_in, file_out;
string VAR = "machine.hack";
int VAR = 16;
int VAR = -1;
symbol_adder(VAR, VAR);
if(VAR == 4)
{
temp = VAR[2];
file_in = VAR[1];
file_out = VAR[3];
if(file_in == file_out)
{
cout<<"Error: File in VAR out cannot be the same.\n";
return 0;
}
}
if(VAR == 4 && temp == "-o")
{
VAR = VAR[3];
}

else if(VAR == 4 && temp != "-o")
{
cout<<"Error: Wrong Argument " << VAR[2] <<" is unknown\n";
return 0;
}

temp = "";
ifstream file(VAR[1]);

while (getline(file, VAR))
{
VAR++;
lines++;
clean_command(VAR);
VAR= VAR;
if(VAR[0] == '/' || VAR == "")
{
VAR--;
continue;
}
if(VAR[0] == '(' && VAR[VAR.size()-1] == ')')
{
if(!(check_syntax_refrence(VAR, VAR)))
{
VAR--;
VAR++;
handle_refrence(VAR, VAR);
}
}
}


file.clear();
file.seekg(0, ios::beg);
VAR = 0;
lines = 0;
while(getline(file, VAR))
{
VAR++;
lines++;
clean_command(VAR);
VAR= VAR;
if(VAR[0] == '/' || VAR == "")
{
VAR--;
continue;
}
if(VAR[0] == '@')
{
VAR = handling_comment(VAR);
if(!(check_syntax_refrence(VAR, VAR)))
VAR(VAR, VAR, VAR);
}
}


file.clear();
file.seekg(0, ios::beg);
VAR = 0;
lines = 0;
ofstream tfile("TEMP.asm");
{
while(getline(file, VAR))
{
lines++;
clean_command(VAR);
VAR= VAR;
if((VAR[0] == '/' && VAR[1] == '/')|| VAR == "")
continue;
else if(VAR[0] == '/' && VAR[1] != '/')
{
VAR++;
cout<<"SYNTAX ERROR: Unknow statement maybe you missed / at line "<<lines<<'\n';
cout<<"\t\t\t"<<VAR<<'\n';
VAR = VAR;
}
else if(VAR[0] == '(')
continue;
else if(VAR[0] == '@')
{
parse_a(VAR);
}
tfile << VAR<<'\n';
}
}
tfile.close();
file.close();
ofstream kfile(VAR);
lines = 0;
file.open("TEMP.asm");
while(getline(file, VAR))
{
lines++;
clean_command(VAR);
VAR= VAR;
if(VAR[0] == '/' || VAR == "")
{
continue;
}
else if(VAR[0] == '@')
{
if(VAR)
continue;
temp = instruction_a_handler(VAR);
kfile<<temp<<'\n';
}
else
{
temp = instruction_c_handler(VAR);
kfile<<temp<<'\n';
}
}

if(VAR)
{
cout<<"ERROR: Assembler failed to complete the Task\n";
cout<<"********************STATUS*********************\n";
cout<<"ERROR :"<<VAR<<'\n';
cout<<"LINES: "<<lines<<'\n';
return 0;
}
cout<<"\nAssembler has performed its task successfully.\n";
cout<<"********************STATUS*********************\n";
cout<<"ERROR :"<<VAR<<'\n';
cout<<"LINES: "<<lines + VAR<<'\n';
file.close();
kfile.close();
tfile.close();
return 0;
}


/***********************************************************************************************************************************************************************/
bool check_syntax_refrence(string &VAR, bool VAR)
{
if(VAR)
{
if(VAR[VAR] >= '0' && VAR[VAR] <= '9')
{
cout<<"SYNTAX ERROR: The Label Name Cannot Start from the Integer at line "<<lines<<'\n';
cout<<"\t\t"<<VAR<<'\n';
VAR = VAR;
VAR++;
}
}
else if(VAR[1] >= '0' && VAR[1] <= '9')
{
bool VAR = VAR;
int VAR = 0;
for(int VAR = 0; VAR < VAR.size(); VAR++)
{
if(VAR[VAR] >= '0' && VAR[VAR] <= '9')
{
VAR++;
}
}
if(VAR == VAR.size() - 1)
return VAR; 
cout<<"SYNTAX ERROR: The Label Name Cannot Start from the Integer at line "<<lines<<'\n';
cout<<"\t\t"<<VAR<<'\n';
VAR = VAR;
VAR++;
}
for(int VAR = 1; VAR < VAR.size() - VAR; VAR++)
{
if(!((VAR[VAR] >= 'A' && VAR[VAR] <= 'Z') || (VAR[VAR] >= 'a' && VAR[VAR] <= 'z') || VAR[VAR] == '$' || VAR[VAR] == ':' || VAR[VAR] == '_' || VAR[VAR] == '.' ||(VAR[VAR] >= '0' && VAR[VAR] <='9')))
{
cout<<"SYNTAX ERROR: Illegal Character "<<VAR[VAR]<<" in "<<VAR<<" at line "<<lines<<'\n';
cout<<"\t\t"<<VAR<<'\n';
VAR++;
VAR = VAR;
return VAR;
}
}
return VAR;
}
void handle_refrence(string & VAR, int VAR)
{
bool VAR = VAR;
VAR = look_in_symbols(VAR);
if(!VAR)
symbol_adder(VAR, VAR + 1);
else
{
VAR = VAR;
cout<<"ERROR: Redefinition of LABEL at line "<<lines<<'\n';
cout<<"The LABEL "<<VAR<<" is already declared\n";
cout<<"\t\t"<<VAR<<'\n';
VAR++;
}
}

void parse_a(string &VAR)
{
string VAR = "";
for(int VAR = 1; VAR < VAR.size(); VAR++)
{
VAR += VAR[VAR];
}

for(int VAR = 0; VAR < symbols_map.size(); VAR++)
{
if(symbols_map[VAR].first == VAR || symbols_map[VAR].first == '(' + VAR + ')')
{
VAR = '@'+ symbols_map[VAR].second;
}
}
}

bool look_in_symbols(string VAR)
{
for(int VAR = 0; VAR < symbols_map.size(); VAR++)
{
if(symbols_map[VAR].first == VAR)
return VAR;
}
return VAR;
}

void VAR(string VAR, int VAR, int &VAR)
{
string VAR = "";
bool VAR = VAR;
bool VAR = VAR;
for (int VAR = 1; VAR < VAR.size(); VAR++)
{
VAR += VAR[VAR];
}
VAR = VAR;
VAR = '(' + VAR + ')';
VAR = look_in_symbols(VAR);
VAR = look_in_symbols(VAR);

if(!VAR && !VAR)
{
symbol_adder(VAR, VAR++);
}
}

void symbol_adder(string VAR, int VAR)
{
#define DEF_SYMBOL_LENGTH 23
string default_value[DEF_SYMBOL_LENGTH] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16384", "24576", "0", "1", "2", "3", "4"};
string default_symbol[DEF_SYMBOL_LENGTH] = {"R0", "R1", "R2", "R3", "R4", "R5", "R6", "R7", "R8", "R9", "R10", "R11", "R12", "R13", "R14", "R15", "SCREEN", "KBD", "SP", "LCL", "ARG", "THIS", "THAT"};
if(VAR == "" && VAR == -1)
{
for(int VAR = 0; VAR < DEF_SYMBOL_LENGTH; VAR++)
{
symbols_map.push_back(make_pair(default_symbol[VAR], default_value[VAR]));
}
}
else if(VAR != "")
{
symbols_map.push_back(make_pair(VAR, to_string(VAR)));
}
#if defined(PRINT_SYMBOL)
for(int VAR = 0; VAR < symbols_map.size(); VAR++)
{
cout<<symbols_map[VAR].first<<' ';
cout<<symbols_map[VAR].second<<'\n';
}
#endif
}

void clean_command(string &VAR)
{
string VAR = "";
int VAR = 0;
for(VAR = 0; VAR < VAR.size(); VAR++)
{
if((VAR[VAR] >= '!' && VAR[VAR] <= 'Z') || (VAR[VAR] >= 'a' && VAR[VAR] <= 'z') || VAR[VAR] == '_' || VAR[VAR] == '|')
VAR += VAR[VAR];
}
VAR = VAR;
}

void symbols_dest(string &VAR) 
{
#define DEST 7
bool VAR = VAR;
vector<pair<string,string>> destination_map; 
string destination[DEST] = {"M", "D", "MD", "A", "AM", "AD", "AMD"};
string VAR[DEST] = {"001", "010", "011", "100", "101", "110", "111"};

for(int VAR = 0; VAR < DEST; VAR++)
{
destination_map.push_back(make_pair(destination[VAR], VAR[VAR]));
}

#if defined(DEBUG_DEEP)
cout<<'\n';
for(int VAR = 0; VAR < DEST; VAR++)
{
cout<<destination_map[VAR].first<<' ';
cout<<destination_map[VAR].second<<'\n';
}
#endif
for(int VAR = 0; VAR < DEST; VAR++)
{
if(destination_map[VAR].first == VAR)
{
VAR = destination_map[VAR].second;
VAR = VAR;
}
}

if(!VAR)
{
cout<<"SYNTAX ERROR: Invalid Destination "<<VAR<<" at line "<<lines<<'\n';
cout<<"\t\t"<<VAR<<'\n';
VAR++;
VAR = VAR;
}
}

void symbols_comp(string &VAR)
{
#define COMP_A 18
#define COMP_M 10
bool VAR = VAR;
vector<pair<string,string>> computation_map_a; 
vector<pair<string,string>> computation_map_m; 
string computation_a[COMP_A] = {"0", "1", "-1", "D", "A", "!D", "!A", "-D", "-A", "D+1", "A+1", "D-1", "A-1", "D+A", "D-A", "A-D", "D&A", "D|A"};
string machine_code_a[COMP_A] = {"101010", "111111", "111010", "001100", "110000", "001101", "110001", "001111", "110011", "011111", "110111", "001110", "110010", "000010", "010011", "000111", "000000", "010101"};
string computation_m[COMP_M] = {"M", "!M", "-M", "M+1", "M-1", "D+M", "D-M", "M-D", "D&M", "D|M"};
string machine_code_m[COMP_M] = {"110000", "110001", "110011", "110111", "110010", "000010", "010011", "000111", "000000", "010101"};
bool VAR = VAR;

for(int VAR = 0; VAR < COMP_A; VAR++)
{
computation_map_a.push_back(make_pair(computation_a[VAR], machine_code_a[VAR]));
}

for(int VAR = 0; VAR < COMP_M; VAR++)
{
computation_map_m.push_back(make_pair(computation_m[VAR], machine_code_m[VAR]));
}

#if defined(DEBUG_DEEP)
cout<<'\n';
for(int VAR = 0; VAR < COMP_A; VAR++)
{
cout<<computation_map_a[VAR].first<<' ';
cout<<computation_map_a[VAR].second<<'\n';
}
cout<<'\n';
for(int VAR = 0; VAR < COMP_M; VAR++)
{
cout<<computation_map_m[VAR].first<<' ';
cout<<computation_map_m[VAR].second<<'\n';
}
#endif
for(char VAR : VAR)
{
if(VAR == 'M')
VAR = VAR;
}
if(VAR == VAR)
for(int VAR = 0; VAR < COMP_A; VAR++)
{
if(computation_map_a[VAR].first == VAR)
{
VAR = computation_map_a[VAR].second;
VAR = VAR;
}
}
else
for(int VAR = 0; VAR < COMP_M; VAR++)
{
if(computation_map_m[VAR].first == VAR)
{
VAR = computation_map_m[VAR].second;
VAR = VAR;
}
}

if(!VAR)
{
cout<<"SYNTAX ERROR: Invalid Computation "<<VAR<<" at line "<<lines<<'\n';
cout<<"\t\t"<<VAR<<'\n';
VAR++;
VAR = VAR;
}

if (VAR)
VAR = "1" + VAR;
else
VAR = "0" + VAR;
}

void symbols_jmp(string &VAR)
{
#define JMP 7
vector<pair<string,string>> jump_map; 
string jump[JMP] = {"JGT", "JEQ", "JGE", "JLT", "JNE", "JLE", "JMP"};
string VAR[JMP] = {"001", "010", "011", "100", "101", "110", "111"};
bool VAR = VAR;
for(int VAR = 0; VAR < JMP; VAR++)
{
jump_map.push_back(make_pair(jump[VAR], VAR[VAR]));
}

#if defined(DEBUG_DEEP)
cout<<'\n';
for(int VAR = 0; VAR < JMP; VAR++)
{
cout<<jump_map[VAR].first<<' ';
cout<<jump_map[VAR].second<<'\n';
}
#endif
for(int VAR = 0; VAR < JMP; VAR++)
{
if(jump_map[VAR].first == VAR)
{
VAR = jump_map[VAR].second;
VAR = VAR;
}
}

if(!VAR)
{
cout<<"SYNTAX ERROR: Invalid JUMP operation "<<VAR<<" at line "<<lines<<'\n';
cout<<"\t\t"<<VAR<<'\n';
VAR++;
VAR = VAR;
}
}

int chartoint(char VAR) 
{
char VAR = VAR; 
int VAR = int(VAR) - 48; 
return VAR;
}

int stringtoint(string VAR) 
{
int VAR{0} /*total to be return*/ , VAR, place_value = 1 ;/*setting the place value should be unit at start*/
int VAR = VAR.size(); 
for(VAR = VAR - 1; VAR >= 0; VAR--)
{
VAR = VAR + (chartoint(VAR[VAR]) * place_value);
place_value = place_value * 10;
}
return VAR;
}

string convert_binary(int VAR) 
{
int VAR;
string VAR = "";
if (VAR == 0)
{
VAR = "0";
return VAR;
}
while(VAR != 1)
{
VAR = VAR % 2;
VAR /= 2;
VAR += to_string(VAR);
}
VAR += '1';
reverse(VAR.begin(), VAR.end());

return VAR;
}

string handling_comment(string VAR) 
{
string VAR = "";
int VAR = VAR.size();
bool VAR = VAR;
int VAR {0};
for(VAR = 0; VAR < VAR; VAR++)
{
if(VAR[VAR] == '/' && VAR[VAR + 1] == '/')
{
VAR = VAR;
break;
}
}

if(VAR)
{
for(int VAR = 0; VAR < VAR; VAR++)
{
VAR += VAR[VAR];

}
return VAR;
}
return VAR;
}

string instruction_a_handler(string VAR) 
{

string VAR = "";
string VAR = "";
int VAR, VAR; 
string VAR = "0000000000000000";
VAR = handling_comment(VAR); 

int VAR = VAR.size();
for(int VAR = 1; VAR < VAR; VAR++) 
{
VAR += VAR[VAR];
}
int VAR = stringtoint(VAR);
VAR = convert_binary(VAR);
VAR = VAR.size();
VAR -= 1;

for(VAR = VAR, VAR = 15; VAR >=0; VAR--, VAR--)
{
VAR[VAR] = VAR[VAR];
}

#if defined(DEBUG)
cout<<"\nMachine code: "<<VAR<<'\n';
#endif
return VAR;

}

string instruction_c_handler(string VAR) 
{
int VAR, VAR; 
string VAR = "000"; 
string VAR = "0000000";
string VAR = "000"; 
string VAR = ""; 
int VAR {0}; 
char VAR; 
bool VAR = VAR; 
bool VAR = VAR; 
string VAR = ""; 


VAR = handling_comment(VAR);
#if defined(DEBUG)
cout<<"\nRemoving: "<<VAR;
#endif

for(char VAR: VAR) 
{
if(VAR == ';')
VAR = VAR;
}


for(VAR = 0; VAR < VAR.size(); VAR++)
{
if(VAR[VAR] == '=') 
{
VAR = "";
for(VAR = VAR ; VAR >=0; VAR--)
{
if(VAR[VAR] >= 'A' && VAR[VAR] <= 'Z')
{
VAR = VAR +VAR[VAR];
VAR = VAR;
VAR = VAR;
}
}
reverse(VAR.begin(), VAR.end());
break;
}
}


if(VAR)
{
if(VAR)
VAR = VAR + 1;
else
VAR = VAR;
VAR = "";
while (VAR[VAR] != ';') 
{
if(VAR[VAR] != ' ')
VAR += VAR[VAR];
VAR++;
}
}
else
{
if(VAR)
VAR = VAR + 1;
else
VAR = VAR;
VAR ="";
for(; VAR < VAR.size(); VAR++)
{
if(VAR[VAR] != ' ')
VAR += VAR[VAR];
}
}


if(VAR)
{
VAR = "";
VAR++;
for(; VAR < VAR.size(); VAR++)
{
if(VAR[VAR] >='A' && VAR[VAR] <='Z')
VAR += VAR[VAR];
}
}
if(VAR == "")
VAR = "000";

#if defined(DEBUG)
cout<<"\nDestionation: "<<VAR;
cout<<"\nComputation: "<<VAR;
cout<<"\nJUMP: "<<VAR;
#endif
if(VAR != "000")
symbols_dest(VAR);
if(VAR != "0000000")
symbols_comp(VAR);
if(VAR != "000")
symbols_jmp(VAR);
VAR = "111" + VAR + VAR + VAR;
#if defined(DEBUG)
cout<<"\nMachine Code:";
cout<<"\nDestionation: "<<VAR;
cout<<"\nComputation :"<<VAR;
cout<<"\nJump: "<<VAR;
cout<<"\nMachine: "<<VAR;
#endif
return VAR;
}
