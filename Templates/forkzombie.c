#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) perror("fork failed");
    else if (pid == 0) {
        printf("Child PID=%d, Parent PID=%d\n", getpid(), getppid());
        sleep(5);
        printf("Child alive after parent exit, New Parent PID=%d\n", getppid());
    } else {
        printf("Parent PID=%d created Child PID=%d\n", getpid(), pid);
        sleep(2);
        printf("Parent exiting now (child becomes orphan)\n");
        exit(0);
    }
    return 0;
}
