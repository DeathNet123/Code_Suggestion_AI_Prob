import re
line ="int handle_command_generic(char *command, int wait_flag, int in, int out) \{var\};"
var = "in"
print(f"\\b{var}\\b")
print(re.search(f"\\b{var}\\b",line))