// reverse a number

#include<stdio.h>

int main() {

    int n, rev = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    int m=n;

    while(n!=0){
        rev = rev*10 + n%10;
        n = n/10;
    }

    printf("Reversed of %d is %d",m ,rev);

    return 0;
}