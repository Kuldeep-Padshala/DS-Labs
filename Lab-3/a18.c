#include<stdio.h>

int main() {

    int n,sum=0;

    printf("Enter n: ");
    scanf("%d",&n);

    int arr[n];
    arr[0] = 1;

    for(int i=1; i<sizeof(arr)/4;i++){
        arr[i] = arr[i-1]+1;
    }

    for(int i=0; i<sizeof(arr)/4;i++){
        sum += arr[i];
    }

    float avg = (float)sum/n;
    printf("Avg is %f",avg);

    
    return 0;
}