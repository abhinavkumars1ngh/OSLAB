#include <stdio.h>
#include <pthread.h>

// Structure to hold the input values and result
typedef struct
{
    int value1;
    int value2;
    int result;
} AddParams;

// Function to add the values
void *addValues(void *parameters)
{
    AddParams *params = (AddParams *)parameters;
    params->result = params->value1 + params->value2;
    pthread_exit(NULL);
}

int main()
{
    pthread_t thread;
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    AddParams params = {a, b, 0}; // Initialize input values and result

    // Create a thread to add the values
    pthread_create(&thread, NULL, addValues, (void *)&params);

    // Wait for the thread to finish
    pthread_join(thread, NULL);

    // Output the result
    printf("The sum is: %d\n", params.result);

    return 0;
}
