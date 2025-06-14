// area of a Circle

#include<stdio.h>
#define PI 3.14

int main() {
    
    int r;
    printf("Enter radius of circle: ");
    scanf("%d", &r);

    float area = PI * r * r;
    printf("Area of circle with radius %d is %.2f\n", r, area);
    
    return 0;
}