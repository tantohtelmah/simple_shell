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
	int i, j = 0, a, y = 0;
	char *path = getenv("PATH");
	char *path_dup;
	char *command_dup;
	char *token;
	char *token_command;
	char *first_token;
	char *result[100];
	char *result_command[100];
	char *args_commad[100][100];
	char *resultsptr;
	int counter = 0;
	pid_t pid; 

	while (1)
	{
		/* CREATING THE PROMPT */
		printf("$ ");
		if (getline(&command, &len, stdin) == -1)
		{
			free(command);
			break;
		}
		printf("i am here\n");
		command[strlen(command) - 1] = '\0';
		if (strlen(command) != 0)
		{
			command_dup = strdup(command);
			command_dup = strcat(command_dup, " ");
			token_command = strtok(command_dup, " ");
			first_token = strdup(token_command);
			strcpy(args_commad[0], first_token);
			a = 1;
			while (token_command != NULL)
			{

				result_command[i] = malloc(strlen(token_command + 1));
				if (result_command[i] == NULL)
				{
					printf("malloc\n");
					return (0);
				}
				strcpy(result_command[i], token_command);
				printf("%s\n", token_command);
				token_command = strtok(NULL, " ");
				strcat(args_commad[a], token_command);
				printf("%s here oh %d\n", result_command[i], i);
				a++;
			}
			printf("%s here oh %d\n", *result_command, i);
		}
		else
			continue;

		/* checks for builtin function equal to the command */
		if (builtin_checker(first_token) == 1)
		{
			/* EXECUTE FUNCTION */
			printf("builtin");
		}
		else
		{
			/* GETS PATH, DUPLICATES AND TOKENIZE */
			if (path == NULL)
				printf("PATH not found\n");
			path_dup = strdup(path);
			token = strtok(path_dup, ":");
			i = 0;
			while (token != NULL)
			{
				result[i] = malloc(strlen(token) + strlen(first_token) + 2);
				if (result[i] == NULL)
				{
					printf("malloc\n");
					return (0);
				}
				strcpy(result[i], token);
				strcat(result[i], "/");
				strcat(result[i], first_token);
				token = strtok(NULL, ":");
				if (check_file_in_path(result[i]))
				{
					printf("%s\n", result[i]);
					printf("executable\n");
					pid = fork();
					if (pid == 0)
					{
						execve(first_token, args_command, NULL);
						printf("This line will not be printed\n");
					}
					else if (pid > 0)
					{
						wait(NULL);
						printf("Child process finished\n");
					}
					else
					{
						perror("fork");
						return 1;
					}
					break;
				}
			}
		}
		counter++;
	}
	return (0);
}
