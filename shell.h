#ifndef SHELL_H
#define SHELL_H

extern char **environ;
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <linux/limits.h>
#include <stdarg.h>
#include <ctype.h>
#include <errno.h>

typedef struct common
{
	int argc;
	char **argv;
	char *tmp;
	int status;
	char *command;
	size_t len;
} common_t;

int builtin_checker(char *command, char *args[], common_t *_common);
int check_file_in_path(char *path);
int execute(char *args[], int *status);
int exit_func(int argc1, ...);

#endif /* SHELL_H */

