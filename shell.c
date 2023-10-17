#include "shell.h"

int main(int argc, char **argv);
/**
 * main - Initiates a prompt for the simple shell
 * @argc: integer, number of arguments from the terminal
 * @argv: char, array of arguments
 * @envp: char
 * Return: Int
*/
int main(int argc, char **argv)
{
	char *command = NULL;
	size_t len = 0;
	int i;
	char *path = getenv("PATH");
	char *path_dup;
	char *token;
	char *args[100];
	char cmd_path[PATH_MAX];
	common_t _common = {0};

	_common.argc = argc;
	_common.argv = argv;

	while (1)
	{
		i = 0;
		/* CREATING THE PROMPT */
		if (isatty(STDIN_FILENO))
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

		if (builtin_checker(args[0], args, &_common))
			continue;
			/* GETS PATH, DUPLICATES AND TOKENIZE */
		if (path == NULL)
			break;
		if (check_file_in_path(args[0]))
		{
			execute(args, &_common.status);
			if (_common.status == 512)
				_common.status = 2;
		}
		else
		{
			_common.tmp = getcwd(NULL, 0);
			sprintf(cmd_path, "%s/%s", _common.tmp, args[0]);
			if (check_file_in_path(cmd_path))
			{
				execute(args, &_common.status);
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
						execute(args, &_common.status);
						break;
					}
					token = strtok(NULL, ":");
				}
				free(path_dup);
				if (!token)
					printf("Command not found\n");
			}
		}
		/*free(command);*/
	}
	return (0);
}
