#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
	pid_t p1 = fork();
	pid_t p2 = fork();
	if(p2 == 0){
		sleep(1);
		printf("Inside Parent process, my ID is: %d\n", getpid());
	}else{
		printf("Inside Child process, my ID is: %d\n", getpid());
	}
	
	return 0;
}
