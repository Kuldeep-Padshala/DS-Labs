// merge two unsorted arrays

#include<stdio.h>

int main() {

    int n1,n2;

    printf("Enter n1: ");
    scanf("%d",&n1);
    int a1[n1];

    printf("Enter n2: ");
    scanf("%d",&n2);
    int a2[n2];

    for(int i=0; i<n1;i++){
        printf("Enter A1[%d]: ",i);
        scanf("%d",&a1[i]);
    }

    for(int i=0; i<n2;i++){
        printf("Enter A2[%d]: ",i);
        scanf("%d",&a2[i]);
    }

    int m[n1+n2];

    for(int i=0;i<(n1+n2);i++){
        if(i<n1){
            m[i] = a1[i];
        }
        else{
            m[i] = a2[i-n1];
        }
    }
    

    printf("New array: ");

        for(int j=0;j<n1+n2;j++){
            printf("%d ",m[j]);
        }
    return 0;
}