#include "main.h"

/**
 * __exit - custom exit function
 * @stat: exit status
 */

void __exit(char *stat)
{
	int status = 0;

	if (stat != NULL)
	{
		status = atoi(stat);
	}
	free(command);
	exit(status);
}
