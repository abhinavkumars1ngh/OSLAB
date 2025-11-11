#include <stdio.h>
#include <pthread.h>
#define N 5
int A[N]={1,2,3,4,5},B[N]={10,20,30,40,50},C[N];
void* add(void* arg){int i=*(int*)arg;C[i]=A[i]+B[i];return NULL;}
int main(){
    pthread_t t[N];int idx[N];
    for(int i=0;i<N;i++){idx[i]=i;pthread_create(&t[i],NULL,add,&idx[i]);}
    for(int i=0;i<N;i++)pthread_join(t[i],NULL);
    for(int i=0;i<N;i++)printf("%d ",C[i]);
    printf("\n");
}
