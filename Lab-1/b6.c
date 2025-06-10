#include<stdio.h>

int main() {

    int h, m, s, sec;

    printf("Enter seconds:");
    scanf("%d",&sec);

    h = sec/3600;
    sec = sec - (h*3600);

    m = sec/60;
    sec = sec - (m*60);

    s = sec;

    printf("Time is %d:%d:%d\n", h, m, s);
    
    return 0;
}