#include "main.h"

/**
 *
 *
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
	token = strtok(line, "	 \n");
	while (token)
	{
		tokens[j] = token;
		token = strtok(NULL, "	 \n");/*apartir de aca tokeniza el siguiente argumento*/
		j++;
	}/*loop que recorre y tokeniza */
	return (tokens);
	/*line : lo que quiero tokenizar
	 * * " \n" limitadores que quiero eliminar*/
}
/***
 *
 *
 */
char ** get_path(void)
{
	char *path = _getenv("PATH");/*getenv obtene el valor de la variable de entorno que nosotros queremos*/
	char *ptoken;
	char **pathtokens;
	int i = 1024;
	int j = 0;
	/*PATH : /us/bin..*/

	pathtokens = malloc(sizeof(char *) * i);
	ptoken = strtok(path, ":");

	while (ptoken)
	{
		pathtokens[j] = ptoken;/*loop que recorre y tokeniza*/
		ptoken = strtok(NULL, ":");
		j++;
	}
	return (pathtokens);
	/*path: lo que quiero tokenizar
	 * ":" limitadores que quiero eliminar*/
}
/**
 *
 *
 */
char ** paste_command(char ** tokens)
{
	 char * commandcopy;
	 char ** path = get_path();
	 char * command = NULL;
	 int i = 0;
	 struct stat buf;

	 while(path[i])
	 {
		commandcopy = tokens[0];/*guarda una copia del getline*/
		command = malloc(_strlen(path[i]) + _strlen(commandcopy) + 1);
		/*almacena espacio para el PATH y el comando*/
		if(!command)
		{
			perror("ERROR!1");
			exit(EXIT_FAILURE);
		}
		_strcpy(command, path[i]);
		_strcat(command, "/");/*añade un backlash al PATH*/
		_strcat(command, commandcopy);/*añade un backlash al PATH*/
		if (!stat(command, &buf))
		{
		       tokens[0] = command;
		       return(tokens);
		}
		i++;
	}
	return (tokens);
}
/**
 *
 *
 *
 *
 */
void exe(char ** buftok)
{
	pid_t p, w;
	int wstatus;
	char **command;

	p = fork();

	if (p == -1)
	{
		perror("EEROR!2(acasapete!)");
		exit(EXIT_FAILURE);
	}
	else if (p == 0)
	{
		command = paste_command(buftok);
		execve(command[0], command, NULL);
		exit(0);
	}
	else
	{
		w = waitpid(p, &wstatus, WUNTRACED | WCONTINUED);

		if (w == -1)
			exit(EXIT_FAILURE);
		/* WUNTRACED:habilita al padre a ser retornado al  waitpid si el hijo se deteiene o muere
		 * WCONTINUED: retorna al padre si un hijo detenido a sido reanudado mediante la entrega de
		 * sigcont : es una señal enviada para reanudar un proceso suspendido*/
	}
	/* WUNTRACED:habilita al padre a ser retornado al  waitpid si el hijo se deteiene o muere
		 * WCONTINUED: retorna al padre si un hijo detenido a sido reanudado*/
}
/**
 *
 *
 *
 */
char * _getenv(char *name)
{

	int i = 0, y, count = 0, length;
	char *copy;

	copy = name;
	if (name == NULL || !name[i])
		return (NULL);

	length = _strlen(copy);
	while (*(environ + i))
	{
		y = 0;
		while (*(*(environ + i) + y) != '=')
		{
			if (*(*(environ + i) + y) == name[y])
				count++;
			y++;
		}
		if (count == length)
		{
			y++;
			return (*(environ + i) + y);
		}
		i++;
		count = 0;
	}
	return (NULL);
}
