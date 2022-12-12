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
		{
			free(buffer);
			return(0);
		}
		else
		{
			buftok = split_line(buffer);
			exe(buftok);
			free_grid(buftok);
		}
		if (_strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
	}
	free_grid(buftok);
	exit(EXIT_SUCCESS);
}
