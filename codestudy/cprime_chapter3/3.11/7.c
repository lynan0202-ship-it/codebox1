#include <stdio.h>
int main() {
    double inches;
    printf("Enter your height in inches: ");
    scanf("%lf", &inches);
    // 1 英寸 = 2.54 厘米 
    printf("Your height in centimeters: %f\n", inches * 2.54); 
    return 0;
}
