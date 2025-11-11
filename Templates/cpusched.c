#include <stdio.h>

struct proc{int id,bt,wt,tat,prio;};

void calc(struct proc p[],int n){
    p[0].wt=0;
    for(int i=1;i<n;i++)p[i].wt=p[i-1].bt+p[i-1].wt;
    for(int i=0;i<n;i++)p[i].tat=p[i].wt+p[i].bt;
}

void sortbt(struct proc p[],int n){
    struct proc t;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(p[j].bt>p[j+1].bt){t=p[j];p[j]=p[j+1];p[j+1]=t;}
}

void sortprio(struct proc p[],int n){
    struct proc t;
    for(int i=0;i<n-1;i++)
        for(int j=0;j<n-i-1;j++)
            if(p[j].prio>p[j+1].prio){t=p[j];p[j]=p[j+1];p[j+1]=t;}
}

void rr(struct proc p[],int n,int q){
    int rem[n];for(int i=0;i<n;i++)rem[i]=p[i].bt;
    int t=0,done;
    while(1){
        done=1;
        for(int i=0;i<n;i++){
            if(rem[i]>0){
                done=0;
                if(rem[i]>q){t+=q;rem[i]-=q;}
                else{t+=rem[i];p[i].wt=t-p[i].bt;rem[i]=0;}
            }
        }
        if(done)break;
    }
    for(int i=0;i<n;i++)p[i].tat=p[i].bt+p[i].wt;
}

int main(){
    int n,ch,q;
    printf("Enter no of processes: ");scanf("%d",&n);
    struct proc p[n];
    for(int i=0;i<n;i++){
        p[i].id=i+1;
        printf("Enter BT and Priority for P%d: ",i+1);
        scanf("%d%d",&p[i].bt,&p[i].prio);
    }
    printf("1.FCFS 2.SJF 3.Priority 4.RR: ");scanf("%d",&ch);
    if(ch==2)sortbt(p,n);
    else if(ch==3)sortprio(p,n);
    if(ch==4){printf("Quantum: ");scanf("%d",&q);rr(p,n,q);}else calc(p,n);

    printf("\nPID\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++)printf("%d\t%d\t%d\t%d\n",p[i].id,p[i].bt,p[i].wt,p[i].tat);
}
