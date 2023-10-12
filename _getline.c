#include "shell.h"

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
