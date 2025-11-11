#include <stdio.h>
#include <pthread.h>

#define ARRAY_SIZE 5

// Structure to hold the input arrays and result
typedef struct
{
    int *array1;
    int *array2;
    int *result;
    int start_index;
    int end_index;
} AddArrayParams;

// Function to add the arrays
void *addArrays(void *parameters)
{
    AddArrayParams *params = (AddArrayParams *)parameters;
    for (int i = params->start_index; i < params->end_index; i++)
    {
        params->result[i] = params->array1[i] + params->array2[i];
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[2];
    int array1[ARRAY_SIZE] = {1, 2, 3, 4, 5};
    int array2[ARRAY_SIZE] = {6, 7, 8, 9, 10};
    int result[ARRAY_SIZE];

    AddArrayParams params1 = {array1, array2, result, 0, ARRAY_SIZE / 2};
    AddArrayParams params2 = {array1, array2, result, ARRAY_SIZE / 2, ARRAY_SIZE};

    // Create threads to add the arrays
    pthread_create(&threads[0], NULL, addArrays, (void *)&params1);
    pthread_create(&threads[1], NULL, addArrays, (void *)&params2);

    // Wait for the threads to finish
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    // Output the result
    printf("The sum array is: ");
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}
