#include<stdio.h>

int main() {

    int n, fact=1;

    printf("Enter n: ");
    scanf("%d",&n);

    if(n==0){
        fact = 1;
    }
    else{
        for(int i=1;i<=n;i++){
            fact = fact*i;
        }
    }
    printf("%d! = %d",n,fact);

    
    return 0;
}