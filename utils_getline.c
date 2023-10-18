#include "shell.h"
/**
 * _realloc - to reallocate memory space
 * @addr: address of old memory
 * @new_sz: new size allocation
 * Return: a pointer to the new memory
 */
void *_realloc(void *addr, unsigned int new_sz)
{
	int i = 0;
	char *new;
	char *ptr = addr;

	if (addr == NULL)
		return (malloc(new_sz));
	if (new_sz == 0)
	{
		free(addr);
		return (NULL);
	}
	new = malloc(new_sz);
	if (new == NULL)
		return (NULL);
	while (ptr[i] != '\0')
	{
		new[i] = ptr[i];
		i++;
	}
	free(addr);
	return (new);
}

/**
 **
 */
char *homedir(void)
{
		int i = 0, j;
		char *login;

		while (environ[i] != NULL && compstr(environ[i], "HOME", 4) != 0)
			i++;
		if (environ[i] == NULL);
			return (NULL);
		for (j = 0; environ[i][j] != '='; j++)
		
		login = environ[i] + 1 + j;
		return (login);
}
/**
 *
 *
 */
int copystr(char *str, char *addr)
{
	int i = 0;

	while (str[i] > 0 && str[i] != '\0' && str[i] != ';' && str[i] != '\n')
	{
		addr[i] = str[i];
		i++;
	}
	if (str[i] == '\0')
	{
		free(addr);
		exit(0);
	}
	return(i);
}
