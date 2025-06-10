#include<stdio.h>

int main() {

    int n;

    printf("Enter n: ");
    scanf("%d",&n);

    int arr[n][n];

    for(int i=0; i<n;i++){
        for(int j=0; j<=i;j++){
            if(i==j || j==0){
                arr[i][j]=1;
            }
            else{
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<=n-i-1;j++){
            printf(" ");
        }
        for(int k=0; k<=i;k++){
            printf("%d ",arr[i][k]);
        }
        printf("\n");
    }

    
    return 0;
}