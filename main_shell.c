#include "shell.h"

int main (int argc, char *argv[], char **env)
{
	/*void(argc);*/
	signal(SIGINT, CTRLC);
	make_env(env);
	call_shell(argv[0]);
	return(0);
}

void CTRLC(int indicator)
{
	write(STDOUT_FILENO, "\n", 1);
	prompt_out(22);
	(void) indicator;

}

char *old_dir(void)
{
	int i = 0, j;
	char *mydir;

	while(compstr(environ[i], "OLDDIR", 6) != 0)
		i++;
	for (j = 0; environ[i][j] != '='; j++)
	mydir = environ[i] + 1 + j;
	return (mydir);
}

void file_init(char *writebuff, int writeint)
{
	int fd1, logged, fd2, history;
	char *path;

	path = homedir();
	path = joinstr(path, "/logging.txt");
	fd1 = open(path, O_RDWR | O_TRUNC | O_CREAT, 0660);
	free(path);
	path = homedir();
	path = joinstr(path, "/history.text");
	fd2 = open (path, O_RDWR | O_APPEND | O_CREAT, 0660);
	free(path);
	logged = write(fd1, writebuff,  writeint);
	if (logged < 0)
		exit(-1);
	history = write(fd2, writebuff, writeint);
	if (history < 0)
		exit(-1);
	close(fd1);
	close(fd2);
}
