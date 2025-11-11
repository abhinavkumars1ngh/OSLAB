#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t p1 = fork();
	
	if(p1 == 0){
		printf("This is the child process, the id is: %d\nFinished Execution in child!\n", getpid());
	}else{
		sleep(2);
		printf("This is the parent process, the id is: %d\n", getpid());
	}
	
	return 0;
}
