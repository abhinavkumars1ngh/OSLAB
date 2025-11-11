#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid1, pid2, pid3, pid4;

    // Create CLD1
    pid1 = fork();
    if (pid1 == 0) {
        // Child CLD1
        printf("CLD1 Process ID: %d\n", getpid());
        execl("wc", "wc", "file.txt" ,NULL);
    } else {
        // Parent P
        wait(NULL);

        // Create CLD2
        pid2 = fork();
        if (pid2 == 0) {
            // Child CLD2
            printf("CLD2 Process ID: %d\n", getpid());
            execl("date", "date", NULL);
        } else {
            // Parent P
            wait(NULL);

            // Create CLD3
            pid3 = fork();
            if (pid3 == 0) {
                // Child CLD3
                printf("CLD3 Process ID: %d\n", getpid());
                execl("ls", "ls", "-l" , NULL);
            } else {
                // Parent P
                wait(NULL);

                // Create CLD4
                pid4 = fork();
                if (pid4 == 0) {
                    // Child CLD4
                    printf("CLD4 Process ID: %d\n", getpid());
                    execl("cat", "cat", "file1.txt" , NULL);
                } else {
                    // Parent P
                    wait(NULL);
                }
            }
        }
    }

    return 0;
}
