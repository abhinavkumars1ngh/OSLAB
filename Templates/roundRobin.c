#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

struct process{
	int pid;
	int ct;
	int bt;
	int timeLeft;
	int wt;
	int tat;
};

struct queue{
   struct process q[100]; 
   int front; 
   int rear; 
};

struct process null= {0,0,0,0,0,0};

void enqueue(struct process element, struct queue q1) {
    if ((q1.rear + 1) % 100 == q1.front) { 
        printf("Queue is full");
        return;
    }
    if (q1.front == -1) {
        q1.front = 0;
    }
    q1.rear = (q1.rear + 1) % 100; 
    q1.q[q1.rear] = element;
}

struct process dequeue(struct queue q1) {
    if (q1.front == -1) { 
        return null;
    }
    struct process element = q1.q[q1.front];
    q1.front = (q1.front + 1) % 100; 
    if (q1.front > q1.rear) { 
        q1.front = -1;
        q1.rear = -1;
    }
    return element;
}

void findCT(struct queue ready, int qt);
void findWT(struct process p[], int numP);
void findTAT(struct process p[], int numP);
double findAvgWT(struct process p[], int n);
double findAvgTAT(struct process p[], int n);

int main(){
	int n;
	printf("Enter the number of processes to be made(minimum 5):\n");
	scanf("%d", &n);
	
	int qt;
	printf("Enter the value of time quantum:\n");
	scanf("%d", &qt);
	
	struct process p[n];
	struct queue ready;
	ready.front = -1;
	ready.rear = -1;
	
	for(int i = 0; i < n; i++){
		p[i].pid = i+1;
		p[i].ct = 0;
		printf("Please enter the burst time of Process %d:",(i+1));
		scanf("%d",&p[i].bt);
		printf("\n");
		
		p[i].ct = p[i].bt;
		enqueue(p[i], ready);
	}
	findCT(ready, qt);
	findWT(p, n);
	findTAT(p, n);
	
	printf("PID\tBurst\tCompletion_time\tWaiting\tTurnaround\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t\t%d\t%d\n", p[i].pid, p[i].bt,p[i].ct, p[i].wt, p[i].tat);
        }
        
        printf("The average waiting time is: %f\n", findAvgWT(p, n));
	printf("The average turn around time is: %f\n", findAvgTAT(p, n));
	return 0;
}

void findCT(struct queue ready, int qt){
	int curr = 0;
	while(ready->front != -1){
		struct process deque = dequeue(ready);
		if(deque.timeLeft >= qt){
			curr+=qt;
			deque.ct = curr;
			deque.timeLeft -= qt;
			enqueue(deque, ready);
		}else{
			curr += deque.timeLeft;
			deque.ct = curr;
			deque.timeLeft = 0;
		}
	}
}

void findWT(struct process p[], int numP){
	for(int i = 0; i < numP; i++){
		p[i].wt = p[i].ct-p[i].bt;
	}
}

void findTAT(struct process p[], int numP){
	for(int i = 0; i < numP; i++){
		p[i].tat = p[i].ct;
	}
}

double findAvgWT(struct process p[], int n){
	float total=0;
	for(int i = 0; i < n; i++){
		total += p[i].wt;
	}
	
	return total/n;
}

double findAvgTAT(struct process p[], int n){
	float total=0;
	for(int i = 0; i < n; i++){
		total += p[i].tat;
	}
	
	return total/n;
}
