#include "main.h"

/**
 * _printenv - prints the environment variables
 * @env: environment variable
 */

void _printenv(char **env)
{
	unsigned int i;

	i = 0;
	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}
