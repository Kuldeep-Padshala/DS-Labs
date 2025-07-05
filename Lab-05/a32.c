// insert a number at a given location in an array

#include<stdio.h>

int main() {

    int m,n,x,y;
    printf("Enter number of rows and columns for matrix 1: \n");
    printf("m:");
    scanf("%d", &m);
    printf("n:");
    scanf("%d", &n);
    printf("Enter number of rows and columns for matrix 2: \n");
    printf("x:");
    scanf("%d", &x);
    printf("y:");
    scanf("%d", &y);

    if(m == 0 || n == 0 || x == 0 || y == 0) {
        printf("Matrix dimensions cannot be zero.\n");
        return 1;
    }

    if(n != x) {
        printf("Matrix multiplication not possible. Number of columns in first matrix must equal number of rows in second matrix.\n");
        return 1;
    }

    int arr1[m][n];
    int arr2[x][y];

    printf("Enter elements of Matrix 1:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            // printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr1[i][j]);
        }
    }

    printf("Enter elements of Matrix 2:\n");
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            // printf("Element [%d][%d]: ", i, j);
            scanf("%d", &arr2[i][j]);
        }
    }

    int res[m][y];

    for(int i=0;i<m;i++){
        for(int j=0;j<y;j++){
            res[i][j] = 0;
            for(int k=0;k<n;k++){
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }

    printf("Result of multiplication:\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<y;j++){
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}