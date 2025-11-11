#include <stdio.h>

// Function to check whether a page exists in a frame or not
int search(int key, int fr[], int fn)
{
    for (int i = 0; i < fn; i++)
        if (fr[i] == key)
            return i;
    return -1;
}

// Function to find the frame that will not be used recently in future after given index in pg[0..pn-1]
int predict(int pg[], int fr[], int pn, int fn, int index)
{
    // Store the index of pages which are going to be used recently in future
    int res = -1, farthest = index;
    for (int i = 0; i < fn; i++)
    {
        int j;
        for (j = index; j < pn; j++)
        {
            if (fr[i] == pg[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        // If a page is never referenced in future, return it.
        if (j == pn)
            return i;
    }
    // If all of the frames were not in future, return any of them, we return 0. Otherwise we return res.
    return (res == -1) ? 0 : res;
}

void optimalPage(int pg[], int pn, int fn)
{
    // Create an array for given number of frames and initialize it as empty.
    int fr[fn];
    for (int i = 0; i < fn; i++)
        fr[i] = -1;

    // Traverse through page reference array and check for miss and hit.
    int hit = 0;
    for (int i = 0; i < pn; i++)
    {
        // Page found in a frame: HIT
        int pos = search(pg[i], fr, fn);
        if (pos != -1)
        {
            hit++;
            continue;
        }

        // Page not found in a frame: MISS

        // If there is space available in frames.
        int j;
        for (j = 0; j < fn; j++)
        {
            if (fr[j] == -1)
            {
                fr[j] = pg[i];
                break;
            }
        }

        // If all frames are full, find the page to be replaced.
        if (j == fn)
        {
            int k = predict(pg, fr, pn, fn, i + 1);
            fr[k] = pg[i];
        }
    }
    printf("OPTIMAL:\nHit: %d, ", hit);
    printf("Miss: %d\n", pn - hit);
}

// Driver Function
int main()
{
    int pg[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int pn = sizeof(pg) / sizeof(pg[0]);
    int fn = 4;
    optimalPage(pg, pn, fn);
    return 0;
}
