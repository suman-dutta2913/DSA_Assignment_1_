#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverse(char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

char *multiplyLargeNumbers(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int resultLength = len1 + len2;
    
    int *result = (int *)calloc(resultLength, sizeof(int));
    
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = result[i + j + 1] + mul;
            
            result[i + j] += sum / 10;
            result[i + j + 1] = sum % 10;
        }
    }
    
    char *finalResult = (char *)malloc((resultLength + 1) * sizeof(char));
    int index = 0;
    int i = 0;
    while (i < resultLength && result[i] == 0) i++;
    while (i < resultLength) finalResult[index++] = result[i++] + '0';
    finalResult[index] = '\0';
    
    if (index == 0) {
        finalResult[0] = '0';
        finalResult[1] = '\0';
    }
    
    free(result);
    reverse(finalResult);
    
    return finalResult;
}

int main() {
    char num1[1025], num2[1025];
    printf("Enter the first very large number: ");
    scanf("%s", num1);
    printf("Enter the second very large number: ");
    scanf("%s", num2);

    char *product = multiplyLargeNumbers(num1, num2);
    printf("Product of the two numbers: %s\n", product);

    free(product);
    
    return 0;
}
