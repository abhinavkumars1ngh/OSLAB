#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>

struct process{
	int pid;
	int bt;
	int wt;
	int tat;
};
void rearrange(struct process[], int len);
void findWT(struct process p[], int numP);
void findTAT(struct process p[], int numP);
double findAvgWT(struct process p[], int n);
double findAvgTAT(struct process p[], int n);

int main(){
	int n;
	printf("Enter the number of processes to be made(should be greater than equal to 5):\n");
	scanf("%d", &n);
	
	struct process p[n];
	for(int i = 0; i < n; i++){
		p[i].pid = i+1;
		printf("Please enter the burst time of Process %d:",(i+1));
		scanf("%d",&p[i].bt);
		printf("\n");
	}
	
	rearrange(p, n);
	findWT(p, n);
	findTAT(p, n);
	
	printf("PID\tBurst\tWaiting\tTurnaround\n");
	for (int i = 0; i < n; i++) {
		printf("%d\t%d\t%d\t%d\n", p[i].pid, p[i].bt, p[i].wt, p[i].tat);
        }
        
	return 0;
}

void rearrange(struct process p[], int len){
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len-1; j++){
			if(p[j].bt > p[j+1].bt){
				struct process temp = p[j];
				p[j] = p[j+1];
				p[j+1]=temp;
			}
		}
	}
}

void findWT(struct process p[], int numP){
	int wait = 0;
	p[0].wt = 0;
	for(int i = 1; i < numP; i++){
		wait+=p[i-1].bt;
		p[i].wt = wait;
	}
}

void findTAT(struct process p[], int numP){
	for(int i = 0; i < numP; i++){
		p[i].tat = p[i].bt + p[i].wt;
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
