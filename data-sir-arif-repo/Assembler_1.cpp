#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void to_A_inst(int x, ofstream &out) {
    int i, c = 0;
    int y[16];
    for (i = 0; i < 16; i++) {
        y[i] = 0;
    }
    for (i = 0 ; x > 0 ; i++) {
        y[i] = x % 2;
        x = x / 2;
    }
        for (int j = 15 ; j >= 0 ; j--) {
            out << y[j];
        }
        out << '\n';
}

void compare_table(string stri, int arr[], ofstream &out) {
    int i;
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 1;

    if (stri == "0" || stri == "1" || stri == "-1" || stri == "D" || stri == "A" || stri == "!D" || stri == "!A" || stri == "-D" || stri == "-A" || stri == "D+1" || stri == "A+1" || stri == "D-1" || stri == "A-1" || stri == "D+A" || stri == "D-A" || stri == "A-D" || stri == "D&A" || stri == "D|A") {
                arr[3] = 0;
            }
            if (stri == "0") {
                arr[4] = 1; arr[5] = 0; arr[6] = 1; arr[7] = 0; arr[8] = 1; arr[9] = 0;
            }
            else if (stri == "1") {
                arr[4] = 1; arr[5] = 1; arr[6] = 1; arr[7] = 1; arr[8] = 1; arr[9] = 1;
            }
            else if (stri == "-1") {
                arr[4] = 1; arr[5] = 1; arr[6] = 1; arr[7] = 0; arr[8] = 1; arr[9] = 0;
            }
            else if (stri == "D") {
                arr[4] = 0; arr[5] = 0; arr[6] = 1; arr[7] = 1; arr[8] = 0; arr[9] = 0;
            }
            else if (stri == "A") {
                arr[4] = 1; arr[5] = 1; arr[6] = 0; arr[7] = 0; arr[8] = 0; arr[9] = 0;
            }
            else if (stri == "!D") {
                arr[4] = 0; arr[5] = 0; arr[6] = 1; arr[7] = 1; arr[8] = 0; arr[9] = 1;
            }
            else if (stri == "!A") {
                arr[4] = 1; arr[5] = 1; arr[6] = 0; arr[7] = 0; arr[8] = 0; arr[9] = 1;
            }
            else if (stri == "-D") {
                arr[4] = 0; arr[5] = 0; arr[6] = 1; arr[7] = 1; arr[8] = 1; arr[9] = 1;
            }
            else if (stri == "-A") {
                arr[4] = 1; arr[5] = 1; arr[6] = 0; arr[7] = 0; arr[8] = 1; arr[9] = 1;
            }
            else if (stri == "D+1") {
                arr[4] = 0; arr[5] = 1; arr[6] = 1; arr[7] = 1; arr[8] = 1; arr[9] = 1;
            }
            else if (stri == "A+1") {
                arr[4] = 1; arr[5] = 1; arr[6] = 0; arr[7] = 1; arr[8] = 1; arr[9] = 1;
            }
            else if (stri == "D-1") {
                arr[4] = 0; arr[5] = 0; arr[6] = 1; arr[7] = 1; arr[8] = 1; arr[9] = 0;
            }
            else if (stri == "A-1") {
                arr[4] = 1; arr[5] = 1; arr[6] = 0; arr[7] = 0; arr[8] = 1; arr[9] = 0;
            }
            else if (stri == "D+A") {
                arr[4] = 0; arr[5] = 0; arr[6] = 0; arr[7] = 0; arr[8] = 1; arr[9] = 0;
            }
            else if (stri == "D-A") {
                arr[4] = 0; arr[5] = 1; arr[6] = 0; arr[7] = 0; arr[8] = 1; arr[9] = 1;
            }
            else if (stri == "A-D") {
                arr[4] = 0; arr[5] = 0; arr[6] = 0; arr[7] = 1; arr[8] = 1; arr[9] = 1;
            }
            else if (stri == "D&A") {
                arr[4] = 0; arr[5] = 0; arr[6] = 0; arr[7] = 0; arr[8] = 0; arr[9] = 0;
            }
            else if (stri == "D|A") {
                arr[4] = 0; arr[5] = 1; arr[6] = 0; arr[7] = 1; arr[8] = 0; arr[9] = 1;
            }
            if (stri == "M" | stri == "!M" | stri == "-M" | stri == "M+1" | stri == "M-1" | stri == "D+M" | stri == "D-M" | stri == "M-D" | stri == "D&M" | stri == "D|M") {
                arr[3] = 1;
            }
            if (stri == "M") {
                arr[4] = 1; arr[5] = 1; arr[6] = 0; arr[7] = 0; arr[8] = 0; arr[9] = 0;   
            }
            else if (stri == "!M") {
                arr[4] = 1; arr[5] = 1; arr[6] = 0; arr[7] = 0; arr[8] = 0; arr[9] = 1;   
            }
            else if (stri == "-M") {
                arr[4] = 1; arr[5] = 1; arr[6] = 0; arr[7] = 0; arr[8] = 1; arr[9] = 1;   
            }
            else if (stri == "M+1") {
                arr[4] = 1; arr[5] = 1; arr[6] = 0; arr[7] = 1; arr[8] = 1; arr[9] = 1;   
            }
            else if (stri == "M-1") {
                arr[4] = 1; arr[5] = 1; arr[6] = 0; arr[7] = 0; arr[8] = 1; arr[9] = 0;   
            }
            else if (stri == "D+M") {
                arr[4] = 0; arr[5] = 0; arr[6] = 0; arr[7] = 0; arr[8] = 1; arr[9] = 0;   
            }
            else if (stri == "D-M") {
                arr[4] = 0; arr[5] = 1; arr[6] = 0; arr[7] = 0; arr[8] = 1; arr[9] = 1;   
            }
            else if (stri == "M-D") {
                arr[4] = 0; arr[5] = 0; arr[6] = 0; arr[7] = 1; arr[8] = 1; arr[9] = 1;   
            }
            else if (stri == "D&M") {
                arr[4] = 0; arr[5] = 0; arr[6] = 0; arr[7] = 0; arr[8] = 0; arr[9] = 0;   
            }
            else if (stri == "D|M") {
                arr[4] = 0; arr[5] = 1; arr[6] = 0; arr[7] = 1; arr[8] = 0; arr[9] = 1;   
            }
            for (int j = 0; j < 16; j++) {
                out << arr[j];
            }
            out << '\n';
}

int main() {
    string s, file_name, name, fileNameOut, fileNameIn;
    char *ch;
    bool v1flag = false, v2flag = false;
    int x, count = 0, i;
    cout << "Enter File Name : ";
    cin >> fileNameIn;
    for (int i = 0 ; i < fileNameIn.length() ; i++) {
        if (fileNameIn[i] != '.') {
            fileNameOut += fileNameIn[i];
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
        string res; 
        bool s_cmt = false; 
         for (i = 0 ; i < s.length() ; i++) {  
            if (s_cmt == true && s[i] == '\n') {
                s_cmt = false; 
            }
            else if (s_cmt) {
                continue;  
            }
            else if (s[i] == '/' && s[i+1] == '/') {
                s_cmt = true;
                i++; 
            }
            else {
                res += s[i]; 
            } 
        } 
        int j = 0;
        for (int i = 0; res[i] ; i++) {
            if (res[i] != ' ') {
                res[j++] = res[i]; 
            }
        }   
        res[j] = '\0';             
        res.resize(j);
        if (res[0] == '@') {
            for (i = 1 ; res[i] != '\0' ; i++) {
                count++;
            }
            ch = new char [count];
            for (i = 0 ; res[i] != '\0' ; i++) {
                ch[i] = res[i + 1];
            }
            x = atoi(ch);
            to_A_inst(x, output);
            delete []ch;
        }
        for(i = 0 ; res[i] != '\0' ; i++) {
            if(res[i] == '=') {
                v1flag = true;
            }
        }      
        if (v1flag) {
            int a = 0, arr[16];
            for (i = 0 ; i < 16 ; i++) {
                arr[i] = 0;
            }
            string str, stri;
            for (i = 0 ; res[i] != '\0' ; i++) {
                if(!(res[i] == '=')) {
                    if (res[i] == '\r' || res[i] == '\b' || res[i] == '\n' || res[i] == '\t') {
                        break;
                    }
                    str += res[i];
                }
                else {
                    break;
                }
            }   
            if (str == "null") {
                arr[10] = 0; arr[11] = 0; arr[12] = 0;
            }
            else if (str == "M") {
                arr[10] = 0; arr[11] = 0; arr[12] = 1;
            }
            else if (str == "D") {
                arr[10] = 0; arr[11] = 1; arr[12] = 0;
            }
            else if (str == "MD") {
                arr[10] = 0; arr[11] = 1; arr[12] = 1;
            }
            else if (str == "A") {
                arr[10] = 1; arr[11] = 0; arr[12] = 0;
            }
            else if (str == "AM") {
                arr[10] = 1; arr[11] = 0; arr[12] = 1;
            }
            else if (str == "AD") {
                arr[10] = 1; arr[11] = 1; arr[12] = 0;
            }
            else if (str == "AMD") {
                arr[10] = 1; arr[11] = 1; arr[12] = 1;
            }
            for (i = 0 ; res[i] != '\0' ; i++) {
                if(res[i] == '=') {
                    a = i;
                }
            }
            for (i = a + 1 ; res[i] != '\0' ; i++) {
                if (res[i] == '\r' || res[i] == '\b' || res[i] == '\n' || res[i] == '\t') {
                    break;
                }
                stri += res[i];
            }  
            compare_table(stri, arr, output);
            v1flag = false;
        }    
        for(i = 0 ; res[i] != '\0' ; i++) {
            if(res[i] == ';') {
                v2flag = true;
            }
        }
        if(v2flag) {
            int x, j, arr[16];
            for (i = 0 ; i < 16 ; i++) {
                arr[i] = 0;
            }
            string st, stri;
            for (i = 0 ; res[i] != '\0' ; i++) {
                if(res[i] == ';') {
                    x = i;
                }
            }
            for (i = x + 1 ; res[i] != '\0' ; i++) {
                if (res[i] == '\r' || res[i] == '\b' || res[i] == '\n' || res[i] == '\t') {
                        break;
                    }
                st += res[i];
            }   
            if (st == "null") {
                arr[13] = 0; arr[14] = 0; arr[15] = 0;
            }
            else if (st == "JGT") {
                arr[13] = 0; arr[14] = 0; arr[15] = 1;
            }
            else if (st == "JEQ") {
                arr[13] = 0; arr[14] = 1; arr[15] = 0;
            }
            else if (st == "JGE") {
                arr[13] = 0; arr[14] = 1; arr[15] = 1;
            }
            else if (st == "JLT") {
                arr[13] = 1; arr[14] = 0; arr[15] = 0;
            }
            else if (st == "JNE") {
                arr[13] = 1; arr[14] = 0; arr[15] = 1;
            }
            else if (st == "JLE") {
                arr[13] = 1; arr[14] = 1; arr[15] = 0;
            }
            else if (st == "JMP") {
                arr[13] = 1; arr[14] = 1; arr[15] = 1;
            }
            for (i = 0 ; res[i] != '\0' ; i++) {
                if(!(res[i] == ';')) {
                    if (res[i] == '\r' || res[i] == '\b' || res[i] == '\n' || res[i] == '\t') {
                        break;
                    }
                    stri += res[i];
                }
                else {
                    break;
                }
            }   
            compare_table(stri, arr, output);
            v2flag = false;
        }
    }
    in.close();
    output.close();
    return 0;
}
