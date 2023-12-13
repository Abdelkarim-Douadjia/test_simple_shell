#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char *command = NULL;
    size_t len = 0;
    ssize_t nread;

    while (1) {
        // Print the prompt and read the command from the user
        printf("$ ");
        nread = getline(&command, &len, stdin);
        
        // Check for errors or end of input
        if (nread == -1) {
            if (feof(stdin)) {
                printf("\n"); // End of input, print a newline and exit
                exit(EXIT_SUCCESS);
            } else {
                perror("getline"); // Error reading input, print an error message and exit
                exit(EXIT_FAILURE);
            }
        }
        
        // Print the command that was entered
        printf("%s", command);
    }

    // Free the memory allocated by getline()
    free(command);
    command = NULL;

    return (0);
}

