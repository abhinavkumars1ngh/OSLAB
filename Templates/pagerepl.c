#include <stdio.h>
int findLRU(int t[],int n){int m=t[0],p=0;for(int i=1;i<n;i++)if(t[i]<m){m=t[i];p=i;}return p;}
int main(){
    int n,f;printf("Pages and frames: ");scanf("%d%d",&n,&f);
    int p[n],fr[f],t[f],c=0,fault=0;
    for(int i=0;i<n;i++)scanf("%d",&p[i]);
    for(int i=0;i<f;i++)fr[i]=-1;
    for(int i=0;i<n;i++){
        int flag=0;for(int j=0;j<f;j++)if(fr[j]==p[i]){flag=1;t[j]=++c;}
        if(flag==0){int pos=-1;
            for(int j=0;j<f;j++)if(fr[j]==-1){pos=j;break;}
            if(pos==-1)pos=findLRU(t,f);
            fr[pos]=p[i];t[pos]=++c;fault++;
        }
        printf("\nFrame: ");for(int j=0;j<f;j++)if(fr[j]!=-1)printf("%d ",fr[j]);else printf("- ");
    }
    printf("\nPage Faults=%d\n",fault);
}
