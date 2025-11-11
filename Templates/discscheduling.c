#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

void fcfs(int req[], int n, int head) {
    int total = 0;
    printf("\nFCFS Order: %d ", head);
    for (int i = 0; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d", req[i]);
    }
    printf("\nTotal Head Movement: %d\n", total);
}

void sstf(int req[], int n, int head) {
    int done[n], total = 0;
    for (int i = 0; i < n; i++) done[i] = 0;
    printf("\nSSTF Order: %d ", head);
    for (int i = 0; i < n; i++) {
        int min = 9999, pos = -1;
        for (int j = 0; j < n; j++) {
            if (!done[j] && abs(req[j] - head) < min) {
                min = abs(req[j] - head);
                pos = j;
            }
        }
        done[pos] = 1;
        total += abs(req[pos] - head);
        head = req[pos];
        printf("-> %d", head);
    }
    printf("\nTotal Head Movement: %d\n", total);
}

void scan(int req[], int n, int head, int disk_size, int dir) {
    int total = 0;
    sort(req, n);
    int pos;
    for (pos = 0; pos < n && req[pos] < head; pos++);
    printf("\nSCAN Order: %d ", head);

    if (dir == 1) {
        for (int i = pos; i < n; i++) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d", head);
        }
        total += abs((disk_size - 1) - head);
        head = disk_size - 1;
        for (int i = pos - 1; i >= 0; i--) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d", head);
        }
    } else {
        for (int i = pos - 1; i >= 0; i--) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d", head);
        }
        total += head;
        head = 0;
        for (int i = pos; i < n; i++) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d", head);
        }
    }
    printf("\nTotal Head Movement: %d\n", total);
}

void cscan(int req[], int n, int head, int disk_size) {
    int total = 0;
    sort(req, n);
    int pos;
    for (pos = 0; pos < n && req[pos] < head; pos++);
    printf("\nCSCAN Order: %d ", head);

    for (int i = pos; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d", head);
    }
    total += abs((disk_size - 1) - head);
    total += (disk_size - 1);
    head = 0;
    for (int i = 0; i < pos; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d", head);
    }
    printf("\nTotal Head Movement: %d\n", total);
}

void look(int req[], int n, int head, int dir) {
    int total = 0;
    sort(req, n);
    int pos;
    for (pos = 0; pos < n && req[pos] < head; pos++);
    printf("\nLOOK Order: %d ", head);

    if (dir == 1) {
        for (int i = pos; i < n; i++) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d", head);
        }
        for (int i = pos - 1; i >= 0; i--) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d", head);
        }
    } else {
        for (int i = pos - 1; i >= 0; i--) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d", head);
        }
        for (int i = pos; i < n; i++) {
            total += abs(req[i] - head);
            head = req[i];
            printf("-> %d", head);
        }
    }
    printf("\nTotal Head Movement: %d\n", total);
}

void clook(int req[], int n, int head) {
    int total = 0;
    sort(req, n);
    int pos;
    for (pos = 0; pos < n && req[pos] < head; pos++);
    printf("\nCLOOK Order: %d ", head);

    for (int i = pos; i < n; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d", head);
    }
    total += abs(head - req[0]);
    head = req[0];
    for (int i = 0; i < pos; i++) {
        total += abs(req[i] - head);
        head = req[i];
        printf("-> %d", head);
    }
    printf("\nTotal Head Movement: %d\n", total);
}

int main() {
    int n, head, disk_size, dir, ch;
    printf("Enter number of requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter request sequence: ");
    for (int i = 0; i < n; i++) scanf("%d", &req[i]);
    printf("Enter initial head position: ");
    scanf("%d", &head);
    printf("Enter disk size: ");
    scanf("%d", &disk_size);
    printf("Enter direction (1 for high, 0 for low): ");
    scanf("%d", &dir);

    printf("\n1.FCFS\n2.SSTF\n3.SCAN\n4.C-SCAN\n5.LOOK\n6.C-LOOK\nEnter choice: ");
    scanf("%d", &ch);

    switch (ch) {
        case 1: fcfs(req, n, head); break;
        case 2: sstf(req, n, head); break;
        case 3: scan(req, n, head, disk_size, dir); break;
        case 4: cscan(req, n, head, disk_size); break;
        case 5: look(req, n, head, dir); break;
        case 6: clook(req, n, head); break;
        default: printf("Invalid choice\n");
    }
    return 0;
}
