#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>
#include <fcntl.h>

char *_strncat(char *dest, char *src, int n);
char *check_path(char *path);
void _printenv(char **env, char **cmd_line);
char *_strtok(char *str, const char *delim);

#endif
