#include <stdio.h>
#include <stdlib.h>

struct slot
{
    int val;
    int pr;
};

int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};
    struct slot slots[4];
    for (int i = 0; i < 4; i++)
    {
        slots[i].val = -1;
        slots[i].pr = 0;
    }
    int hit = 0;
    int miss = 0;
    int ind = 0;

    for (int i = 0; i < 14; i++)
    {
        int flag = 0;
        for (int j = 0; j < 4; j++)
        {
            if (pages[i] == slots[j].val)
            {
                hit++;
                flag = 1;
                ind++;
                slots[j].pr = ind;
                break;
            }
        }
        if (flag == 0)
        {
            int minVal = 999;
            int minind = -1;
            for (int k = 0; k < 4; k++)
            {
                if (slots[k].pr < minVal)
                {
                    minVal = slots[k].pr;
                    minind = k;
                }
            }
            slots[minind].val = pages[i];
            ind++;
            slots[minind].pr = ind;
            miss++;
        }
    }

    printf("LRU:\nHit: %d, Miss: %d\n", hit, miss);

    return 0;
}