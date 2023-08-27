#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compareStrings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1 < len2)
        return -1;
    if (len1 > len2)
        return 1;

    for (int i = 0; i < len1; i++) {
        if (str1[i] < str2[i])
            return -1;
        if (str1[i] > str2[i])
            return 1;
    }

    return 0;
}

char *subtractStrings(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char *result = (char *)malloc((len1 + 1) * sizeof(char));

    int carry = 0;
    int i, j, k;
    for (i = len1 - 1, j = len2 - 1, k = 0; i >= 0; i--, j--, k++) {
        int digit1 = str1[i] - '0';
        int digit2 = (j >= 0) ? str2[j] - '0' : 0;

        int diff = digit1 - digit2 - carry;
        if (diff < 0) {
            diff += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        result[k] = diff + '0';
    }

    result[k] = '\0';
    for (int i = k - 1; i >= 0 && result[i] == '0'; i--)
        result[i] = '\0';

    return result;
}

char *divideLargeNumbers(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);

    if (compareStrings(num1, num2) < 0) {
        char *result = (char *)malloc(2 * sizeof(char));
        result[0] = '0';
        result[1] = '\0';
        return result;
    }

    char *quotient = (char *)malloc((len1 + 1) * sizeof(char));
    quotient[0] = '0';
    quotient[1] = '\0';

    char *remainder = (char *)malloc((len1 + 1) * sizeof(char));
    strcpy(remainder, num1);

    char *temp = (char *)malloc((len2 + 1) * sizeof(char));

    for (int i = len1 - len2; i >= 0; i--) {
        strcpy(temp, num2);
        for (int j = 0; j < i; j++) {
            strcat(temp, "0");
        }

        while (compareStrings(remainder, temp) >= 0) {
            char *sub = subtractStrings(remainder, temp);
            free(remainder);
            remainder = sub;

            int qLen = strlen(quotient);
            quotient[qLen] += 1;
        }
    }

    free(temp);
    free(remainder);

    return quotient;
}

int main() {
    char num1[1025], num2[1025];
    printf("Enter the dividend: ");
    scanf("%s", num1);
    printf("Enter the divisor: ");
    scanf("%s", num2);

    char *quotient = divideLargeNumbers(num1, num2);
    printf("Quotient of the division: %s\n", quotient);

    free(quotient);

    return 0;
}
