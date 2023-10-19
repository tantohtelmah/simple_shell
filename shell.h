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
#include <sys/stat.h>
#include <signal.h>
#include <fcntl.h>
#include <linux/limits.h>
#include <stdarg.h>
#include <ctype.h>
#include <errno.h>

/**
 * struct common - A struct
 * @argc: member 1
 * @argv: mem 2
 * @status: mem 3
 * @command: mem 4
 * @tmp: mem 5
 * @len: mem 6
 */

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

#endif /* SHELL_H */

