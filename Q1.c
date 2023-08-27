#include <stdio.h>
#include <string.h>

void reverse(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

char *addLargeNumbers(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLength = (len1 > len2) ? len1 : len2;
    
    char result[maxLength + 1];
    int carry = 0;
    
    int i, j, k;
    for (i = len1 - 1, j = len2 - 1, k = 0; i >= 0 || j >= 0; i--, j--, k++) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        
        int sum = digit1 + digit2 + carry;
        result[k] = (sum % 10) + '0';
        carry = sum / 10;
    }
    
    if (carry)
        result[k++] = carry + '0';
    
    result[k] = '\0';
    
    reverse(result);
    
    char *finalResult = strdup(result);
    return finalResult;
}

int main() {
    char num1[1025], num2[1025];
    printf("Enter the first very large number: ");
    scanf("%s", num1);
    printf("Enter the second very large number: ");
    scanf("%s", num2);

    char *sum = addLargeNumbers(num1, num2);
    printf("Sum of the two numbers: %s\n", sum);
    
    return 0;
}
