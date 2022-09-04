import re
import os
for filename in os.listdir("./data"):
    fhand = open("data/" + filename, "r")
    clean = open("clean_data/" + filename, "w+")
    regex_1 = r"([a-z]* +)?([a-z\*?]+) +([\*?_a-z]+[0-9]*[a-z]*)(\[[0-9]*\])? *(=|;)" #regex for the variables...
    regex_2 = r"\( *([a-z]* +)?([a-z\*?]+) +([\*?_a-z]+[0-9]*[a-z]*)(\[[0-9]*\])?"
    regex_3 = r" *, *([a-z]* +)?([a-z\*?]+) +([\*?_a-z]+[0-9]*[a-z]*)(\[[0-9]*\])?"
    regex_list = [regex_1, regex_2, regex_3]
    vars = []
    for line in fhand:
        line = line.strip()
        for regex in regex_list:
            results = re.findall(regex, line)
            for result in results:     
                can = str(result[2]).strip().strip("*")
                if(can not in vars):
                    vars.append(can)
    print(vars)
    fhand.seek(0)
    for line in fhand:
        line = line.strip()
        if(re.search(r"\/\/.*", line) is not None):
            line = re.sub(r"\/\/.*", "", line)
        for var in vars:
            res = re.search(f"\\b{var}\\b", line)
            if(res is not None):
                if(var != ""):
                    line = re.sub(f"\\b{var}\\b", "VAR", line)
        clean.write(line + '\n')
    fhand.close()
    clean.close()

