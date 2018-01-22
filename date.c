#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>

void SyntaxError(char *in)
{
	fprintf(stderr, "Syntax Error: %s\nUse: date [option] [file name]\nOptions: -r, -u\n", in);
	exit(1);
}

int main(int argc, char const *argv[])
{
	if ( argc == 1 )
	{
		time_t Time = time(NULL);
	    struct tm *Time_tm = localtime(&Time);
	    char date[64];
	    strftime(date, sizeof(date), "%c", Time_tm);
	    printf("Local time and date: %s\n", date);
	}
	else if ( argc == 3 )
	{
		if ( strcmp(argv[1], "-r") == 0 )
		{
			struct stat atb;
		    stat(argv[2], &atb);
		    char date[64];
		    strftime(date, sizeof(date), "%c", localtime(&(atb.st_ctime)));
		    printf("File %s was last modified at\n%s\n", argv[2], date);
		}
		else
		{
			SyntaxError(argv[0]);
		}
	}
	else if ( argc == 2 )
	{
		if ( strcmp(argv[1], "-u") == 0 )
		{
			time_t Time = time(NULL);
	    	struct tm *Time_tm = localtime(&Time);
  			Time_tm = gmtime(&Time);
  			char date[64];
	    	strftime(date, sizeof(date), "%c", Time_tm);
  			printf("UTC time and date: %s\n", date);
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
