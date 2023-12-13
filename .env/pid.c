#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
/*# pid_t get_pid; */
    pid_t get_ppid;

/*# get_pid = getpid(); */
    get_ppid = getppid();

/*# printf("%u\n", get_pid); */
    printf("%u\n", get_ppid);
    return (0);
}
