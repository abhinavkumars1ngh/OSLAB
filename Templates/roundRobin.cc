#include <stdio.h>
#include <stdlib.h>

struct process {
  int pid;
  int ct;
  int bt;
  int timeLeft;
  int wt;
  int tat;
};

struct queue {
  struct process* q[100];
  int front;
  int rear;
};

struct process* nullProcess() {
  struct process* null = (struct process*)malloc(sizeof(struct process));
  null->pid = 0;
  null->ct = 0;
  null->bt = 0;
  null->timeLeft = 0;
  null->wt = 0;
  null->tat = 0;
  return null;
}

void enqueue(struct queue* q, struct process* element) {
  if ((q->rear + 1) % 100 == q->front) {
    printf("Queue is full\n");
    return;
  }
  if (q->front == -1) {
    q->front = 0;
  }
  q->rear = (q->rear + 1) % 100;
  q->q[q->rear] = element;
}

struct process* dequeue(struct queue* q) {
  if (q->front == -1) {
    printf("Queue is empty\n");
    return nullProcess();
  }
  struct process* element = q->q[q->front];
  q->front = (q->front + 1) % 100;
  if (q->front > q->rear) {
    q->front = -1;
    q->rear = -1;
  }
  return element;
}

void findCT(struct queue* ready, int qt) {
  int curr = 0;
  while (ready->front != -1) {
    struct process* dequeued = dequeue(ready);
    if (dequeued->timeLeft >= qt) {
      curr += qt;
      dequeued->ct = curr;
      dequeued->timeLeft -= qt;
      if (dequeued->timeLeft == 0) { 
        printf("Process %d completed\n", dequeued->pid);
      } else {
        enqueue(ready, dequeued);
      }
    } else {
      curr += dequeued->timeLeft;
      dequeued->ct = curr;
      dequeued->timeLeft = 0;
      printf("Process %d completed\n", dequeued->pid);
    }
  }
}

void findWT(struct process p[], int numP) {
  for (int i = 0; i < numP; i++) {
    p[i].wt = p[i].ct - p[i].bt;
  }
}

void findTAT(struct process p[], int numP) {
  for (int i = 0; i < numP; i++) {
    p[i].tat = p[i].ct;
  }
}

double findAvgWT(struct process p[], int n) {
  float total = 0;
  for (int i = 0; i < n; i++) {
    total += p[i].wt;
  }
  return total / n;
}

double findAvgTAT(struct process p[], int n) {
  float total = 0;
  for (int i = 0; i < n; i++) {
    total += p[i].tat;
  }
  return total / n;
}

int main() {
  int n;
  printf("Enter the number of processes to be made (minimum 5):\n");
  scanf("%d", &n);

  int qt;
  printf("Enter the value of time quantum:\n");
  scanf("%d", &qt);

  struct process p[n];
  struct queue ready;
  ready.front = -1;
  ready.rear = -1;

  for (int i = 0; i < n; i++) {
    p[i].pid = i + 1;
    p[i].ct = 0;
    printf("Please enter the burst time of Process %d:", (i + 1));
    scanf("%d", &p[i].bt);
    printf("\n");

    p[i].timeLeft = p[i].bt;  // Initialize timeLeft with burst time
    enqueue(&ready, &p[i]);   // Enqueue process using address of p[i]
  }

  findCT(&ready, qt);
  findWT(p, n);
  findTAT(p, n);

  printf("PID\tBurst\tCompletion_time\tWaiting\tTurnaround\n");
  for (int i = 0; i < n; i++) {
    printf("%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
  }

  printf("The average waiting time is: %f\n", findAvgWT(p, n));
  printf("The average turn around time is: %f\n", findAvgTAT(p, n));

  return 0;
}

