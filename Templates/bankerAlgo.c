#include <stdio.h>

int main() {
    int p, r;
    printf("Enter no of processes: ");
    scanf("%d", &p);
    printf("Enter no of resources: ");
    scanf("%d", &r);
    int alloc[p][r], max[p][r], avl[r], need[p][r], finish[p], work[r], safe[p];
    
    printf("Enter the available resources:\n");
    for (int i = 0; i < r; i++) {
        scanf("%d", &avl[i]);
        work[i] = avl[i];
    }

    printf("Enter values of allocation matrix: \n");
    for(int i = 0; i < p; i++) {
        printf("Process %d: ", i);
        for(int j = 0; j < r; j++){
        scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter values of maximum matrix: \n");
    for(int i = 0; i < p; i++){
        printf("Process %d: ", i);
        for(int j = 0; j < r; j++){
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
            finish[i] = 0;
        }
    }

    int count = 0;
    while (count < p) {
        int found = 0;
        for (int i = 0; i < p; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < r; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }
                if (j == r) {
                    for (int k = 0; k < r; k++) {
                        work[k] += alloc[i][k];
                    }
                    finish[i] = 1;
                    safe[count++] = i;
                    found = 1;
                }
            }
        }
        if (found == 0) {
            break;
        }
    }

    if (count == p) {
        printf("System is SAFE.\nSafe sequence: ");
        for (int i = 0; i < p; i++) {
            printf("%d ", safe[i]);
        }
        printf("\n");
    } else {
        printf("Deadlock\n");
    }

    return 0;
}