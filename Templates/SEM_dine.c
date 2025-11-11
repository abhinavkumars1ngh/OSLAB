#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 5 // Number of philosophers

enum State
{
    THINKING,
    HUNGRY,
    EATING
};

int state[N];          // State of each philosopher
int forks[N];          // Availability of forks (1 = available, 0 = in use)
int philosopher_id[N]; // IDs of philosophers

void printState()
{
    printf("Philosophers:\n");
    for (int i = 0; i < N; i++)
    {
        printf("Philosopher %d is ", i);
        switch (state[i])
        {
        case THINKING:
            printf("thinking\n");
            break;
        case HUNGRY:
            printf("hungry\n");
            break;
        case EATING:
            printf("eating\n");
            break;
        default:
            printf("unknown state\n");
        }
    }
    printf("\n");
}

void takeForks(int id)
{
    state[id] = HUNGRY;
    printState();
    if (state[id] == HUNGRY && state[(id + 1) % N] != EATING && state[(id + N - 1) % N] != EATING)
    {
        forks[id] = 0;
        forks[(id + 1) % N] = 0;
        state[id] = EATING;
        printState();
        printf("Philosopher %d picked up forks and is now eating\n", id);
    }
}

void putForks(int id)
{
    forks[id] = 1;
    forks[(id + 1) % N] = 1;
    state[id] = THINKING;
    printState();
    printf("Philosopher %d put down forks and is now thinking\n", id);
}

int main()
{
    for (int i = 0; i < N; i++)
    {
        state[i] = THINKING;
        forks[i] = 1;
        philosopher_id[i] = i;
    }

    int num_cycles = 3; // Number of cycles for the simulation
    for (int cycle = 0; cycle < num_cycles; cycle++)
    {
        printf("Cycle %d\n", cycle + 1);
        for (int i = 0; i < N; i++)
        {
            sleep(1); // Simulating time passing
            takeForks(i);
            sleep(1); // Simulating eating time
            putForks(i);
        }
    }

    return 0;
}
