#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t p1 = fork();
	
	if(p1 == 0){
		printf("Inside Child Process, pid: %d\n", getpid());
		printf("Finished Execution\n");
	}else if(p1 > 0){
		sleep(2);
		printf("Inside Parent Process, pid: %d\n", getpid());
	}else{
		printf("Process not created\n");
	}
	
	return 0;
}
