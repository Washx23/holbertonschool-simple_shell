#include "shell.h"

/**
 * main - main function of the shell
 *
 * Return: Always 0
 */
int main(void)
{
	char *input = NULL, **tokens = NULL;
	int status = 0, ex = 0, tty = 1;
	size_t n = 0;
	pid_t child;

	tty = isatty(0);
	while (1)
	{
		child = fork();
		if (child == -1)
		{
			perror("");
			exit(errno);
		}
		if (child == 0)
		{
			if (isatty(0))
				write(1, "$ ", 3);
			getline(&input, &n, stdin);
			tokens = _getinput(input);
			free(input);
			tokens[0] = checkexec(tokens);
			if (execve(tokens[0], tokens, environ) == -1)
			{
				perror("");
				free(tokens);
				exit(errno);
			}
		}
		if (child > 0)
		{
			ex = WEXITSTATUS(status);
			wait(&status);
			free(input);
			if (tty == 0 || WEXITSTATUS(status) == 98)
				return (ex);
		}
	}
	return (0);
}
