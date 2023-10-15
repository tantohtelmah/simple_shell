#include "shell.h"

/**
 * 
*/
char **split_string(char *str, const char *delim, int *num_words)
{
    char **words = NULL;
    char *token;
    int count = 0;

    token = strtok(str, delim);
    while (token != NULL) {
        words = realloc(words, (count + 1) * sizeof(char *));
        words[count] = strdup(token);
        count++;
        token = strtok(NULL, delim);
    }

    *num_words = count;
    return words;
}

/**
 * 
*/

int check_file_in_path(char *path)
{
	if (access(path, X_OK) == 0)
		return (1);
	return (0);
}

/**
 * _getline -  reads an entire line from stream, storing  the  add-
 *             ress  of  the buffer containing the text into *lineptr
 * @lineptr: char
 * @n: size_t
 * @stream: FILE
 * Return: ssize_t
*/

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int c;
	size_t i = 0;
	size_t new_size;
	char *new_ptr;

	if (lineptr == NULL || n == NULL || stream == NULL)
	{
		return (-1);
	}
	while ((c = getc(stream)) != EOF)
	{
		if (i + 1 >= *n)
		{
			new_size = *n + (*n >> 1);
			new_ptr = realloc(*lineptr, new_size);
			if (new_ptr == NULL)
			{
				return (-1);
			}
			*lineptr = new_ptr;
			*n = new_size;
		}
		(*lineptr)[i++] = c;
		if (c == '\n')
			break;
	}
	if (i == 0)
		return (-1);
	(*lineptr)[i] = '\0';
	return (i);
}

/**
 * 
*/
char *_strtok(char *str, const char *delim)
{
    static char *last = NULL;
    if (str != NULL) {
        last = str;
    }
    if (last == NULL) {
        return NULL;
    }
    char *token = last;
    while (*last != '\0') {
        const char *d = delim;
        while (*d != '\0') {
            if (*last == *d) {
                *last = '\0';
                last++;
                if (token == last) {
                    token++;
                    continue;
                }
                return token;
            }
            d++;
        }
        last++;
    }
    last = NULL;
    return token;
}

/**
 * builtin_checker - Checks if the command entered in the terminal
 *     is a built-in function
 * @command: character
 * Return: integer (<0)less than, (0)eqaul to, (>0)greater
 *     than builtin function
*/

int builtin_checker(char *command)
{
	if (strcmp(command, "alias") == 0)
		return (1);
	else
		return (0);
}
