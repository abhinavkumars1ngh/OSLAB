#include <stdio.h>

int main()
{

    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    int slots[] = {-1, -1, -1, -1};
    int hit = 0;
    int miss = 0;
    int index = 0;

    for (int i = 0; i < 14; i++)
    {
        int flag = 0;
        for (int j = 0; j < 4; j++)
        {
            if (pages[i] == slots[j])
            {
                hit++;
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            slots[index] = pages[i];
            index = (index + 1) % 4;
            miss++;
        }
    }

    printf("FIFO:\nHit: %d, Miss: %d\n", hit, miss);

    return 0;
}