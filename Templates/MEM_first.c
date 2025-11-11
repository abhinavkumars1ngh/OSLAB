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
    printf("Enter the no of input processes: ");
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
        for (int j = 0; j < 5; j++)
        {
            if (memoryloc[j] >= arr[i] && arr[i] != -1)
            {
                memoryloc[j] -= arr[i];
                allocations[j].array[allocations[j].index] = arr[i];
                arr[i] = -1;
                allocations[j].index++;
            }
        }
    }
    for (int i = 0; i < 5; i++)
    {
        if (allocations[i].index > 0)
        {
            printf("Allocation to block %d ", i);
            for (int j = 0; j < allocations[i].index; j++)
            {
                printf("%d, ", allocations[i].array[j]);
            }
            printf("\n");
        }
    }
    return 0;
}