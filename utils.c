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
* @args: char array
* Return: integer (<0)less than, (0)eqaul to, (>0)greater
*     than builtin function
*/

int builtin_checker(char *command, char *args[], common_t *_common)
{
	int i = 0;

	if (strcmp(command, "exit") == 0)
	{
		if (args[2])
		{
			fprintf(stderr, "%s: %s: too many arguments\n", _common->argv[0], args[0]);
            exit(1);
		}
        else if (args[1])
		{
            while(args[1][i])
            {
                if (!isdigit(args[1][i++]))
                {
                    fprintf(stderr, "%s: 1: %s: Illegal number: %s\n", _common->argv[0], args[0], args[1]);
                    exit(2);
                }
            }
			exit(atoi(args[1]));
		}
		else 
		{
			exit(_common->status);
		}
    }
	else if (strcmp(command, "env") == 0)
	{
		while (environ[i] != NULL)
		{
			printf("%s\n", environ[i++]);
		}
		return (0);
	}
	else if(strcmp(command, "cd") == 0)
	{
		
	}
	else
	{
		return (0);
	}

    return (0);
}
