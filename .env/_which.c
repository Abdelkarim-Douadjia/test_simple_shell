#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char *path = getenv("PATH");
	char *token;
	char *filename;
	int found = 0;

/*Check if filename(s) were provided as arguments*/
	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (1);
	}
/* Loop through each filename provided as an argument */
	for (int i = 1; i < argc; i++)
	{
		filename = argv[i];

/* Loop through each directory in the PATH */
		token = strtok(path, ":");
		while (token != NULL)
		{
/* Check if the file exists in the current directory */
			char filepath[1024];

			sprintf(filepath, "%s/%s", token, filename);
			if (access(filepath, F_OK) != -1)
			{
				printf("%s\n", filepath);
				found = 1;
				break;
			}
			token = strtok(NULL, ":");
		}

/* If the file wasn't found, print an error message */
		if (!found)
		{
			printf("%s: command not found\n", filename);
		}

/* Reset the found flag for the next filename */
		found = 0;
	}

	return (0);
}
