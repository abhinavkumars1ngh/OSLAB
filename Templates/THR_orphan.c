#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t child_pid;

    printf("Parent Process (PID: %d)\n", getpid());

    child_pid = fork();

    if (child_pid == 0) {
        sleep(2); // Child sleeps for 2 seconds
        printf("Child Process (PID: %d), Parent PID: %d\n", getpid(), getppid());
    } else {
        printf("Parent Process, Child PID: %d\n", child_pid);
    }

    return 0;
}
