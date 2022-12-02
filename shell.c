#include "main.h"
char **split_line(char *line);
char **get_path(void);
char **paste_comand(char **tokens);
void exe(char **command);
/**
 *
 *
 */
int main(void)
{
	char * BUF = NULL;
	size_t i = 0;
	char ** BUFTOK = NULL;
	char ** command;

	while(1)
	{
		printf("$");

		if(getline(&BUF, &i, stdin) == -1)
			return(0);
		BUFTOK = split_line(BUF);
		command = paste_comand(BUFTOK);
		exe(command);
	}
}
/**
 *
 *
 */
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
/**
 *
 *
 *
 */
char ** get_path(void)
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
	return(pathtokens);
}

char **paste_comand(char **tokens)
{
	char * commandcopy;
	char ** path = get_path();
	char * command;
	int i = 0;

	while (path[i])
	{
		commandcopy = tokens[0];
		command = malloc(strlen(path[i]) + strlen(commandcopy) + 1);
		strcpy(command, path[i]);
		strcat(command, "/");
		strcat(command, commandcopy);
		i++;
	}
	tokens[0] = command;
	return (tokens);
}
void exe(char **command)
{
	/*execve recive  (command[0]) el cual es el PATH, (command) el argumento
	 * y un puntero a NULL */
	execve(command[0], command, NULL);
}

