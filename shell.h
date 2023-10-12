#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int builtin_checker(char *command);

#endif /* SHELL_H */

