// perform addition of matrices into third matrix and print it

#include<stdio.h>

int main() {

    int n;
    printf("Enter number of rows and columns (2 for 2x2 matrix): ");
    scanf("%d", &n);

    int arr1[n][n];
    int arr2[n][n];

    printf("Enter elements of Matrix 1:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements of Matrix 2:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }

    int sum[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    printf("Sum of the two Matrices:\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    
    return 0;
}