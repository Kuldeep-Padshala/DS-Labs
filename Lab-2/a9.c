#include<stdio.h>

int main() {

    int a,b, ans = 1;

    printf("Enter a: ");
    scanf("%d",&a);

    printf("Enter b: ");
    scanf("%d",&b);

    for(int i=1; i<=b; i++){
        ans = ans*a;
    }
    printf("%d to the power %d = %d",a,b,ans);
    
    return 0;
}