#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void Error()
{
	fprintf(stderr, "Cannot create directory using mkdir\n");
	exit(1);
}
void SyntaxError(char *in)
{
	fprintf(stderr, "Syntax Error: %s\nUse: mkdir [name]\nOptions: -m, -v\nEx: mkdir -m 777 -v Hello\n", in);
	exit(1);
}
int main(int argc, char const *argv[])
{
	if ( argc == 2 )
	{
		char *p;
		p = argv[1];
		if ( p[0] == "-" )
		{
			SyntaxError(argv[0]);
		}
		else if ( mkdir(argv[1], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) < 0 )
		{
			Error();
		}
	}
	else if ( argc == 3 )
	{
		if ( strcmp(argv[1], "-v") == 0 )
		{
			printf("Creating Directory with name: %s\n", argv[2]);
			char *p;
			p = argv[2];
			if ( p[0] == "-" )
			{
				SyntaxError(argv[0]);
			}
			else if ( mkdir(argv[2], S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) < 0 )
			{
				Error();
			}
		}
		else
		{
			SyntaxError(argv[0]);
		}
	}
	else if ( argc == 4 )
	{
		if ( strcmp(argv[1], "-m") == 0 )
		{
			int i;
			i = atoi(argv[2]);
			char *p;
			p = argv[3];
			if ( p[0] == "-" )
			{
				SyntaxError(argv[0]);
			}
			else if ( mkdir(argv[3], i) < 0 )
			{
				Error();
			}
		}
		else
		{
			SyntaxError(argv[0]);
		}
	}
	else if ( argc == 5 )
	{
		if ( strcmp(argv[1], "-m") == 0 )
		{
			int i;
			i = atoi(argv[2]);
			if ( strcmp(argv[3], "-v") == 0 )
			{
				printf("Creating Directory with name: %s\n", argv[4]);
				char *p;
				p = argv[4];
				if ( p[0] == "-" )
				{
					SyntaxError(argv[0]);
				}
				else if ( mkdir(argv[4], i) < 0 )
				{
					Error();
				}
			}
			else
			{
				SyntaxError(argv[0]);
			}
		}
		else if ( strcmp(argv[1], "-v") == 0 )
		{
			if ( strcmp(argv[2], "-m") == 0 )
			{
				int i;
				i = atoi(argv[3]);
				printf("Creating Directory with name: %s\n", argv[4]);
				char *p;
				p = argv[4];
				if ( p[0] == "-" )
				{
					SyntaxError(argv[0]);
				}
				if ( mkdir(argv[4], i) < 0 )
				{
					Error();
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
	}
	else
	{
		SyntaxError(argv[0]);
	}

	return 0;
}