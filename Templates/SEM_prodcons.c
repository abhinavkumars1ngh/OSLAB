#include <stdio.h>
#include <stdlib.h>

int it = 0;
int BUFFER[10];

struct sem
{
    int val;
};

struct sem mutex, full, empty;

void wait(struct sem *s)
{
    s->val--;
    while (s->val < 0)
        ;
}

void signal(struct sem *s)
{
    s->val++;
}

void producer()
{
    wait(&mutex);
    signal(&full);
    wait(&empty);
    BUFFER[it] = 1;
    it++;
    printf("produced item %d", it);
    signal(&mutex);
}

void consumer()
{
    wait(&mutex);
    wait(&full);
    signal(&empty);
    BUFFER[it] = 0;
    printf("consumed item %d", it);
    it--;
    signal(&mutex);
}

int main()
{
    mutex.val = 1;
    full.val = 0;
    empty.val = 10;
    int k = 1;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");
    while (k == 1)
    {
        int n;
        printf("\nEnter your choice:");
        scanf("%d", &n);

        // Switch Cases
        switch (n)
        {
        case 1:
            if ((mutex.val == 1) && (empty.val != 0))
            {
                producer();
            }

            else
            {
                printf("Buffer is full!");
            }
            break;

        case 2:
            if ((mutex.val == 1) && (full.val != 0))
            {
                consumer();
            }

            else
            {
                printf("Buffer is empty!");
            }
            break;

        case 3:
            k = 0;
            break;
        }
    }
}