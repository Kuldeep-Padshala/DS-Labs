// WAP to sort the N names in an alphabetical order.

#include <stdio.h>
#include <string.h>

int main(){

    int n;
    printf("Enter number of names: ");
    scanf("%d", &n);
    char arr[n][100];

    for(int i=0; i<n;i++){
        printf("Enter Arr[%d]: ",i);
        scanf(" %[^\n]s", arr[i]);
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(strcasecmp(arr[i], arr[j]) > 0){   // case ignore karva mate
                char temp[100];
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }

    printf("Sorted names in alphabetical order:\n");
    for(int i=0;i<n;i++){
        printf("%s\n", arr[i]);
    }



    return 0;
}