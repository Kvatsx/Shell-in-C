// Kaustav Vats (2016048)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

char input[100];
char *pArg[100];
char *path = "/mnt/d/College/Semester-4/Operating System/Assignments/Assignment 0/Shell in C/commands/";
char *pPath[30];

void Help()
{
	printf("\n-----Need Help?-----\n");
	printf("Commands Available\n");
	printf("cd\n");
	printf("exit\n");
	printf("ls\n");
	printf("pwd\n");
	printf("rm\n");
	printf("cat\n");
	printf("date\n");
	printf("mkdir\n");
	printf("history\n");
	printf("echo\n\n");
}
void pwd()
{
	char currentwd[1024];
	getcwd(currentwd, sizeof(currentwd));
	printf(COLOR_YELLOW "%s" COLOR_GREEN " >> " COLOR_RESET, currentwd );
}
void getpwd()
{
	char currentwd[1024];
	getcwd(currentwd, sizeof(currentwd));
	printf("%s\n", currentwd);
}

int main(int argc, char const *argv[])
{
	printf("Ultra Simple Shell: Type" COLOR_RED " 'exit' " COLOR_RESET "to exit the shell.\n");
	while ( 1 )
	{
		printf(COLOR_CYAN "ush@" COLOR_RESET );
		pwd();

		if( fgets(input, 100, stdin) == NULL )
		{
			break;
		}
		if ( strcmp(input, "\n") == 0 )
		{
			continue;
		}
// Append command to a file.
		FILE *f;
		f = fopen("/mnt/d/College/Semester-4/Operating System/Assignments/Assignment 0/Shell in C/log.txt", "a");
		if ( strlen(input) != 0 )
		{
			// printf("Our Input: %s\n", input);
			fprintf(f, "%s", input);
		}
		fclose(f);

		if (input[strlen(input) - 1] == '\n')
		{
			input[strlen(input) - 1] = '\0';
		}

		char *parser;
		parser = strtok(input, " ");
		int j = 0;
		while ( parser != NULL )
		{
			pArg[j] = parser;
			parser = strtok(NULL, " ");
			j++;
		}
		pArg[j] = NULL;

		strcpy(pPath, path);
		strcat(pPath, pArg[0]);
// Exit command
		if ( strcmp(pArg[0], "exit") == 0 )
		{
			printf(COLOR_GREEN "Thankyou for using Ultra Simple Shell.\n" COLOR_RESET);
			kill(0, SIGINT);  // send an INT signal
			kill(0, SIGKILL);
			exit(0);
		}
// Pwd command
		else if ( strcmp(pArg[0], "pwd") == 0 )
		{
			getpwd();
		}
// help command
		else if ( strcmp(pArg[0], "help") == 0 )
		{
			Help();
		}
// echo command
		else if ( strcmp(pArg[0], "echo") == 0 )
		{
			if ( j == 1 )
			{
				if ( j == 1 )
				{
					printf("\n");
				}
			}
			else
			{
				if ( strcmp(pArg[1], "-n") == 0 )
				{
					int j = 2;
					while ( pArg[j] != NULL )
					{
						printf("%s ", pArg[j]);
						j++;
					}
				}
				else if ( strcmp(pArg[1], "-e") == 0 )
				{
					// printf("%s\n", "LOL1");
					int j = 2;
					while ( pArg[j] != NULL )
					{
						char *ptr;
						ptr = pArg[j];
						int i=0;
						while ( i < strlen(pArg[j]) )
						{
							// printf("\n");
							// printf("%s\n", ptr);
							if ( ptr[i] == 92 )
							{
								if ( ptr[i+1] == 'n' )
								{
									// printf("%s\n", "lol2");
									printf("\n");
								}
								else if ( ptr[i+1] == 'a' )
								{
									printf("\a");
								}
								else if ( ptr[i+1] == 'b' )
								{
									printf("\b");
								}
								else if ( ptr[i+1] == 'e' )
								{
									printf("\e");
								}
								else if ( ptr[i+1] == 'f' )
								{
									printf("\f");
								}
								else if ( ptr[i+1] == 'r' )
								{
									printf("\r");
								}
								else if ( ptr[i+1] == 't' )
								{
									printf("\t");
								}
								else if ( ptr[i+1] == 'v' )
								{
									printf("\v");
								}
								i++;
							}
							else
							{
								printf("%c", ptr[i]);
							}
							i++;
						}
						j++;
						printf(" ");
					}
					printf("\n");
				}
				else if ( strcmp(pArg[1], "-E") == 0 )
				{
					int j = 2;
					while ( pArg[j] != NULL )
					{
						printf("%s ", pArg[j]);
						j++;
					}
					printf("\n");
				}
				else
				{
					char *p;
					p = pArg[1];
					if ( p[0] == 45 )
					{
						fprintf(stderr, "Syntax Error: echo\nUse: echo [option] [string]\nOptions: -n, -e, -E\nString in double quotes\n");
					}
					else
					{
						int j = 1;
						while ( pArg[j] != NULL )
						{
							printf("%s ", pArg[j]);
							j++;
						}
						printf("\n");
					}
				}
			}
			
		}
// cd command
		else if ( strcmp(pArg[0], "cd") == 0 )
		{
			if ( j == 1 )
			{
				if ( chdir("/mnt") != 0 )
				{
					fprintf(stderr, "%s\n", "Path Problem!");
				}
			}
			else if ( j == 2 )
			{
				if ( chdir(pArg[1]) != 0 )
				{
					fprintf(stderr, "%s\n", "Path Problem!");
				}
			}
			else
			{
				char *p;
				p = (char*)malloc(4095*sizeof(char));
				int i = 1;
				int k=0;
				while ( pArg[i] != NULL )
				{
					char *ptr;
					ptr = pArg[i];
					int l = 0;
					while ( l < strlen(pArg[i]) )
					{
						p[k] = ptr[l];
						k++;
						l++;
					}
					p[k] = ' ';
					k++;
					i++;
				}
				p[k-1] = '\0';
				// printf("%s\n", p);
				// printf("%d\n", strlen(p));
				if ( chdir(p) != 0 )
				{
					fprintf(stderr, "%s\n", "Path Problem!");
				}
			}
		}
// history command
		else if ( strcmp(pArg[0], "history") == 0 )
		{
			if ( j == 1 )
			{
				FILE *f;
				int MaxSize = 1024;
				char Line[MaxSize];
				if ( (f = fopen("/mnt/d/College/Semester-4/Operating System/Assignments/Assignment 0/Shell in C/log.txt", "rb")) == NULL )
				{
					fprintf(stderr, "%s\n", "Commands not stored properly, File Problem!");
				}
				int i=0;
				// int j=0;
				while ( fgets(Line, MaxSize, f) )
				{
					// if ( i%2 == 0 )
					// {
					// 	printf(" %d %s", j, Line);
					// 	j++;
					// }
					printf(" %d %s", i, Line );
					i++;
				}
			}
			else
			{
				fprintf(stderr, "Syntax Error: history\nUse: history\n");
			}
		}
		else if ( fork() == 0 )
		{
			// Child
			if ( execvp(pPath, pArg) < 0 )
			{
				fprintf(stderr, "%s\n", "Could not execute command");
			}
		}
		else
		{
			// Parent
			wait(NULL);
		}

	}

	return 0;
}