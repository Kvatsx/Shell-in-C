# Shell-in-C
Shell implemented in c

Kaustav Vats (2016048)

In my shell i have used fgets to take input from user then split it and stored the string in a array of pointers.
Commands i implemented in my shell are 

Internal -->
- Exit
- pwd
- help
- echo
- cd
- history

External -->
- ls
- cat
- date
- rm
- mkdir

Options used for each command
echo =  -n, -e and -E
ls = -a, -1, -a1 or -1a
cat = -n, -E
date = -r, -u
rm = -d, -i, -i -d or -d -i
mkdir = -m, -v

- Error check for number of arguments for all commands.
- Error check for option not available for all commands.
- Error check for file existence.
- Error check for command available or not.

- Assumptions i made that for some commands user wont pass combined options.(Implemented for few commands)
- For string in echo and path for cd. user can only pass arguments with max one space.
- Command will be in order:
[command] [option] [file/string]

NOTE:- 
- All binaries should be stored in /commands directory.
- For history log file i hardcoded absolute path for file.
- In shell.c i have used absolute path for all binaries.
- If you want to run this shell in your pc, please change it before running Makefile.
- For mkdir -m option mode wont work for NTFS partition.
