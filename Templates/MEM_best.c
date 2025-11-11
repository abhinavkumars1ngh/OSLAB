#include <stdio.h>
#include <stdlib.h>
struct alloc
{
    int index;
    int array[100];
};
int main()
{
    int memoryloc[5] = {100, 500, 200, 300, 600};
    printf("Enter the number of input processes: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    struct alloc allocations[5];
    printf("Enter memory of each process: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    for (int i = 0; i < 5; i++)
        allocations[i].index = 0;
    for (int i = 0; i < n; i++)
    {
        // Find the best-fit memory block
        int bestFitBlock = -1;
        int minSize = 100000;
        for (int j = 0; j < 5; j++)
        {
            if (memoryloc[j] >= arr[i] && memoryloc[j] - arr[i] < minSize)
            {
                bestFitBlock = j;
                minSize = memoryloc[j] - arr[i];
            }
        }
        // Allocate memory to the best-fit block
        if (bestFitBlock != -1)
        {
            memoryloc[bestFitBlock] -= arr[i];
            allocations[bestFitBlock].array[allocations[bestFitBlock].index] =
                arr[i];
            allocations[bestFitBlock].index++;
        }
    }
    // Print the allocations
    for (int i = 0; i < 5; i++)
    {
        if (allocations[i].index > 0)
        {
            printf("Allocation to block %d: ", i);
            for (int j = 0; j < allocations[i].index; j++)
            {
                printf("%d, ", allocations[i].array[j]);
            }
            printf("\n");
        }
    }
    return 0;
}