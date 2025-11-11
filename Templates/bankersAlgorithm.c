#include <stdio.h>

int main(){
	int numProcesses, numResources;
	printf("Enter the number of processes and resources:\n");
	scanf("%d %d", &numProcesses,&numResources);
	
	int alloc[numProcesses][numResources];
	int max[numProcesses][numResources];
	int avail[numResources];
	
	printf("Enter the allocation matrix:\n");	
	for(int i = 0; i < numProcesses; i++){
		for(int j = 0; j < numResources; j++){
			scanf("%d", &alloc[i][j]);
		}
	}
	
	printf("Enter the maximum requirement matrix:\n");
	for(int i = 0; i < numProcesses; i++){
		for(int j = 0; j < numResources; j++){
			scanf("%d", &max[i][j]);
		}
	}
	
	printf("Enter the available system resources:\n");
	for(int i = 0; i < numResources; i++){
		scanf("%d", &avail[i]);
	}
	
	int finish[numProcesses], ans[numProcesses], ind = 0;
	for(int i = 0; i < numProcesses; i++){
		finish[i] = 0;
	}
	
	int need[numProcesses][numResources];
	for(int i = 0; i < numProcesses; i++){
		for(int j = 0; j < numResources; j++){
			need[i][j] = max[i][j] - alloc[i][j];
		}
	}
	
	int y = 0;
	
	for(int i = 0; i < numProcesses; i++){
		for(int j = 0; j < numProcesses; j++){
			if(finish[j] == 0){
				int flag = 0;
				for(int k = 0; k < numResources; k++){
					if(need[j][k] > avail[k]){
						flag = 1;
						break;
					}
				}
				
				if(flag == 0){
					ans[ind++] = j;
					for(int l = 0; l < numResources; l++){
						avail[l] += alloc[j][l];
					}
					finish[j] = 1;
				}
			}
		}
	}
	
	int flag = 1;
	
	for(int i = 0; i < numProcesses; i++){
		if(finish[i] == 0){
			flag = 0;
			printf("The following system is not safe\n");
			break;
		}
	}
	
	if(flag == 1){
		printf("The need matrix:\n");
		
		for(int i = 0; i < numProcesses; i++){
			for(int j = 0; j < numResources; j++){
				printf("%d ", need[i][j]);
			}
			
			printf("\n");
		}
		
		printf("The following is the safe sequence\n");
		
		for(int i = 0; i < numProcesses - 1; i++){
			printf("P%d -> ", ans[i]);
		}
		
		printf("P%d\n", ans[numProcesses-1]);
	}
	
	return 0;
}
