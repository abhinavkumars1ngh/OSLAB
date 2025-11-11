#include <stdio.h>
void allocate(int blk[],int m,int proc[],int n,int t){
    int alloc[n];for(int i=0;i<n;i++)alloc[i]=-1;
    for(int i=0;i<n;i++){
        int best=-1;
        for(int j=0;j<m;j++){
            if(blk[j]>=proc[i]){
                if(t==1&&best==-1)best=j;
                else if(t==2&&(best==-1||blk[j]<blk[best]))best=j;
                else if(t==3&&(best==-1||blk[j]>blk[best]))best=j;
            }
        }
        if(best!=-1){alloc[i]=best;blk[best]-=proc[i];}
    }
    printf("Process\tSize\tBlock\n");
    for(int i=0;i<n;i++){printf("P%d\t%d\t",i+1,proc[i]);
        if(alloc[i]!=-1)printf("%d\n",alloc[i]+1);else printf("Not Allocated\n");}
}
int main(){
    int m,n,ch;printf("Blocks: ");scanf("%d",&m);
    int blk[m];for(int i=0;i<m;i++)scanf("%d",&blk[i]);
    printf("Processes: ");scanf("%d",&n);
    int proc[n];for(int i=0;i<n;i++)scanf("%d",&proc[i]);
    printf("1.First 2.Best 3.Worst: ");scanf("%d",&ch);
    allocate(blk,m,proc,n,ch);
}
