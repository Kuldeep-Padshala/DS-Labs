// prime or not

#include<stdio.h>

int main() {

    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    if(n==1){
        printf("1 is not prime.\n");
        return 0;
    }
    if(n==2 || n==3){
        printf("%d is prime.\n", n);
        return 0;
    }
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            printf("%d is not prime.\n", n);
            return 0;
        }
    }
    printf("%d is prime.\n", n);

    return 0;
}