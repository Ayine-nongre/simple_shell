#include "main.h"

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
 */

void err_printer(char *cmd_line, char *cmd)
{
	err_msg(cmd_line);
	err_msg(": ");
	err_msg("1");
	err_msg(": ");
	err_msg(cmd);
	err_msg(": ");

	if (errno == 126 || errno == 127)
		err_msg(errno == 127 ? "not found\n" : "Permission denied\n");
}
