#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

#define BUFFER_SIZE 10
#define READERS 3
#define WRITERS 2

struct sem
{
    int val;
};

struct sem mutex, wrt;
int read_count = 0;
int BUFFER[BUFFER_SIZE];
int it = 0;

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

void writer()
{
    wait(&wrt);
    BUFFER[it] = 1;
    it++;
    printf("Writer wrote item %d\n", it);
    signal(&wrt);
}

void reader()
{
    wait(&mutex);
    read_count++;
    if (read_count == 1)
    {
        wait(&wrt);
    }
    signal(&mutex);

    int read_item = BUFFER[it - 1];
    printf("Reader read item %d\n", read_item);

    wait(&mutex);
    read_count--;
    if (read_count == 0)
    {
        signal(&wrt);
    }
    signal(&mutex);
}

int main()
{
    mutex.val = 1;
    wrt.val = 1;

    for (int i = 0; i < READERS; i++)
    {
        if (fork() == 0)
        {
            reader();
            exit(0);
        }
    }

    for (int i = 0; i < WRITERS; i++)
    {
        if (fork() == 0)
        {
            writer();
            exit(0);
        }
    }

    // Wait for all child processes to finish (not done in this simplified example)
    // Wait calls would be added here

    return 0;
}
