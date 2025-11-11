#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t p1 = fork();
	
	if(p1 == 0){
		sleep(1);
		printf("Inside Child Process, pid: %d\n", getpid());
	}else if(p1 > 0){
		printf("Inside Parent Process, pid: %d\n", getpid());
		exit(0);
	}else{
		printf("Child not created\n");
	}
	return 0;
}
