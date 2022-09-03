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

void compare_table(string VAR, int VAR[], ofstream &out) {
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
string s, file_name, name, fileNameOut, fileNameIn;
char *VAR;
bool VAR = false, v2flag = false;
int VAR, count = 0, VAR;
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
ifstream in(fileNameIn);
while(true) {
getline (in, s);
if (in.fail()) {
break;
}
string VAR;
bool VAR = false;
for (VAR = 0 ; VAR < s.length() ; VAR++) {
if (VAR == true && s[VAR] == '\n') {
VAR = false;
}
else if (VAR) {
continue;
}
else if (s[VAR] == '/' && s[VAR+1] == '/') {
VAR = true;
VAR++;
}
else {
VAR += s[VAR];
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
for (VAR = 1 ; VAR[VAR] != '\0' ; VAR++) {
count++;
}
VAR = new char [count];
for (VAR = 0 ; VAR[VAR] != '\0' ; VAR++) {
VAR[VAR] = VAR[VAR + 1];
}
VAR = atoi(VAR);
to_A_inst(VAR, output);
delete []VAR;
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
