#include<stdio.h>

int main() {

    int n,m,sum=0;

    printf("Enter m: ");
    scanf("%d",&m);

    printf("Enter n: ");
    scanf("%d",&n);

    int arr[n-m+1];
    arr[0] = m;
    arr[sizeof(arr)/4] = n;

    for(int i=1; i<sizeof(arr)/4;i++){
        arr[i] = arr[i-1]+1;
    }

    for(int i=0; i<sizeof(arr)/4;i++){
        sum += arr[i];
    }
    printf("Sum is %d",sum);

    
    return 0;
}