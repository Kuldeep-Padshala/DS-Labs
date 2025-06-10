#include<stdio.h>

int main() {

    int y, w, d, days;

    printf("Enter seconds:");
    scanf("%d",&days);

    y = days/365;
    days = days - (y*365);

    w = days/7;
    days = days - (w*7);

    d = days;

    printf("Time is %d years, %d weeks, %d days\n", y, w, d);
    
    return 0;
}