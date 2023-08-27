#include <stdio.h>
#include <math.h>

double power(double base, int exponent) {
    if (exponent == 0) {
        return 1.0;
    }

    double result = 1.0;
    int positiveExponent = (exponent > 0) ? exponent : -exponent;
    
    while (positiveExponent > 0) {
        if (positiveExponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        positiveExponent /= 2;
    }

    return (exponent > 0) ? result : 1.0 / result;
}

int main() {
    double base;
    int exponent;

    printf("Enter the base: ");
    scanf("%lf", &base);
    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    double result = power(base, exponent);
    printf("Result: %.6lf\n", result);

    return 0;
}
