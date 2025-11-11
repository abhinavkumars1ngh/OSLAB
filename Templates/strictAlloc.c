#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 4

bool flag[NUM_THREADS] = {false, false, false, false};
int turn = 0;

void *process(void *id)
{
    int thread_id = *((int *)id);
    int other;
    if (thread_id == 0)
    {
        other = 1;
    }
    else if (thread_id == 1)
    {
        other = 2;
    }
    else if (thread_id == 2)
    {
        other = 3;
    }
    else
    {
        other = 0;
    }

    flag[thread_id] = true;
    turn = other;

    while (flag[other] && turn == other)
    {
    }

    // Critical section
    printf("Process %d is in its critical section\n", thread_id);

    // End of critical section
    flag[thread_id] = false;
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    int result_code;
    unsigned index;

    for (index = 0; index < NUM_THREADS; ++index)
    {
        thread_args[index] = index;
        result_code = pthread_create(&threads[index], NULL, process, &thread_args[index]);
        if (result_code != 0)
        {
            fprintf(stderr, "Thread creation failed: %d\n", result_code);
            exit(EXIT_FAILURE);
        }
    }

    for (index = 0; index < NUM_THREADS; ++index)
    {
        result_code = pthread_join(threads[index], NULL);
        if (result_code != 0)
        {
            fprintf(stderr, "Thread join failed: %d\n", result_code);
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}
