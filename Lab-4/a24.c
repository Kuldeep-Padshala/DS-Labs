// insert a number at a given location in an array

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
    printf("Enter position to insert the number (0 to %d): ", n);
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid position!\n");
        return 1;
    }

    
        int temp = arr[pos];
        int temp2;
        arr[pos] = num;

        for(int i=(pos+1);i<n+1;i++){    //also be done without temporary variable by iterating from n to pos+1
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