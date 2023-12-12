#include "shell.h"

/**
 * read-line - read a char (line) from the standard input and output
 *
 * Return: the command from the user's input
 */
char *read-line(void)
{
	char *line = NULL;
	size_t buffer_size = 0;

	if (getline(&line, &buffer_size, stdin) == -1)
	{
		perror("getline");
		exit(1);
	}

	return (line);
}
