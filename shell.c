#include "main.h"

int main(void)
{
	char * buffer = NULL;
	size_t i = 0;

	char ** buftok;

	while (1)
	{	
		if(isatty(0) == 1)
			printf("SWF$ ");
		if(getline(&buffer, &i, stdin) == -1)
			return(0);
		buftok = split_line(buffer);
		exe(buftok);
		if (_strcmp(buffer, "exit") == 0)
		{
			return (0);
		}
	}
}
