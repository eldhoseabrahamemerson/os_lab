#include<stdio.h>
int main(){
    int n,m,i,j,k;
    printf("enter the number of processes: ");
    scanf("%d",&n);
    printf("enter the number of resources: ");
    scanf("%d",&m);
    int alloc[n][m],max[n][m],need[n][m],avail[m],finish[n],safe[n];
    printf("enter the allocation matrix: \n");
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                scanf("%d",&alloc[i][j]);
    }
}
printf("enter the max matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("enter the available resources: \n");
    for(i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    for(i=0;i<n;i++){
        finish[i]=0;
    }
    int count=0;
    while(count<n){
         int found=0;
         for(i=0;i<n;i++){
            if(finish[i]==0){
                for(j=0;j<m;j++){
                    if( need[i][j]>avail[j]){
                        break;
                    }
                }
                if(j==m){
                    for(k=0;k<m;k++){
                    avail[k]=avail[k]+alloc[i][k];
                    }
                    safe[count]=i;
                    count++;
                    found=1;
                    finish[i]=1;
                 }
            }
         }
         if(found==0){
            printf("no safe sequence\n");
            return 0;
         }
    }
    printf("safe sequence");
    for(i=0;i<n;i++){
        printf("P%d\t",safe[i]);
    }
    return 0;
}

