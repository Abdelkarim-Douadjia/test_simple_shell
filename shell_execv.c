#include "shell.h"

/**
 * execute_command -This command will execute a command which includes
 * arguments using fork & execve
 * @args: these are all teh argurmantes that will be passed
 *
 * Return: 1 when it is  infinite and, 0 for success
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	if (args[0] == NULL)
	{
		return (1);
	}

	/* quit the  shell interface */
	if (strcmp(args[0], "exit") == 0)
		exit(0);

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
		{
			printf("%s: command not found\n", args[0]);
		}
		exit(1);
	}
	else if (pid < 0)
	{
		perror("execvp");
	}
	else
	{
		while (waitpid(pid, &status, 0) != pid)
		{
			wait(&status);
		}
	}

	return (1);
}
