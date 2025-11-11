#include <stdio.h>
int main(){
    int n,m;printf("Processes and resources: ");scanf("%d%d",&n,&m);
    int alloc[n][m],max[n][m],avail[m];
    printf("Allocation:\n");for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&alloc[i][j]);
    printf("Max:\n");for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&max[i][j]);
    printf("Available:\n");for(int i=0;i<m;i++)scanf("%d",&avail[i]);
    int f[n],ans[n],ind=0;for(int i=0;i<n;i++)f[i]=0;
    int need[n][m];for(int i=0;i<n;i++)for(int j=0;j<m;j++)need[i][j]=max[i][j]-alloc[i][j];
    for(int k=0;k<n;k++){for(int i=0;i<n;i++){if(f[i]==0){int flag=0;
        for(int j=0;j<m;j++)if(need[i][j]>avail[j]){flag=1;break;}
        if(flag==0){ans[ind++]=i;for(int y=0;y<m;y++)avail[y]+=alloc[i][y];f[i]=1;}
    }}}int safe=1;for(int i=0;i<n;i++)if(f[i]==0)safe=0;
    if(safe){printf("Safe sequence: ");for(int i=0;i<n;i++)printf("P%d ",ans[i]);}
    else printf("Unsafe state\n");
}
