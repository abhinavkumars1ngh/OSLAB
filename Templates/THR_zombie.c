#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t child_pid;

    printf("Parent Process (PID: %d)\n", getpid());

    child_pid = fork();

    if (child_pid == 0)
    {
        printf("Child Process (PID: %d), Parent PID: %d\n", getpid(), getppid());
    }
    else
    {
        sleep(5); // Parent sleeps for 5 seconds, making child a zombie
        printf("Parent Process exiting\n");
    }

    return 0;
}
