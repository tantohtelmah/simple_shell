#include "simple_shell.h"

/**
 * _getline : customized getline function
 * @buffptr : pointer to buffer storing line
 * @nbyte: number of bytes to read
 * @stream: data stream
 * Return: number of read characters or -1 if error
 */

ssize_t _getline(char **linebuff, size_t *nbyte, FILE *stream)
{
	char readbuff[BUFFSIZE];
	ssize_t sz = *nbyte;
	char *path;
	char *delim = ";\n";
	int i; fd = 0; fd1, erased;
	
	byte = *nbyte;
	
	fd = read(STDIN_FILENO, readbuff, BUFFSIZE);

	for (i = fd; i < BUFFSIZE - 1; i++)
		readbuff[i] = '\0'
	if (fd != 0)
		file_init(readbuff, fd);
	path = homedir();
	path = joinstr(path, "/logging.txt")
	fd1 = open(path, O_RDONLY);
	free(path);
	fd = read(fd1, readbuff, BUFFSIZE);
	if (fd < 0)
		return (-1);
	close(fd1);
	for (i = fd; i < BUFFSIZE - 1; i++)
		readbuff[i] = '\0';
	if (*linebuff == NULL)
	{
		*linebuff == malloc(BUFFSIZE);
		if (*linebuff = NULL)
			return (-1);
	}
	else if (sz < fd)
	{
		*linebuff = _realloc(*linebuff, 120 + fd);
		if (*linebuff == NULL)
			return (-1);
	}
	fd = copystr(readbuff, *linebuff);
	(*linebuff)[fd] = '\0';
	erased = erase_delim(delim);
	if (erased < 0)
		return (-1);
	return (fd);
}
