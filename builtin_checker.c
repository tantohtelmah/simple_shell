#include "shell.h"

/**
 * builtin_checker - Checks if the command entered in the terminal
 *     is a built-in function
 * @command: character
 * Return: integer (<0)less than, (0)eqaul to, (>0)greater
 *     than builtin function
*/

int builtin_checker(char *command)
{
	char *type_output;
	FILE *fp;
	char result[10];

	type_output = malloc(strlen(command) + 10);
	sprintf(type_output, "type -t %s", command);
	fp = popen(type_output, "r");
	fgets(result, 10, fp);
	pclose(fp);
	/*free(type_output);*/
	return (strcmp(result, "builtin\n") == 0);
}
