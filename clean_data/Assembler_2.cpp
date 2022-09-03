#include <iostream>
#include <fstream>
#include <iomanip>

using namespace VAR;

void to_A_inst(int VAR, ofstream &out) {
int VAR, c = 0;
int VAR[16];
for (VAR = 0; VAR < 16; VAR++) {
VAR[VAR] = 0;
}
for (VAR = 0 ; VAR > 0 ; VAR++) {
VAR[VAR] = VAR % 2;
VAR = VAR / 2;
}
for (int VAR = 15 ; VAR >= 0 ; VAR--) {
out << VAR[VAR];
}
out << '\n';
}

void compare_table(string VAR, int *VAR, ofstream &out) {
int VAR;
VAR[0] = 1;
VAR[1] = 1;
VAR[2] = 1;

if (VAR == "0" || VAR == "1" || VAR == "-1" || VAR == "D" || VAR == "A" || VAR == "!D" || VAR == "!A" || VAR == "-D" || VAR == "-A" || VAR == "D+1" || VAR == "A+1" || VAR == "D-1" || VAR == "A-1" || VAR == "D+A" || VAR == "D-A" || VAR == "A-D" || VAR == "D&A" || VAR == "D|A") {
VAR[3] = 0;
}

if (VAR == "0") {
VAR[4] = 1; VAR[5] = 0; VAR[6] = 1; VAR[7] = 0; VAR[8] = 1; VAR[9] = 0;
}
else if (VAR == "1") {
VAR[4] = 1; VAR[5] = 1; VAR[6] = 1; VAR[7] = 1; VAR[8] = 1; VAR[9] = 1;
}
else if (VAR == "-1") {
VAR[4] = 1; VAR[5] = 1; VAR[6] = 1; VAR[7] = 0; VAR[8] = 1; VAR[9] = 0;
}
else if (VAR == "D") {
VAR[4] = 0; VAR[5] = 0; VAR[6] = 1; VAR[7] = 1; VAR[8] = 0; VAR[9] = 0;
}
else if (VAR == "A") {
VAR[4] = 1; VAR[5] = 1; VAR[6] = 0; VAR[7] = 0; VAR[8] = 0; VAR[9] = 0;
}
else if (VAR == "!D") {
VAR[4] = 0; VAR[5] = 0; VAR[6] = 1; VAR[7] = 1; VAR[8] = 0; VAR[9] = 1;
}
else if (VAR == "!A") {
VAR[4] = 1; VAR[5] = 1; VAR[6] = 0; VAR[7] = 0; VAR[8] = 0; VAR[9] = 1;
}
else if (VAR == "-D") {
VAR[4] = 0; VAR[5] = 0; VAR[6] = 1; VAR[7] = 1; VAR[8] = 1; VAR[9] = 1;
}
else if (VAR == "-A") {
VAR[4] = 1; VAR[5] = 1; VAR[6] = 0; VAR[7] = 0; VAR[8] = 1; VAR[9] = 1;
}
else if (VAR == "D+1") {
VAR[4] = 0; VAR[5] = 1; VAR[6] = 1; VAR[7] = 1; VAR[8] = 1; VAR[9] = 1;
}
else if (VAR == "A+1") {
VAR[4] = 1; VAR[5] = 1; VAR[6] = 0; VAR[7] = 1; VAR[8] = 1; VAR[9] = 1;
}
else if (VAR == "D-1") {
VAR[4] = 0; VAR[5] = 0; VAR[6] = 1; VAR[7] = 1; VAR[8] = 1; VAR[9] = 0;
}
else if (VAR == "A-1") {
VAR[4] = 1; VAR[5] = 1; VAR[6] = 0; VAR[7] = 0; VAR[8] = 1; VAR[9] = 0;
}
else if (VAR == "D+A") {
VAR[4] = 0; VAR[5] = 0; VAR[6] = 0; VAR[7] = 0; VAR[8] = 1; VAR[9] = 0;
}
else if (VAR == "D-A") {
VAR[4] = 0; VAR[5] = 1; VAR[6] = 0; VAR[7] = 0; VAR[8] = 1; VAR[9] = 1;
}
else if (VAR == "A-D") {
VAR[4] = 0; VAR[5] = 0; VAR[6] = 0; VAR[7] = 1; VAR[8] = 1; VAR[9] = 1;
}
else if (VAR == "D&A") {
VAR[4] = 0; VAR[5] = 0; VAR[6] = 0; VAR[7] = 0; VAR[8] = 0; VAR[9] = 0;
}
else if (VAR == "D|A") {
VAR[4] = 0; VAR[5] = 1; VAR[6] = 0; VAR[7] = 1; VAR[8] = 0; VAR[9] = 1;
}
if (VAR == "M" | VAR == "!M" | VAR == "-M" | VAR == "M+1" | VAR == "M-1" | VAR == "D+M" | VAR == "D-M" | VAR == "M-D" | VAR == "D&M" | VAR == "D|M") {
VAR[3] = 1;
}
if (VAR == "M") {
VAR[4] = 1; VAR[5] = 1; VAR[6] = 0; VAR[7] = 0; VAR[8] = 0; VAR[9] = 0;
}
else if (VAR == "!M") {
VAR[4] = 1; VAR[5] = 1; VAR[6] = 0; VAR[7] = 0; VAR[8] = 0; VAR[9] = 1;
}
else if (VAR == "-M") {
VAR[4] = 1; VAR[5] = 1; VAR[6] = 0; VAR[7] = 0; VAR[8] = 1; VAR[9] = 1;
}
else if (VAR == "M+1") {
VAR[4] = 1; VAR[5] = 1; VAR[6] = 0; VAR[7] = 1; VAR[8] = 1; VAR[9] = 1;
}
else if (VAR == "M-1") {
VAR[4] = 1; VAR[5] = 1; VAR[6] = 0; VAR[7] = 0; VAR[8] = 1; VAR[9] = 0;
}
else if (VAR == "D+M") {
VAR[4] = 0; VAR[5] = 0; VAR[6] = 0; VAR[7] = 0; VAR[8] = 1; VAR[9] = 0;
}
else if (VAR == "D-M") {
VAR[4] = 0; VAR[5] = 1; VAR[6] = 0; VAR[7] = 0; VAR[8] = 1; VAR[9] = 1;
}
else if (VAR == "M-D") {
VAR[4] = 0; VAR[5] = 0; VAR[6] = 0; VAR[7] = 1; VAR[8] = 1; VAR[9] = 1;
}
else if (VAR == "D&M") {
VAR[4] = 0; VAR[5] = 0; VAR[6] = 0; VAR[7] = 0; VAR[8] = 0; VAR[9] = 0;
}
else if (VAR == "D|M") {
VAR[4] = 0; VAR[5] = 1; VAR[6] = 0; VAR[7] = 1; VAR[8] = 0; VAR[9] = 1;
}
for (int VAR = 0; VAR < 16; VAR++) {
out << VAR[VAR];
}
out << '\n';
}

int main() {
string fileNameOut, fileNameIn;
int VAR = 0, count_of_var = 0, count_of_ins = 0, cur_label = 0, o = 0;
string *VAR;
int *VAR;
cout << "Enter File Name : ";
cin >> fileNameIn;
for (int VAR = 0 ; VAR < fileNameIn.length() ; VAR++) {
if (fileNameIn[VAR] != '.') {
fileNameOut += fileNameIn[VAR];
}
else {
break;
}
}
fileNameOut += ".hack";
ofstream output(fileNameOut);
ifstream input(fileNameIn);
while (true) {
string f, z, variable;
int var_number, VAR;
getline(input, f);
if (input.fail()) {
break;
}
int VAR = 0;
for (int VAR = 0; f[VAR] ; VAR++) {
if (f[VAR] != ' ') {
f[VAR++] = f[VAR];
}
}
f.resize(VAR);
if (f[0] == '(') {
VAR++;
}
else if (f[1] == '_' || (f[1] >= 'VAR' && f[1] <= 'z') || f[1] == '$' || f[1] == ':' || f[1] == '.' || (f[1] >= 'A' && f[1] <= 'Z')) {
count_of_var++;
}
}
input.close();
VAR = new string [VAR];
VAR = new int [VAR];
ifstream file(fileNameIn);
while (true) {
string VAR;
bool VAR = false, com_flag = true, empty_flag = true;
string w, q;
int VAR, r;
getline(file, w);
if (file.fail()) {
break;
}
if (w == "") {
continue;
}
for (VAR = 0 ; VAR < w.length() ; VAR++) {
if (VAR == true && w[VAR] == '\n') {
VAR = false;
}
else if (VAR) {
continue;
}
else if (w[VAR] == '/' && w[VAR+1] == '/') {
com_flag = false;
VAR = true;
VAR++;
}
else {
VAR += w[VAR];
}
}
if (o == 0) {
count_of_ins = 0;
o++;
}
else if (com_flag) {
count_of_ins++;
}
int VAR = 0;
for (int VAR = 0; w[VAR] ; VAR++) {
if (w[VAR] != ' ') {
w[VAR++] = w[VAR];
}
}
w.resize(VAR);
if (w[0] == '(') {
cur_label++;
for (VAR = 1 ; w[VAR] != ')' ; VAR++) {
if (w[VAR] == '\r' || w[VAR] == '\b' || w[VAR] == '\n' || w[VAR] == '\t') {
break;
}
VAR[cur_label - 1] += w[VAR];
}
VAR[cur_label - 1] = count_of_ins - 1;
count_of_ins--;
}
}
file.close();
string VAR;
char *VAR;
string *VAR;
VAR = new string [count_of_var];
bool VAR = false, v2flag = false, equal = true, flag = true, variable = true;
int VAR, VAR, VAR, VAR, var_num = 16, cur_var = 1, *v_num, t;
v_num = new int [count_of_var];
ifstream in(fileNameIn);
while(true) {
int VAR = 0;
getline(in, VAR);
if (in.fail()) {
break;
}
string VAR;
bool VAR = false;
for (VAR = 0 ; VAR < VAR.length() ; VAR++) {
if (VAR == true && VAR[VAR] == '\n') {
VAR = false;
}
else if (VAR) {
continue;
}
else if (VAR[VAR] == '/' && VAR[VAR+1] == '/') {
VAR = true;
VAR++;
}
else {
VAR += VAR[VAR];
}
}
int VAR = 0;
for (int VAR = 0; VAR[VAR] ; VAR++) {
if (VAR[VAR] != ' ') {
VAR[VAR++] = VAR[VAR];
}
}
VAR[VAR] = '\0';
VAR.resize(VAR);
if (VAR[0] == '@') {
if (VAR[1] >= '0' && VAR[1] <= '9') {
for (VAR = 1 ; VAR[VAR] != '\0' ; VAR++) {
VAR++;
}
VAR = new char [VAR];
VAR = 0;
for (VAR = 1 ; VAR[VAR] != '\0' ; VAR++) {
VAR[VAR++] = VAR[VAR];
}
VAR = atoi(VAR);
to_A_inst(VAR, output);
delete []VAR;
}
else if (VAR[1] == '_' || (VAR[1] >= 'VAR' && VAR[1] <= 'z') || VAR[1] == '$' || VAR[1] == ':' || VAR[1] == '.' || (VAR[1] >= 'A' && VAR[1] <= 'Z')) {
string temp, tmp;
for (VAR = 1 ; VAR[VAR] != '\0' ; VAR++) {
if (VAR[VAR] == '\r' || VAR[VAR] == '\b' || VAR[VAR] == '\n' || VAR[VAR] == '\t') {
break;
}
tmp += VAR[VAR];
}
if (tmp == "R0") { to_A_inst(0, output); variable = false;}
else if (tmp == "R1") { to_A_inst(1, output); variable = false;}
else if (tmp == "R2") { to_A_inst(2, output); variable = false;}
else if (tmp == "R3") { to_A_inst(3, output); variable = false;}
else if (tmp == "R4") { to_A_inst(4, output); variable = false;}
else if (tmp == "R5") { to_A_inst(5, output); variable = false;}
else if (tmp == "R6") { to_A_inst(6, output); variable = false;}
else if (tmp == "R7") { to_A_inst(7, output); variable = false;}
else if (tmp == "R8") { to_A_inst(8, output); variable = false;}
else if (tmp == "R9") { to_A_inst(9, output); variable = false;}
else if (tmp == "R10") { to_A_inst(10, output); variable = false;}
else if (tmp == "R11") { to_A_inst(11, output); variable = false;}
else if (tmp == "R12") { to_A_inst(12, output); variable = false;}
else if (tmp == "R13") { to_A_inst(13, output); variable = false;}
else if (tmp == "R14") { to_A_inst(14, output); variable = false;}
else if (tmp == "R15") { to_A_inst(15, output); variable = false;}
else if (tmp == "SP") { to_A_inst(0, output); variable = false;}
else if(tmp == "LCL") { to_A_inst(1, output); variable = false;}
else if(tmp == "ARG") { to_A_inst(2, output); variable = false;}
else if(tmp == "THIS") { to_A_inst(3, output); variable = false;}
else if(tmp == "THAT") { to_A_inst(4, output); variable = false;}
else if(tmp == "SCREEN") { to_A_inst(16384, output); variable = false;}
else if(tmp == "KBD") { to_A_inst(24576, output); variable = false;}
for (int VAR = 0 ; VAR < VAR ; VAR++) {
if (tmp == VAR[VAR]) {
to_A_inst(VAR[VAR], output);
variable = false;
}
}
if (cur_var == 1 && variable) {
for (VAR = 1 ; VAR[VAR] != '\0' ; VAR++) {
if (VAR[VAR] == '\r' || VAR[VAR] == '\b' || VAR[VAR] == '\n' || VAR[VAR] == '\t') {
break;
}
VAR[cur_var - 1] += VAR[VAR];
}
v_num[cur_var - 1] = var_num;
to_A_inst(v_num[cur_var-1], output);
flag = false;
equal = false;
cur_var++;
}
if (flag && variable) {
for (VAR = 1 ; VAR[VAR] != '\0' ; VAR++) {
if (VAR[VAR] == '\r' || VAR[VAR] == '\b' || VAR[VAR] == '\n' || VAR[VAR] == '\t') {
break;
}
temp += VAR[VAR];
}
for (VAR = 0 ; VAR < cur_var - 1 ; VAR++) {
if (temp == VAR[VAR]) {
t = v_num[VAR];
to_A_inst(t, output);
equal = false;
}
}
}
if(equal && variable) {
for (VAR = 1 ; VAR[VAR] != '\0' ; VAR++) {
if (VAR[VAR] == '\r' || VAR[VAR] == '\b' || VAR[VAR] == '\n' || VAR[VAR] == '\t') {
break;
}
VAR[cur_var-1] += VAR[VAR];
}
var_num++;
v_num[cur_var-1] = var_num;
to_A_inst(v_num[cur_var-1], output);
cur_var++;
}
flag = true;
equal = true;
variable = true;
}
}
for(VAR = 0 ; VAR[VAR] != '\0' ; VAR++) {
if(VAR[VAR] == '=') {
VAR = true;
}
}
if (VAR) {
int VAR = 0, VAR[16];
for (VAR = 0 ; VAR < 16 ; VAR++) {
VAR[VAR] = 0;
}
string str, VAR;
for (VAR = 0 ; VAR[VAR] != '\0' ; VAR++) {
if(!(VAR[VAR] == '=')) {
if (VAR[VAR] == '\r' || VAR[VAR] == '\b' || VAR[VAR] == '\n' || VAR[VAR] == '\t') {
break;
}
str += VAR[VAR];
}
else {
break;
}
}
if (str == "null") {
VAR[10] = 0; VAR[11] = 0; VAR[12] = 0;
}
else if (str == "M") {
VAR[10] = 0; VAR[11] = 0; VAR[12] = 1;
}
else if (str == "D") {
VAR[10] = 0; VAR[11] = 1; VAR[12] = 0;
}
else if (str == "MD") {
VAR[10] = 0; VAR[11] = 1; VAR[12] = 1;
}
else if (str == "A") {
VAR[10] = 1; VAR[11] = 0; VAR[12] = 0;
}
else if (str == "AM") {
VAR[10] = 1; VAR[11] = 0; VAR[12] = 1;
}
else if (str == "AD") {
VAR[10] = 1; VAR[11] = 1; VAR[12] = 0;
}
else if (str == "AMD") {
VAR[10] = 1; VAR[11] = 1; VAR[12] = 1;
}
for (VAR = 0 ; VAR[VAR] != '\0' ; VAR++) {
if(VAR[VAR] == '=') {
VAR = VAR;
}
}
for (VAR = VAR + 1 ; VAR[VAR] != '\0' ; VAR++) {
if (VAR[VAR] == '\r' || VAR[VAR] == '\b' || VAR[VAR] == '\n' || VAR[VAR] == '\t') {
break;
}
VAR += VAR[VAR];
}
compare_table(VAR, VAR, output);
VAR = false;
}
for(VAR = 0 ; VAR[VAR] != '\0' ; VAR++) {
if(VAR[VAR] == ';') {
v2flag = true;
}
}
if(v2flag) {
int VAR, VAR, VAR[16];
for (VAR = 0 ; VAR < 16 ; VAR++) {
VAR[VAR] = 0;
}
string st, VAR;
for (VAR = 0 ; VAR[VAR] != '\0' ; VAR++) {
if(VAR[VAR] == ';') {
VAR = VAR;
}
}
for (VAR = VAR + 1 ; VAR[VAR] != '\0' ; VAR++) {
if (VAR[VAR] == '\r' || VAR[VAR] == '\b' || VAR[VAR] == '\n' || VAR[VAR] == '\t') {
break;
}
st += VAR[VAR];
}
if (st == "null") {
VAR[13] = 0; VAR[14] = 0; VAR[15] = 0;
}
else if (st == "JGT") {
VAR[13] = 0; VAR[14] = 0; VAR[15] = 1;
}
else if (st == "JEQ") {
VAR[13] = 0; VAR[14] = 1; VAR[15] = 0;
}
else if (st == "JGE") {
VAR[13] = 0; VAR[14] = 1; VAR[15] = 1;
}
else if (st == "JLT") {
VAR[13] = 1; VAR[14] = 0; VAR[15] = 0;
}
else if (st == "JNE") {
VAR[13] = 1; VAR[14] = 0; VAR[15] = 1;
}
else if (st == "JLE") {
VAR[13] = 1; VAR[14] = 1; VAR[15] = 0;
}
else if (st == "JMP") {
VAR[13] = 1; VAR[14] = 1; VAR[15] = 1;
}
for (VAR = 0 ; VAR[VAR] != '\0' ; VAR++) {
if(!(VAR[VAR] == ';')) {
if (VAR[VAR] == '\r' || VAR[VAR] == '\b' || VAR[VAR] == '\n' || VAR[VAR] == '\t') {
break;
}
VAR += VAR[VAR];
}
else {
break;
}
}
compare_table(VAR, VAR, output);
v2flag = false;
}
}
in.close();
output.close();
return 0;
}
