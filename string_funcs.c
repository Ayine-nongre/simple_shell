#include "main.h"

/**
 * _strncat - concatenates two strings
 * @dest: destination
 * @src: source
 * @n: number
 * Return: pointer to dest
 */

char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;

	while (*(dest + i) != '\0')
	{
		i++;
	}

	while (n > 0)
	{
		*(dest + i) = *(src + j);
		if (*(src + j) == '\0')
			break;
		i++;
		j++;
		n--;
	}
	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: string one
 * @s2: string two
 * Return: int value
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0, diff = 0;

	while (diff == 0)
	{
		if (*(s1 + i) == '\0' && *(s2 + i) == '\0')
			break;
		diff = (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (diff);
}
