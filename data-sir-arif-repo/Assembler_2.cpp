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

void compare_table(string stri, int *arr, ofstream &out) {
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
    string fileNameOut, fileNameIn;
    int count_of_labels = 0, count_of_var = 0, count_of_ins = 0, cur_label = 0, o = 0;
    string *labels;
    int *l_num;
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
    ifstream input(fileNameIn);
    while (true) {
        string f, z, variable;
        int var_number, i;
        getline(input, f);
        if (input.fail()) {
            break;
        }
        int j = 0;
        for (int i = 0; f[i] ; i++) {
            if (f[i] != ' ') {
                f[j++] = f[i]; 
            }
        }                 
        f.resize(j);
        if (f[0] == '(') {
            count_of_labels++;
        }
        else if (f[1] == '_' || (f[1] >= 'a' && f[1] <= 'z') || f[1] == '$' || f[1] == ':' || f[1] == '.' || (f[1] >= 'A' && f[1] <= 'Z')) {
            count_of_var++;
        }    
    }
    input.close();
    labels = new string [count_of_labels];
    l_num = new int [count_of_labels];
    ifstream file(fileNameIn);
    while (true) {
        string res; 
        bool s_cmt = false, com_flag = true, empty_flag = true; 
        string w, q;
        int i, r;
        getline(file, w);
        if (file.fail()) {
            break;
        }
        if (w == "") {
            continue;
        }
        for (i = 0 ; i < w.length() ; i++) {  
            if (s_cmt == true && w[i] == '\n') {
                s_cmt = false; 
            }
            else if (s_cmt) {
                continue;  
            }
            else if (w[i] == '/' && w[i+1] == '/') {
                com_flag = false;
                s_cmt = true;
                i++; 
            }
            else {
                res += w[i]; 
            } 
        } 
        if (o == 0) {
            count_of_ins = 0;
            o++;
        }
        else if (com_flag) {
            count_of_ins++;
        }
        int j = 0;
        for (int i = 0; w[i] ; i++) {
            if (w[i] != ' ') {
                w[j++] = w[i]; 
            }
        }                 
        w.resize(j);
        if (w[0] == '(') {
            cur_label++;
            for (i = 1 ; w[i] != ')' ; i++) {
                if (w[i] == '\r' || w[i] == '\b' || w[i] == '\n' || w[i] == '\t') {
                    break;
                }
                labels[cur_label - 1] += w[i];
            }
            l_num[cur_label - 1] = count_of_ins - 1;
            count_of_ins--;
        }
    }
    file.close();
    string s;
    char *ch;
    string *variables;
    variables = new string [count_of_var];
    bool v1flag = false, v2flag = false, equal = true, flag = true, variable = true;
    int x, i, y, j, var_num = 16, cur_var = 1, *v_num, t;
    v_num = new int [count_of_var];
    ifstream in(fileNameIn);
    while(true) {
        int count = 0;
        getline(in, s);
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
            if (res[1] >= '0' && res[1] <= '9') {
                for (i = 1 ; res[i] != '\0' ; i++) {
                    count++;
                }
                ch = new char [count];
                j = 0; 
                for (i = 1 ; res[i] != '\0' ; i++) {
                    ch[j++] = res[i];
                }
                x = atoi(ch);
                to_A_inst(x, output);
                delete []ch;
            }   
            else if (res[1] == '_' || (res[1] >= 'a' && res[1] <= 'z') || res[1] == '$' || res[1] == ':' || res[1] == '.' || (res[1] >= 'A' && res[1] <= 'Z')) {
                string temp, tmp;
                for (i = 1 ; res[i] != '\0' ; i++) {
                    if (res[i] == '\r' || res[i] == '\b' || res[i] == '\n' || res[i] == '\t') {
                        break;
                    }
                    tmp += res[i];
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
                for (int y = 0 ; y < count_of_labels ; y++) {
                    if (tmp == labels[y]) {
                        to_A_inst(l_num[y], output);
                        variable = false;
                    }
                }
                if (cur_var == 1 && variable) {
                    for (i = 1 ; res[i] != '\0' ; i++) {
                        if (res[i] == '\r' || res[i] == '\b' || res[i] == '\n' || res[i] == '\t') {
                            break;
                        }
                        variables[cur_var - 1] += res[i];
                    }    
                        v_num[cur_var - 1] = var_num;
                        to_A_inst(v_num[cur_var-1], output);
                        flag = false;
                        equal = false;
                        cur_var++;
                }   
                    if (flag && variable) {
                        for (i = 1 ; res[i] != '\0' ; i++) {
                            if (res[i] == '\r' || res[i] == '\b' || res[i] == '\n' || res[i] == '\t') {
                                break;
                            }
                            temp += res[i];
                        }
                        for (i = 0 ; i < cur_var - 1 ; i++) {
                            if (temp == variables[i]) {
                                t = v_num[i];
                                to_A_inst(t, output);
                                equal = false;
                            }
                        }  
                    }      
                    if(equal && variable) {
                        for (i = 1 ; res[i] != '\0' ; i++) {
                            if (res[i] == '\r' || res[i] == '\b' || res[i] == '\n' || res[i] == '\t') {
                                break;
                            }
                            variables[cur_var-1] += res[i];
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
