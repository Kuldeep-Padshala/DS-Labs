#include<stdio.h>

int main() {

    int n, sum=0;
    printf("Enter n: ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++){

        for(int j=1; j<=i;j++){
            printf("%d+", j);
            sum = sum+j;
        }
        printf(" ");
    }

    printf("\b\b = %d\n", sum);

    return 0;
}