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
#include <ctype.h>
#include <errno.h>

extern char **environ;
extern int errno;

/*********string manipulation functions****************/
char *_strncat(char *dest, char *src, int n);
int _strcmp(char *s1, char *s2);

/*********shell handling functions********************/
char *check_path(char *path);
void _printenv(char **cmd_line);
void err_msg(char *err);
void err_printer(char *cmd_line, char *cmd, int count);
void __exit(char *stat);
bool isEmptySpaces(char *cmd);
int execute(char **argv);
int loop(char **cmd_line);

#endif
