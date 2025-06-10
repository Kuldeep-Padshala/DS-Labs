#include<stdio.h>

int main() {

    int a,b,flag=1;
    printf("Enter a: ");
    scanf("%d", &a);

    printf("Enter b: ");
    scanf("%d", &b);

    for(int n=a; n<=b; n++){

    if(n==1){
        continue;
    }
    
    if(n==2 || n==3){
        printf("%d ", n);
        continue;
    }
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            flag = 0;
        }
    }
    
    if(flag){
        printf("%d ", n);
    }
    flag =1;
    }
    return 0;
}