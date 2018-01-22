#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _XOPEN_SOURCE 500

#include <ftw.h>

void Error()
{
	fprintf(stderr, "File could not be delete file\n");
	exit(1);
}
void SyntaxError(char *in)
{
	fprintf(stderr, "Syntax Error: %s\nUse: rm [option] [path]\nOptions: -d, -i or both\n", in);
	exit(1);
}
static int RemoveFiles(const char *fpath, const struct stat *sb, int typeflag, struct FTW *ftwbuf)
{
    if(remove(fpath) < 0)
    {
        Error();
        return -1;
    }
}
int main(int argc, char const *argv[])
{
	if ( argc == 2 )
	{
		char *p;
		p = argv[1];
		if ( p[0] == '-' )
		{
			SyntaxError(argv[0]);
		}
		else if ( remove(argv[1]) < 0 )
		{
			Error();
		}
	}
	else if ( argc == 3 )
	{
		if ( strcmp(argv[1], "-d") == 0 )
		{
			if ( rmdir(argv[2]) < 0 )
			{
				Error();
			}
		}
		// else if ( strcmp(argv[1], "-f") == 0 )
		// {
		// 	int flags = 0;
		// 	flags |= FTW_DEPTH;
		// 	flags |= FTW_MOUNT;
		// 	flags |= FTW_PHYS;
		// 	if ( nftw(argv[2], RemoveFiles, 20, flags) < 0)
		// 	{
		// 		Error();
		// 	}
		// }
		else if ( strcmp(argv[1], "-i") == 0 )
		{
			printf("rm: remove '%s'? reply y/n: ", argv[2]);
			char c;
			c = getchar( );
			if ( c == 'y' && remove(argv[2]) < 0 )
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
		if ( strcmp(argv[1], "-i") == 0 )
		{
			if ( strcmp(argv[2], "-d") == 0 )
			{
				printf("rm: remove '%s'? reply y/n: ", argv[3]);
				char c;
				c = getchar( );
				if ( c == 'y' && rmdir(argv[3]) < 0 && remove(argv[3]) < 0 )
				{
					Error();
				}
			}
		}
		else if ( strcmp(argv[2], "-i") == 0 )
		{
			if ( strcmp(argv[1], "-d") == 0 )
			{
				printf("rm: remove '%s'? reply y/n: ", argv[3]);
				char c;
				c = getchar( );
				if ( c == 'y' && rmdir(argv[3]) < 0 && remove(argv[3]) < 0 )
				{
					Error();
				}
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