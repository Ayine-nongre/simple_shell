#include "main.h"

char *check_path1(char *cmd){
	char *path = getenv("PATH");
	char full_path[1024];
	char *data;
	struct stat st;


	data = strtok(path, ":");

	while (data)
	{
		strcpy(full_path, data);
		strcat(full_path, "/");
		strcat(full_path, cmd);

		if (stat(full_path, &st) == 0)
		{
			cmd = full_path;
			return (cmd);
		}

		data = strtok(NULL, ":");
	}

	return (cmd);
}
