#include "shell.h"

int main(void);
/**
 * main - Initiates a prompt for the simple shell
 * @argc: integer, number of arguments from the terminal
 * @argv: char, array of arguments
 * @envp: char
 * Return: Int
*/
int main(void)
{
	char *command = NULL;
	size_t len = 0;
	int i;
	char *path = getenv("PATH");
	char *path_dup;
	char *token;
	char *args[100];
	char cmd_path[PATH_MAX];
	int status;

	while (1)
	{
		status = 0;
		i = 0;
		/* CREATING THE PROMPT */
		printf("$ ");
		if (getline(&command, &len, stdin) == -1)
		{
			free(command);
			break;
		}
		args[i] = strtok(command, " \n");
		while (args[i])
			args[++i] = strtok(NULL, " \n");
		if (!args[0])
			continue;
		/* checks for builtin function equal to the command */
		if (builtin_checker(args[0]))
			continue;
			/* GETS PATH, DUPLICATES AND TOKENIZE */
		if (path == NULL)
			break;
		if (check_file_in_path(args[0]))
		{
			execute(args, &status);
		}
		else
		{
			getcwd(cmd_path, PATH_MAX);
			strcat(cmd_path, "/");
			strcat(cmd_path, args[0]);
			if (check_file_in_path(cmd_path))
			{
				execute(args, &status);
			}
			else
			{
				path_dup = strdup(path);
				token = strtok(path_dup, ":");
				while (token)
				{
					strcpy(cmd_path, token);
					strcat(cmd_path, "/");
					strcat(cmd_path, args[0]);
					if (check_file_in_path(cmd_path))
					{
						args[0] = cmd_path;
						execute(args, &status);
						break;
					}
					token = strtok(NULL, ":");
				}
				free(path_dup);
				if (!token)
					printf("Command not found\n");
			}
		}
		free(command);
	}
	return (0);
}
