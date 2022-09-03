if_one = "if(VAR == 10)\n{\n return 0;\n}\n"
if_two = "if(VAR == 11)\n{\n return VAR;\n}\n"
if_three = "if(VAR && VAR[VAR] == NULL)\n{\n continue;\n}\n";
if_0 = "if ( VAR == 10)\n"
if_1 = "if ( VAR == 11)\n"
if_2 = "if ( VAR == 12)\n"
fhand = open("./clean_data/if_train.c", "w+")

for idx in range(0, 1000):
    fhand.write(if_one)
    fhand.write(if_two)
    fhand.write(if_three)
    fhand.write(if_0)
    fhand.write(if_1)
    fhand.write(if_2)
fhand.close()