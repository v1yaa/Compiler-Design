#include <stdio.h>
#include <math.h>

int main() {
    int a = 10, b = 5, c = 2;
    int result;
	result = (a + b) * c; 
    printf("Result of (10 + 5) * 2 = %d\n", result);
	result = (int)pow(a, 2); 
    printf("Result of 10^2 = %d\n", result);
    result = a * b / c; 
    printf("Result of 10 * 5 / 2 = %d\n", result);
    result = a + b - c; 
    printf("Result of 10 + 5 - 2 = %d\n", result);
    return 0;
}
