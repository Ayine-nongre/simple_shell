#include "main.h"

/**
 * check_path - function that checks if command is a path
 * @path: command to check
 * Return: string pointer
 */

char *check_path(char *path)
{
	char str[1024] = "/bin/";
	int i = 0, j = 0, n = 0;
	bool test = 1;

	while (*(str + i) != '\0')
		i++;

	while (*(path + j) != '\0')
		j++;

	for (n = 0; n < i; n++)
	{
		if (*(str + n) == *(path + n))
			test &= 1;
		else
			test &= 0;
	}

	if (test == 0)
		return (_strncat(str, path, j));

	return (path);
}
