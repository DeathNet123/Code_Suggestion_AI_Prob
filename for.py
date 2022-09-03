import random
types = ["int", "long long"]
op = ["!=", "==" , ">=", "<="]
part = ["NULL", "VAR", 10, 20, 30, 40]
end = ["VAR++", "VAR = VAR-1", "VAR--", "VAR = VAR+1"]
var_part = ["", "[VAR]"]
fhand = open("./clean_data/file.c", "a+")
for idx in range (0, random.randint(0, 1000)):
    t = random.choice(types)
    init = random.randint(0, 100)
    o = random.choice(op)
    p = random.choice(part)
    e = random.choice(end)
    vr = random.choice(var_part)
    fhand.write(f"for({t} VAR = {init}; VAR{vr} {o} {p}; {e})\n")