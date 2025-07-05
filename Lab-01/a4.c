// largest among the given three

#include<stdio.h>

int main() {
    
    int a,b,c;
    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    printf("Enter c: ");
    scanf("%d", &c);

    (a>b) ? (a>c ? printf("The largest number is a = %d\n", a) : printf("The largest number is c = %d\n", c)) 
        : (b>c ? printf("The largest number is b = %d\n", b) : printf("The largest number is c = %d\n", c));
        

    
    return 0;
}