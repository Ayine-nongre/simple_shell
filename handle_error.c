#include "main.h"

/**
 * to_str - converts int to string
 * @num: value to convert
 * Return: string value
 */

char *to_str(int num) {
	char *string;
	char *temp;
	int i, len;

	string = malloc(6 * sizeof(char));
	if (!string)
		exit(1);

	if (num == 0) {
		string[0] = '0';
		string[1] = '\0';
		return (string);
	}

	for (i = 0; num; i++) {
		string[i] = '0' + (num % 10);
		num /= 10;
	}
	string[i] = '\0';

	/* Reverse the string */
	temp = strdup(string);
	len = strlen(string);
	for (i = 0; --len >= 0; ++i)
		string[i] = temp[len];
	free(temp);
	return (string);
}

/**
 * err_msg - prints a message
 * @err: string value
 */

void err_msg(char *err)
{
	write(STDERR_FILENO, err, strlen(err));
}

/**
 * err_printer - prints err message
 * @cmd_line: name of program
 * @cmd: command that failed
 * @count: number of executions
 */

void err_printer(char *cmd_line, char *cmd, int count)
{
	err_msg(cmd_line);
	err_msg(": ");
	err_msg(to_str(count));
	err_msg(": ");
	err_msg(cmd);
	err_msg(": ");

	if (errno == 126 || errno == 127)
		err_msg(errno == 127 ? "not found\n" : "Permission denied\n");
}
