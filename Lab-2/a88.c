#include<stdio.h>


int factorial(int n){

    if(n==0){
        return 1;
    }

    return n*factorial(n-1);
}

int main() {

    int n, fact;

    printf("Enter n: ");
    scanf("%d",&n);

    fact = factorial(n);
    printf("%d! = %d",n,fact);
    
    return 0;
}