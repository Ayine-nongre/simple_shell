#include "main.h"

/**
 * execute - executes a command in shell
 * @cmd_line: command line arguments
 * @command: input from user
 * @env: environment variables
 * Return: int value
 */

int execute(char **cmd_line, char *command, char **env)
{
	char *buff, *argv[100];
	int status, i;
	pid_t child_pid = 1;
	struct stat st;

	argv[0] = strtok(command, " \t\v\b\r\n");
	i = 0;
	while (argv[i] != NULL && i < 99)
	{
		i++;
		argv[i] = strtok(NULL, " \t\v\b\r\n");
	}
	argv[i + 1] = NULL;

	buff = check_path(argv[0]);

	if (strcmp(argv[0], "env") == 0)
		_printenv(env, cmd_line);
	if (stat(buff, &st) != 0)
		perror(cmd_line[0]);
	else
		child_pid = fork();
	if (child_pid == -1)
	{
		perror(cmd_line[0]);
		return (1);
	}

	if (child_pid == 0)
	{
		if (execve(buff, argv, NULL) == -1)
			perror(cmd_line[0]);
	}
	else
		wait(&status);
	return (0);
}

/**
 * loop - prints a prompt and takes input till error or exit
 * @cmd_line: command line arguments
 * @env: environment variables
 * Return: int value
 */

int loop(char **cmd_line, char **env)
{
	char *command = NULL, *prompt = "$ ";
	size_t n = 0;
	int input = 0;

	while (1)
	{
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

		execute(cmd_line, command, env);

	}
	free(command);
	return (0);
}

/**
 * main - entry point of program
 * @argc: number of command line arguments
 * @argv: array of command line arguments
 * @env: enviroment variables
 * Return: int value
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	loop(argv, env);
	return (0);
}
