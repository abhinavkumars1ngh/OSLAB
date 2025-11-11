#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

void *thread_function(void *arg){
	int thread_id = *(int *)arg;
	printf("Hello from thread %d\n", thread_id);
	pthread_exit(NULL);
}

int main(){
	pthread_t threads[NUM_THREADS];
	int thread_ids[NUM_THREADS];S
	int rc, i;

	for(int i = 0; i < NUM_THREADS; i++){
		thread_ids[i] = i;
		rc = pthread_create(&threads[i], NULL, thread_function, (void *)&thread_ids[i]);
		
		if(rc){
			printf("Error creating thread %d\n", i);
			exit(-1);
		}
	}
	
	for(int i = 0; i < NUM_THREADS; i++){
		rc = pthread_join(threads[i], NULL);
		
		if(rc){
			printf("Error joining thread %d\n", i);
			exit(-1);
		}
	}
	
	printf("All threads completed\n");
	return 0;
}
