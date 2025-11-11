#include <stdio.h>
#include <unistd.h>

int main()
{
    int n = 3;
    printf("Initial Process (PID: %d)\n", getpid());

    for (int i = 1; i <= n; i++)
    {
        if (fork() == 0)
        {
            printf("Child Process %d (PID: %d), Parent PID: %d\n", i, getpid(), getppid());
        }
        else
        {
            wait(NULL);
        }
    }

    return 0;
}
