all: compile run

compile: shell.c ls.c cat.c date.c rm.c mkdir.c
	gcc -w shell.c -o shell
	gcc -w ls.c -o ls
	gcc -w cat.c -o cat
	gcc -w date.c -o date
	gcc -w rm.c -o rm
	gcc -w mkdir.c -o mkdir
	mkdir commands
	mv ls commands
	mv cat commands
	mv date commands
	mv rm commands
	mv mkdir commands

run:
	./shell

clean:
	rm -r commands
	rm shell