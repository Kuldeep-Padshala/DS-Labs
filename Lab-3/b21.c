#include<stdio.h>

int main() {

    int n,a,b;

    printf("Enter n: ");
    scanf("%d",&n);

    int arr[n];

    for(int i=0; i<sizeof(arr)/4;i++){
        printf("Enter Arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    printf("Enter a: ");
    scanf("%d",&a);
    printf("Enter b: ");
    scanf("%d",&b);

    for(int i=0; i<sizeof(arr)/4;i++){
        if(a==arr[i]){
            arr[i] = b;
        }
    }
    for(int i=0; i<sizeof(arr)/4;i++){
        printf("%d ",arr[i]);
    }

    
    return 0;
}