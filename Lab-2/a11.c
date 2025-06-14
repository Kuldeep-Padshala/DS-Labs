// factors of a given number

#include<stdio.h>

int main() {

    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Factorial is not defined for negative numbers.\n");
        return 1;
    }
    
    printf("Factors of %d are: ", n);

    for(int i=1; i<=n; i++){
        if(n%i==0){
            printf("%d ",i);
        }
    }
}