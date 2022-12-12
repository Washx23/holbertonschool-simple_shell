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
