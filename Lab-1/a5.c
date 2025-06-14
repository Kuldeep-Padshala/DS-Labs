//leap year

#include<stdio.h>

int main() {

    int y;
    printf("Enter a year: ");
    scanf("%d", &y);

    if( (y%4 == 0 && y%100 != 0) || y%400 == 0 ) {
        printf("The year %d is a leap year.\n", y);
    } else {
        printf("The year %d is not a leap year.\n", y);
    }
    
    return 0;
}