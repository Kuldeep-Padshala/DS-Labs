#include<stdio.h>

int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {

    int a=1,b=1000;

    for(int n=a; n<=b; n++){

        int sum = 0, temp = n, digits = 0;

        while (temp != 0) {
            temp /= 10;
            digits++;
        }

        temp = n;
        while (temp != 0) {
            int digit = temp % 10;
            sum += power(digit, digits);
            temp /= 10;
        }
        if (sum == n) {
            printf("%d ", n);
        }
    
    }
    return 0;
}