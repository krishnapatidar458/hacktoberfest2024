#include <stdio.h>
#include <string.h>
#include <stdbool.h>


bool isPalindrome(const char *str) {
    int length = strlen(str);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return false; 
        }
    }
    return true;
}

int main() {
    char input[100];

    printf("Enter a string (up to 99 characters): ");
    scanf("%99s", input);

    if (isPalindrome(input)) {
        printf("%s is a palindrome.\n", input);
    } else {
        printf("%s is not a palindrome.\n", input);
    }

    return 0;
}
