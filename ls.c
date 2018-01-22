#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

void Error()
{
	fprintf(stderr, "Error: ls, file does not exist.\n");
}
void SyntaxError(char *in)
{
	fprintf(stderr, "Syntax Error: %s\nUse: ls [options] [directory] \nOptions: -a, -1, -a1 or -1a\n", in);
	exit(1);
}

int main(int argc, char const *argv[])
{
	struct dirent **names;
	int n;

	if ( argc == 1 )
	{
		n = scandir(".", &names, NULL, alphasort);
		if ( n == NULL )
		{
			Error();
		}
		else if ( n < 0 )
		{
			SyntaxError(argv[0]);
		}
		else
		{
			int i=0;
			while ( i < n )
			{
				char *p;
				p = names[i]->d_name;
				if ( p[0] == '.' )
				{
					i++;
					continue;
				}
				printf("%s\t", (names[i]->d_name));
				free(names[i]);
				i++;
				if ( i%10 == 0 )
				{
					printf("\n");
				}
			}
			printf("\n");
			free(names);
		}
	}
	else if ( argc == 2 )
	{
		char *p;
		p = argv[1];
		if ( p[0] == '-' )
		{
			if ( strcmp(argv[1], "-1") == 0 )
			{
				n = scandir(".", &names, NULL, alphasort);
				if ( n < 0 )
				{
					SyntaxError(argv[0]);
				}
				else
				{
					int i=0;
					while ( i < n )
					{
						char *p;
						p = names[i]->d_name;
						if ( p[0] == '.' )
						{
							i++;
							continue;
						}
						printf("%s\n", (names[i]->d_name));
						free(names[i]);
						i++;
					}
					free(names);
				}
			}
			else if ( strcmp(argv[1], "-a") == 0 )
			{
				n = scandir(".", &names, NULL, alphasort);
				if ( n < 0 )
				{
					SyntaxError(argv[0]);
				}
				else
				{
					int i=0;
					while ( i < n )
					{
						printf("%s\t", (names[i]->d_name));
						free(names[i]);
						i++;
						if ( i%10 == 0 )
						{
							printf("\n");
						}
					}
					free(names);
					printf("\n");
				}
			}
			else if ( strcmp(argv[1], "-a1") == 0 || strcmp(argv[1], "-1a") == 0 )
			{
				n = scandir(".", &names, NULL, alphasort);
				if ( n < 0 )
				{
					SyntaxError(argv[0]);
				}
				else
				{
					int i=0;
					while ( i < n )
					{
						printf("%s\n", (names[i]->d_name));
						free(names[i]);
						i++;
					}
					free(names);
				}
			}
			else
			{
				SyntaxError(argv[0]);
			}
		}
		else
		{
			n = scandir(argv[1], &names, NULL, alphasort);
			if ( n < 0 )
			{
				Error();
			}
			else
			{
				int i=0;
				while ( i < n )
				{
					char *p;
					p = names[i]->d_name;
					if ( p[0] == '.' )
					{
						i++;
						continue;
					}
					printf("%s\t", (names[i]->d_name));
					free(names[i]);
					i++;
					if ( i%10 == 0 )
					{
						printf("\n");
					}
				}
				free(names);
				printf("\n");
			}
		}
	}
	else if ( argc == 3 )
	{
		char *p;
		p = argv[1];
		if ( p[0] == '-' )
		{
			if ( strcmp(argv[1], "-1") == 0 )
			{
				n = scandir(argv[2], &names, NULL, alphasort);
				if ( n < 0 )
				{
					Error();
				}
				else
				{
					int i=0;
					while ( i < n )
					{
						char *p;
						p = names[i]->d_name;
						if ( p[0] == '.' )
						{
							i++;
							continue;
						}
						printf("%s\n", (names[i]->d_name));
						free(names[i]);
						i++;
					}
					free(names);
				}
			}
			else if ( strcmp(argv[1], "-a") == 0 )
			{
				n = scandir(argv[2], &names, NULL, alphasort);
				if ( n < 0 )
				{
					Error();
				}
				else
				{
					int i=0;
					while ( i < n )
					{
						printf("%s\t", (names[i]->d_name));
						free(names[i]);
						i++;
						if ( i%10 == 0 )
						{
							printf("\n");
						}
					}
					free(names);
					printf("\n");
				}
			}
			else if ( strcmp(argv[1], "-a1") == 0 || strcmp(argv[1], "-1a") == 0 )
			{
				n = scandir(argv[2], &names, NULL, alphasort);
				if ( n < 0 )
				{
					Error();
				}
				else
				{
					int i=0;
					while ( i < n )
					{
						printf("%s\n", (names[i]->d_name));
						free(names[i]);
						i++;
					}
					free(names);
				}
			}
			else
			{
				SyntaxError(argv[0]);
			}
		}
		else
		{
			SyntaxError(argv[0]);
		}
	}
	else
	{
		SyntaxError(argv[0]);
	}
	return 0;
}