#include <stdio.h>
struct process{
int alloc[10],maxi[10],need[10],av[10];
int flag,executed;
}p[20];

int main(){
int n,r,i,j,k,available[10],count=0,newavailable[10];
printf("enter no of process:");
scanf("%d",&n);
printf("enter no of resources:");
scanf("%d",&r);

for (i=0;i<n;i++){
    printf("PROCESS %d\n",i+1);

    //reading maximum values
    for(j=0;j<r;j++){
        printf("enter Maximum resource value for resource %d:", j+1);
        scanf("%d",&p[i].maxi[j]);
    }

    //reading allocation process
    for(j=0;j<r;j++){
        printf("enter Allocation resource value for resource %d:",j+1);
        scanf("%d",&p[i].alloc[j]);
    }
}
printf("\n");

// reading available values
for(i=0;i<r;i++){
    printf("enter available value for resource %d:", i+1);
    scanf("%d",&available[i]);
}

//calculating need values
for(i=0;i<n;i++){
    for(j=0;j<r;j++){
        p[i].need[j]=p[i].maxi[j] - p[i].alloc[j];
    }
}

printf("\n\n");
i=0;

while(1) {
dothis:
    p[i].flag=0;
    for(j=0;j<r;j++){
        if (p[i].need[j]<=available[j]){             //comparing need with available
            p[i].flag++;

        }
        else{
            printf("Unsafe state for process %d\n\n",i+1);
            break;
        }
    }
    if(p[i].flag==r&&p[i].executed!=1){
            count++;
            p[i].executed=1;
        printf("safe state for process %d\n",i+1);
        printf("process %d is executed\n\n",i+1);
        for(k=0;k<r;k++){
            p[i].av[k]=available[k];               //allocating available values to each process
        }
        for(k=0;k<r;k++){
            newavailable[k]=available[k]+p[i].alloc[k];   // calculating new available values for next process
            available[k]=newavailable[k];
        }

    }
    if(count==n){                              //checking if all process executed
        break;
    }
i++;
    if(i==n&&count<n){
        for(k=0;k<n;k++){
            if(p[k].flag!=r){
                i=k;
                goto dothis;                     //condition to execute not executed process
            }
        }
    }
}

//printing table values

printf("PROCESS    ALLOCATION     MAXIMUM      NEED       AVAILABLE\n\n");
for(i=0;i<n;i++){
    printf("P %d\t  ",i+1);
    for(j=0;j<r;j++){
        printf("%d ",p[i].alloc[j]);
    }
    printf("\t  ");

    for(j=0;j<r;j++){
        printf("%d ",p[i].maxi[j]);
    }
    printf("\t  ");

    for(j=0;j<r;j++){
        printf("%d ",p[i].need[j]);
    }
    printf("\t  ");

    for(j=0;j<r;j++){
        printf("%d ",p[i].av[j]);
    }
    printf("\t  ");
    printf("\n");
}


}
