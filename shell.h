#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <string.h>

#define TOKEN_BUF_SIZE 64
#define TOKEN_DELIMITERS " \t\r\n\a"

/* shell functions - prototypes */
char *read_line(void);
char **split_line(char *line);
int execute_command(char **args);

#endif /* simple_shell */
