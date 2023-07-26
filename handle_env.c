#include "main.h"

/**
 * _printenv - prints the environment variables
 * @cmd_line: command line arguments
 */

void _printenv()
{
	unsigned int i, j;
	char **env = environ;
	char *newline = "\n";

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
			j++;

		write(STDOUT_FILENO, env[i], j);

		write(STDOUT_FILENO, newline, 1);
		i++;
	}
}
