import random
op = ["!=", "==" , ">=", "<="]
var_part = ["", "[VAR]"]
part = ["NULL", "VAR", 10, 20, 30, 40]
fhand = open("./clean_data/if_train.c", "a+")
for idx in range (0, random.randint(0, 1000)):
    o = random.choice(op)
    vr = random.choice(var_part)
    p = random.choice(part)
    fhand.write(f"if(VAR {vr} {o} {p})\n")
fhand.close()