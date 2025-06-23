// check whether the string is Palindrome or not using Pointer.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    
    char *c = (char *)malloc(100*sizeof(char));
    if(c == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter a string: ");
    scanf(" %[^\n]s", c);

    int len = strlen(c);
    int isPalindrome = 1;
    
    for(int i = 0; i < len / 2; i++) {
        if(c[i] != c[len - i - 1]) { // also use *(c + i) != *(c + len - i - 1)
            isPalindrome = 0;
            break;
        }
    }

    if(isPalindrome) {
        printf("The string is a palindrome.\n");
    } 
    else {
        printf("The string is not a palindrome.\n");
    }
    free(c);

}