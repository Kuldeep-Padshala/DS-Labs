// factorial of a number

#include<stdio.h>

int factorial(int n){

    if(n==0){
        return 1;
    }

    return n*factorial(n-1);
}

int main() {

    int n, fact=1;

    printf("Enter n: ");
    scanf("%d",&n);

    // if(n==0){
    //     fact = 1;
    // }
    // else{
    //     for(int i=1;i<=n;i++){
    //         fact = fact*i;
    //     }
    // }
    // printf("%d! = %d",n,fact);

    fact = factorial(n);
    printf("%d! = %d",n,fact);

    
    return 0;
}