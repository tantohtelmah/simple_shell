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
#include "utils_getline.c"

ssize_t _getline(char **linebuff, size_t *nbyte, FILE *stream);
void *_realloc(void *addr, unsigned int new_sz);
char *homedir(void);

/* MAIN */
void file_init(char *writebuff, int writeint);
char *old_dir(void);
void KILLIT(int indicator);
void CTRLC(int indicator);

int copystr(char *str, char *addr);
int builtin_checker(char *command);

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
int exit_func(int argc1, ...);

#endif /* SHELL_H */

