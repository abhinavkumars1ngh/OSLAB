#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define SIZE 5
int buf[SIZE],in=0,out=0;
sem_t full,empty;
pthread_mutex_t m;

void* prod(void* arg){
    for(int i=1;i<=10;i++){
        sem_wait(&empty);
        pthread_mutex_lock(&m);
        buf[in]=i;in=(in+1)%SIZE;
        printf("Produced %d\n",i);
        pthread_mutex_unlock(&m);
        sem_post(&full);
        sleep(1);
    }return NULL;
}
void* cons(void* arg){
    for(int i=1;i<=10;i++){
        sem_wait(&full);
        pthread_mutex_lock(&m);
        int item=buf[out];out=(out+1)%SIZE;
        printf("Consumed %d\n",item);
        pthread_mutex_unlock(&m);
        sem_post(&empty);
        sleep(2);
    }return NULL;
}
int main(){
    pthread_t p,c;
    sem_init(&empty,0,SIZE);sem_init(&full,0,0);
    pthread_mutex_init(&m,NULL);
    pthread_create(&p,NULL,prod,NULL);
    pthread_create(&c,NULL,cons,NULL);
    pthread_join(p,NULL);pthread_join(c,NULL);
    sem_destroy(&empty);sem_destroy(&full);
    pthread_mutex_destroy(&m);
}
