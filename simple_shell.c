#include "shell.h"

/**
 * main - This is a basic  UNIX shell prompt
 *
 * @argc: this is the arguments count to the main
 * @argv: this is the pointer to an array of the strings in the args
 * @env: this are all the null-terminated array of strings
 *
 * Return: when exit code is 0 on success, and otherwise for failure
 */
int main(int argc, char **argv, char **env)
{
	char **args, *line;
	int status = 1;
	(void) argc;

	while (status)
	{
		printf("#cisfun$ ");
		line = read_line();
		args = split_line(line);
		status = execute_command(args);

		/* this is built-in environment section */
		if (strcmp(argv[0], "env") == 0)
		{
			while (*env)
			{
				printf("%s\n", *env++);
			}
			return (1);
		}

		free(line);
		free(args);
	}

	return (0);
}
