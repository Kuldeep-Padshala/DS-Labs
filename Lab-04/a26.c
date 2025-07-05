// insert a number in an array that is already sorted in an ascending order

#include<stdio.h>

int main() {

    int n;

    printf("Enter n: ");
    scanf("%d",&n);

    int arr[100];

    for(int i=0; i<n;i++){
        printf("Enter Arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    printf("Enter a number to insert: ");
    int num;
    scanf("%d", &num);
    int pos;

    for(int i=0;i<n;i++){
        if(num>arr[i]){
            pos = i+1;
        }
    }


    int temp = arr[pos];
        int temp2;
        arr[pos] = num;

        for(int i=(pos+1);i<n+1;i++){
            temp2 = arr[i];
            arr[i] = temp;
            temp = temp2;
            temp2 = arr[i+1];
        }
        printf("New array: ");
        for(int j=0;j<n+1;j++){
            printf("%d ",arr[j]);
        }

    return 0;
}