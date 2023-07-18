#include "main.h"

/**
 * _printenv - prints the environment variables
 * @env: environment variable
 * @cmd_line: command line arguments
 */

void _printenv(char **env, char **cmd_line)
{
	unsigned int i, j;
	char *newline = "\n";

	i = 0;
	while (env[i] != NULL)
	{
		j = 0;
		while (env[i][j] != '\0')
			j++;


		if (write(STDOUT_FILENO, env[i], j) == -1)
		{
			perror(cmd_line[0]);
		}

		if (write(STDOUT_FILENO, newline, 1) == -1)
		{
			perror(cmd_line[0]);
		}
		i++;
	}
}
