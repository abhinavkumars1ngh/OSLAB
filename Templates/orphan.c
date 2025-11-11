#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
	pid_t p1 = fork();
	
	if(p1 == 0){
		sleep(1);
		printf("This is the Orphaned child, the ID is: %d\n", getpid());
	}
	else{
		printf("This is the Parent Process, the ID is: %d\n", getpid());
		exit(0);
	}
	return 0;
}
