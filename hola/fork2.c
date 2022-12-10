#include "main.h"

/**
 *vexec - function to create child process and execute correspondent
 *command passed
 *@args: double pointer pointing to string of arguments
 *@enve: enviroment inherited from parent process to use with execve
 *Return: exit status from child process
 */
int vexec(char **args, char **enve)
{
	pid_t pid;
	int status = 0;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (pid == 0)
	{

		if (execve(args[0], args, enve) == -1)
		{
			perror("Error");
		}
		free(args);
	}
	wait(&status);
	if (WIFEXITED(status))
	{
		free(args);
		return (WEXITSTATUS(status));
	}
	free(args);
	return (0);
}
