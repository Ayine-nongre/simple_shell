#include "main.h"

/**
 * _getline - reads input from keyboard
 * @lineptr: string pointer
 * @n: number of characters to read
 * @stream: file obj
 * Return: ssize_t val
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	ssize_t num_read = 1024;
	int fd;

	fd = fileno(stream);

	if (*lineptr == NULL || *n == 0)
	{
		*lineptr = malloc(sizeof(char) * 1024);
		*n = 1024;
	}

	while (num_read == 1024)
	{
		num_read = read(fd, *lineptr, 1024);
		if (num_read == -1)
			return (-1);
	}
	return (num_read);
}
