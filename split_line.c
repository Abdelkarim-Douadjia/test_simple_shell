#include "shell.h"

/**
 * split_line - tokenization of command passed to the standard inputs
 * @line: (chars) the line to split into commands args
 *
 * Return: array of args - that are tokenized
 */
char **split_line(char *line)
{
	int buf_size = TOKEN_BUF_SIZE;
	char **command_args = malloc(buf_size * sizeof(char *));
	char *token;
	int i = 0;

	if (!command_args)
	{
		printf("malloc: error - couldn't allocate memory\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, TOKEN_DELIMITERS);
	while (token != NULL)
	{
		command_args[i] = token;
		i++;

		if (i >= buf_size)
		{
			buf_size += TOKEN_BUF_SIZE;
			command_args = realloc(command_args, buf_size * sizeof(char *));
			if (!command_args)
			{
				printf("realloc: re-allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOKEN_DELIMITERS);
	}
	command_args[i] = NULL;
	return (command_args);
}
