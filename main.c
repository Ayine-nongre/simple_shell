#include "main.h"

/**
 * isEmptySpaces - executes a command in shell
 * @cmd: string val
 * Return: bool value
 */

bool isEmptySpaces(char *cmd)
{
	int i;

	for (i = 0; cmd[i] != '\0'; i++)
	{
		if (!isspace(cmd[i]))
			return (false);
	}
	return (true);
}

/**
 * execute - executes a command in shell
 * @argv: array of strings
 * Return: int value
 */

int execute(char **argv)
{
	char *buff;
	int status;
	pid_t child_pid = 1;
	struct stat st;

	buff = check_path1(argv[0]);

	if (_strcmp(argv[0], "exit") == 0)
		__exit(argv[1]);

	if (stat(buff, &st) != 0)
	{
		errno = 127;
		return (-1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		return (-1);
	}

	if (child_pid == 0)
	{
		if (execve(buff, argv, environ) == -1)
		{
			errno = 127;
			return (-1);
		}
	}
	else
		wait(&status);
	return (0);
}

/**
 * loop - prints a prompt and takes input till error or exit
 * @cmd_line: command line arguments
 * Return: int value
 */

int loop(char **cmd_line)
{
	char *command = NULL, *prompt = "$ ", *argv[100];
	size_t n = 0;
	int input = 0, i, err_code = 0;
	int count = 0;

	while (1)
	{
		count++;
		if (isatty(STDIN_FILENO))
		{
			if (write(STDOUT_FILENO, prompt, 2) == -1)
			{
				perror(cmd_line[0]);
				return (1);
			}
		}
		input = getline(&command, &n, stdin);
		if (input == -1)
			break;
		if (input == 1 && command[0] == '\n')
			continue;
		if (isEmptySpaces(command))
			continue;

		argv[0] = strtok(command, " \t\v\b\r\n");
		i = 0;
		while (argv[i] != NULL && i < 99)
		{
			i++;
			argv[i] = strtok(NULL, " \t\v\b\r\n");
		}
		argv[i + 1] = NULL;

		err_code = execute(argv);
		if (err_code != EXIT_SUCCESS)
			err_printer(cmd_line[0], argv[0], count);

	}
	free(command);
	return (0);
}

/**
 * main - entry point of program
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * Return: int value
 */

int main(int argc __attribute__((unused)), char **argv)
{
	loop(argv);
	return (0);
}
