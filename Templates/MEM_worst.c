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
        // Find the worst-fit memory block
        int worstFitBlock = -1;
        int maxSize = -100000;
        for (int j = 0; j < 5; j++)
        {
            if (memoryloc[j] >= arr[i] && memoryloc[j] > maxSize)
            {
                worstFitBlock = j;
                maxSize = memoryloc[j];
            }
        }
        // Allocate memory to the worst-fit block
        if (worstFitBlock != -1)
        {
            memoryloc[worstFitBlock] -= arr[i];
            allocations[worstFitBlock].array[allocations[worstFitBlock].index] =
                arr[i];
            allocations[worstFitBlock].index++;
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