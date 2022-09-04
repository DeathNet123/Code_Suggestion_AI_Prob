import random
filename = ["filename", "\"file.txt\"", "\"log.txt\"", "VAR"]
mode = ["O_RDWR", "O_RDONLY", "O_WRONLY", "O_APPEND", "O_CREAT"]
fhand = open("./clean_data/open_train.c", "a+")
for idx in range (0, random.randint(0, 100)):
    o = random.choice(filename)
    modes = ""
    for idx in range(0, random.randint(1, 3)):
        vr = random.choice(mode)
        modes += vr + "|"
    modes = modes[: len(modes) - 1] 
    fhand.write(f"int VAR = open({o}, {modes});\n")
fhand.close()