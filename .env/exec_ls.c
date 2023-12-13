#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int i;
    pid_t pid;

    for (i = 0; i < 5; i++) {
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(1);
        } else if (pid == 0) {
            char *args[] = {"ls", "-l", "/tmp", NULL};
            execve("/bin/ls", args, NULL);
            perror("execve");
            exit(1);
        } else {
            int status;
            wait(&status);
        }
    }

    return (0);
}
/* In the program, we first declare an integer i and a pid_t variable pid for use later. Then, we use a for loop to create 5 child processes. In each iteration of the loop, we call fork() to create a new child process. If fork() returns a negative value, it means that the child process was not created successfully, so we print an error message using perror() and exit the program with an error code. If fork() returns 0, it means that we are in the child process, so we use execve() to run the command ls -l /tmp. The first argument to execve() is the path to the executable file we want to run, and the second argument is an array of strings that represent the arguments to the command. The last argument to execve() is an array of environment variables, which we set to NULL since we don't need to specify any. If execve() returns, it means that an error occurred, so we print an error message using perror() and exit the child process with an error code. If fork() returns a positive value, it means that we are in the parent process, so we call wait() to wait for the child process to exit. The wait() function waits for any child process to exit, and stores information about the child process's exit status in the status variable. We don't need to use the exit status in this program, so we don't do anything with it. After the child process has exited, we repeat the loop to create the next child process. */
