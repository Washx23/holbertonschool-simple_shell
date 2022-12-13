#include "main.h"

/**
 * free_grid - funcion
 * @grid: pointer
 * @height: integer
 * Return: always
 */
int free_grid(char **grid)
{
	int index = 0;

	if(!grid)
		return(0);

	for (; index < 0; index++)
		free(grid[index]);
	free(grid);
	return(0);
}
/**
 * _calloc - malloc-like function that initializes to '0
 * @nmemb: unsigned int
 * @size: unsigned int
 * Return: always
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i = 0;
	char *a = NULL;

	if (nmemb)
	{
		if (nmemb == 0 || size == 0)
			return (NULL);
		a = malloc(size * nmemb);

		if (a == NULL)
		{
			return (NULL);
		}
		for (i = 0; i < (nmemb * size); i++)
		{
			a[i] = 0;
		}
	}
	return (a);
}
