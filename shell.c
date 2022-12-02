#include "main.h"
char ** split_line(char *line);
void get_path(void);
/**
 *
 *
 */
int main(void)
{
	char * BUF = NULL;
	size_t i = 0;
	char ** BUFTOK = NULL;
	
	while(1)
	{
		printf("$");

		if(getline(&BUF, &i, stdin) == -1)
			return(0);
		BUFTOK = split_line(BUF);
		get_path();
	}
}
char ** split_line(char *line)
{
	char *token;
	char ** tokens;
	int i = 1024;
	int j = 0;

	tokens = malloc(sizeof(char *) * i);
	token = strtok(line, " \n");
	while (token)
	{
		tokens[j] = token;
		token = strtok(NULL, " \n");
		j++;	
	}
	return (tokens);
}
void get_path(void)
{
	/*getenv obtene el valor de la variable de entorno que nosotros queremos*/
	char *path = getenv("PATH");
	char *ptoken;
	char **pathtokens;
	int i = 1024;
	int j = 0;

	pathtokens = malloc(sizeof(char*) * i);
	ptoken = strtok(path, ":");
	while (ptoken)
	{
		pathtokens[j] = ptoken;
		ptoken = strtok(NULL, ":");
		j++;
	}
}
