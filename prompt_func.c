#include "shell.h"

/**
 * main - Initiates a prompt for the simple shell
 * @argc: integer, number of arguments from the terminal
 * @argv: char, array of arguments
 * @envp: char
 * Return: Int
*/


int main(int argc, char *argv[], char **envp)
{
	char *command = NULL;
	size_t len = 0;

	printf("$ ");
	while (getppid)
	{
		/* CREATING THE PROMPT */
		_getline(&command, &len, stdin);
		printf("%s", command);

		/* checks for builtin function equal to the command */
		if (builtin_checker(command) == 0)
		{
			/* EXECUTE FUNCTION */
			printf("i dey");
		}
		else
		{
			/* EXECUTE FILE WITHIN PATH */
		}
	}
}
