#include "main.h"
char **split_line(char *line);
char **get_path(void);
char **paste_comand(char **tokens);
void exe(char **command);
/**
 *
 *
 */
int main(char **pathtokens)
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
		exe(BUFTOK, command);
		if (strcmp(buffer, "exit_fun") == 0)
		{
			return (0);
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
	/*line : lo que quiero tokenizar 
	 * " \n" limitadores que quiero eliminar*/
	while (token)/*loop que recorre y tokeniza */
	{
		tokens[j] = token;
		token = strtok(NULL, " \n");
		/*apartir de aca tokeniza el siguiente argumento*/
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
	/*PATH : /us/bin..*/

	pathtokens = malloc(sizeof(char*) * i);
	ptoken = strtok(path, ":");
	/*path: lo que quiero tokenizar 
	 * ":" limitadores que quiero eliminar*/
	while (ptoken)/*loop que recorre y tokeniza*/
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
	char * command = NULL;
	int i = 0;
	struct stat buffer;

	while (path[i])
	{
		commandcopy = tokens[0];/*guarda una copia del getline*/
		command = malloc(strlen(path[i]) + strlen(commandcopy) + 1);
		/*almacena espacio para el PATH y el comando*/
		if (!command)
		{
			perror("ERROR!1");
			exit(EXIT_FAILURE);
		}
		strcpy(command, path[i]);
		strcat(command, "/");
		/*añade un backlash al PATH*/
		strcat(command, commandcopy);
		/*añade el argumento al PATH con el backlash*/
		if (!stat(command, &buffer))
		{
			tokens[0] = command;
			return  (tokens);
		}
		i++;
	}
	return (tokens);
}
void exe(char **command, char **BUFTOK)
{
	char * buffer = NULL;
	pid_t w, f;
	char TCX = 0;
	int wstatus;

	w = fork();

	if (w == -1)
	{
		perror("ERROR!2");
		exit(EXIT_FAILURE);
	}
	else if (w == 0)
	{
		command = paste_command(BUFTOK);
		TCX = execve(command[0], command, NULL);
		exit(0);

	}
	else 
	{
		/* WUNTRACED:habilita al padre a ser retornado al  waitpid si el hijo se deteiene o muere
		 * WCONTINUED: retorna al padre si un hijo detenido a sido reanudado mediante la entrega de 
		 * sigcont : es una señal enviada para reanudar un proceso suspendido*/
		f = waitpid(w, &wstatus, WUNTRACED | WCONTINUED);
		if (f == -1)
			exit(EXIT_FAILURE);
	}
	/*execve recive  (command[0]) el cual es el PATH, (command) el argumento
	 * y un puntero a NULL */
	/*busca si existe el argumento y lo ejecuta*/
}
int exit_fun(char ** command)
{
	return (0);
}
