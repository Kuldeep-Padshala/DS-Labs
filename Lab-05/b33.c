// insert a number at a given location in an array             (method 1)

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


int main() {

    int n;
    printf("Enter number of names: ");
    scanf("%d", &n);
    char arr[n][100];

    for(int i=0; i<n; i++){
        printf("Enter Arr[%d]: ", i);
        scanf(" %[^\n]s", arr[i]);
    }

    srand(time(NULL)); 
    int random = rand() % n;

    printf("Random name: %s\n", arr[random]);

    printf("Enter its anagram: ");
    char anagram[100];
    scanf(" %[^\n]s", anagram);

    int len = strlen(arr[random]);
    int len2 = strlen(anagram);

    if(len != len2){
        printf("Word entered is not an anagram");
    }
    int sum = 0;

    for(int i=0;i<len;i++){

        for(int j=0;j<len;j++){
            
            //ignoring the case
            if(arr[random][i] == anagram[j] || arr[random][i] + 32 == anagram[j] || arr[random][i] - 32 == anagram[j]){
                anagram[j] = ' '; 
                sum++;
                break;
            }
            
        }
    }
    if(sum==len){
        printf("Word entered is an anagram of given Word\n");
    }

    else{
        printf("Word entered is not an anagram of given Word\n");
    }
    
    return 0;
}