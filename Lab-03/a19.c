// smallest number & the largest number

#include<stdio.h>

int main() {

    int n,min=0,max=0,minIndex=0,maxIndex=0;

    printf("Enter n: ");
    scanf("%d",&n);

    int arr[n];

    for(int i=0; i<sizeof(arr)/4;i++){
        printf("Enter Arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }
    min=arr[0];
    max=arr[0];

    for(int i=0; i<sizeof(arr)/4;i++){
        if(arr[i]>max){
            max = arr[i];
            maxIndex = i;
        }
        if(arr[i]<min){
            min = arr[i];
            minIndex = i;
        }
    }
    printf("Max: %d is at index: %d\n",max,maxIndex);
    printf("Min: %d is at index: %d\n",min,minIndex);

    
    return 0;
}