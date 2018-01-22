#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Error()
{
	fprintf(stderr, "%s\n", "File Problem!");
	exit(1);
}

void SyntaxError(char *in)
{
	fprintf(stderr, "Syntax Error: %s\nUse: cat [option] [file name]\nOptions: -n, -E\n", in);
	exit(1);
}

int main(int argc, char const *argv[])
{
	FILE *f;
	int MaxSize = 1024;
	char Line[MaxSize];

	if ( argc == 2 )
	{
		// printf("%s\n", argv[1]);
		if ( (f = fopen(argv[1], "r")) == NULL )
		{
			Error();
		}
		while ( fgets(Line, MaxSize, f) )
		{
			printf("%s", Line);
		}
	}
	else if ( argc == 3 )
	{
		if ( strcmp(argv[1],"-n") == 0 )
		{
			if ( (f = fopen(argv[2], "r")) == NULL )
			{
				Error();
				exit(1);
			}
			int i=1;
			while ( fgets(Line, MaxSize, f) )
			{
				printf("%d %s", i, Line);
				i++;
			}
		}
		else if ( strcmp(argv[1],"-E") == 0 )
		{
			if ( (f = fopen(argv[2], "r")) == NULL )
			{	
				Error();
				exit(1);
			}
			while ( fgets(Line, MaxSize, f) )
			{
				// printf("%d\n", strlen(Line));
				char *p;
				p = (char*)malloc((strlen(Line)+5)*sizeof(char));
				int i;
				for ( i=0; i<strlen(Line)-2; i++ )
				{
					p[i] = Line[i];
					//printf("Character: %c  %d\n", p[i], (int)p[i]);
				}
				p[i]='$';
				p[i+1] = '\n';
				printf("%s", p);
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
	fclose(f);
	return 0;
}