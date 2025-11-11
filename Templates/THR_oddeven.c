#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_odd_numbers(void *arg)
{
    int n = *(int *)arg;
    for (int i = 1; i <= 2 * n; i += 2)
    {
        printf("%d ", i);
    }
    pthread_exit(NULL);
}

void *print_even_numbers(void *arg)
{
    int n = *(int *)arg;
    for (int i = 2; i <= 2 * n; i += 2)
    {
        printf("%d ", i);
    }
    pthread_exit(NULL);
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    pthread_t odd_thread, even_thread;

    pthread_create(&odd_thread, NULL, print_odd_numbers, &n);
    pthread_create(&even_thread, NULL, print_even_numbers, &n);

    pthread_join(odd_thread, NULL);
    pthread_join(even_thread, NULL);

    printf("\n");

    return 0;
}
