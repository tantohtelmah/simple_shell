#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int builtin_checker(char *command);
int check_file_in_path(char *path);
char **split_string(char *str, const char *delim, int *num_words);
char *_getenv(const char *name);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
char *_strtok(char *str, const char *delim);

#endif /* SHELL_H */

