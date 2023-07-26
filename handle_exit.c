#include "main.h"

/**
 * __exit - custom exit function
 * @stat: exit status
 */

void __exit(char *stat)
{
	int status;

	if (stat == NULL)
		exit(0);
	else
	{
		status = atoi(stat);
		exit(status);
	}
}
