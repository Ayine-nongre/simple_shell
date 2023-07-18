#include "main.h"

static int count;

/**
 * token_generator - breaks string into tokens
 * @str: string to be broken
 * @delim: delimiter
 * @i: loop param
 * Return: string pointer
 */

char *token_generator(char *str, const char *delim, int i)
{
	unsigned int k = 0, j;
	char *token;

	token = malloc(sizeof(char) * 1024);

	while (*(str + i) != '\0')
	{
		j = 0;
		while (*(delim + j) != *(str + i)  && *(delim + j) != '\0')
			j++;
		if (j == strlen(delim))
		{
			token[k] = str[i];
			k++;
		}
		else
			break;
		i++;
	}
	count = i;

	return (token);
}

/**
 * _strtok - breaks string into tokens
 * @str: string to be broken
 * @delim: delimiter
 * Return: string pointer
 */

char *_strtok(char *str, const char *delim)
{
	static char *savedStr;
	char *token;
	unsigned int i;

	if (str != NULL)
	{
		i = 0;
		savedStr = str;

		token = token_generator(str, delim, i);
	}
	else
	{
		str = savedStr;
		i = count + 1;

		token = token_generator(str, delim, i);
	}

	if (*(str + i) == '\0')
		return (NULL);

	return (token);
}
