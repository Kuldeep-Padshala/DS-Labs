// character is vowel or not.

#include<stdio.h>

int main() {
    
    char c;
    printf("Enter a character: ");
    scanf(" %c", &c);

    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' ||
       c=='A' || c=='E' || c=='I' || c=='O' || c=='U') {
        printf("The character '%c' is a vowel.\n", c);
    } else {
        printf("The character '%c' is a consonant.\n", c);
    }
    
    return 0;
}