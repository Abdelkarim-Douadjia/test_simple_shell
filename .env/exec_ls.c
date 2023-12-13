#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - the main entry
 * Return: Always 0
 */
int main(void)
{
	int i;
	pid_t pid;

	for (i = 0; i < 5; i++)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(1);
		}
		else if (pid == 0)
		{
			char *args[] = {"ls", "-l", "/tmp", NULL};

			execve("/bin/ls", args, NULL);
			perror("execve");
			exit(1);
		}
		else
		{
			int status;

			wait(&status);
		}
	}
	return (0);
}
