#include "shell.h"

/**
* check_file_in_path - checks if file is executable
* @path: char
* Return: int
*/

int check_file_in_path(char *path)
{
	if (access(path, X_OK) == 0)
		return (1);
	return (0);
}

/**
* execute -  executes builtin functions
* @args: character
* @status: int
* Return: int
*/

int execute(char *args[], int *status)
{
	pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		execve(args[0], args, environ);
	}
	else if (pid > 0)
	{
		wait(status);
	}
	else
	{
		perror("fork");
		return (0);
	}
	return (1);
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
	if (strcmp(command, "exit") == 0)
	{
		exit(0);
	}
	else if (strcmp(command, "pwd") == 0)
	{
		char *_pwd = getenv("PWD");

		printf("%s\n", _pwd);
		return (1);
	}
	else
	{
		return (0);
	}


}
