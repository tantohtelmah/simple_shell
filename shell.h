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
int check_file_in_path(char *path);
char **split_string(char *str, const char *delim, int *num_words);
char *_getenv(const char *name);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);
int execute(char *args[], int *status);

#endif /* SHELL_H */

