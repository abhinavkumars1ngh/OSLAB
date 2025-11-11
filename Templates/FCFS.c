#include <stdio.h>
#include <stdlib.h>

struct process{
	int pid;
	//int at;
	int bt;
	int wt;
	int tat;
};

void findWT(struct process p[], int len);
void findTAT(struct process p[], int len);
float findAvgWT(struct process p[], int len);
float findAvgTAT(struct process p[], int len);

int main(){
	int n;
	printf("Enter the number of processes to be made(should be more than 5):\n");
	scanf("%d", &n);
	
	struct process p[n];
	for(int i = 0; i < n; i++){
		p[i].pid = i+1;
		printf("Please enter the burst times of Process %d:",(i+1));
		scanf("%d",&p[i].bt);
		printf("\n");
	}
	
	findWT(p, n);
	findTAT(p, n);
	
	printf("PID\tBurst\tWaiting\tTurnaround\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
        }

	printf("The average waiting time is: %f\n", findAvgWT(p, n));
	printf("The average turn around time is: %f\n", findAvgTAT(p, n));
	return 0;
}

void findWT(struct process p[], int len){
	int wait = 0;
	for(int i = 0; i < len; i++){
		p[i].wt = wait;
		wait += p[i].bt;
	}
}

void findTAT(struct process p[], int len){
	for(int i = 0; i < len; i++){
		p[i].tat = p[i].bt + p[i].wt;
	}
}

float findAvgWT(struct process p[], int len){
	int totalWait = 0;
	float avg = 0;
	
	for(int i = 0; i < len; i++){
		totalWait += p[i].wt;
	}
	
	avg = (totalWait*1.0)/len;
	return avg;	
}

float findAvgTAT(struct process p[], int len){
	int totalTAT = 0;
	float avg = 0;
	
	for(int i = 0; i < len; i++){
		totalTAT += p[i].tat;
	}
	
	avg = (totalTAT*1.0)/len;
	return avg;	
}
