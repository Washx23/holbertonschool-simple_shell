#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(__attribute__((unused))int ac,__attribute__((unused)) char **av)
{
	char * lineptr = NULL;
	size_t i = 0;	
	while(1)
	{
		printf("$");
		getline(&lineptr, &i, stdin);
		printf("%s", lineptr);
	}
}

