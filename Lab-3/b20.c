// array contains a duplicate number or not

#include<stdio.h>

int main() {

    int n,isDuplicate=0;

    printf("Enter n: ");
    scanf("%d",&n);

    int arr[n];

    for(int i=0; i<sizeof(arr)/4;i++){
        printf("Enter Arr[%d]: ",i);
        scanf("%d",&arr[i]);
    }

    for(int i=0;i<n-1;i++){

        for(int j=i+1;j<n;j++){

            if(arr[j] == arr[i]){
                isDuplicate = 1;
                break;
            }
        }
    }

    if(isDuplicate){
        printf("Yes, array contains duplicate number");
    }
    else{
        printf("No, array do not contains duplicate number");
    }
    

    
    return 0;
}