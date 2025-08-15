#include <stdio.h>
int main() {
    double cups;
    printf("Enter the number of cups: ");
    scanf("%lf", &cups);
    
    double pints = cups / 2;
    double gills = cups * 4;
    double tablespoons = cups * 16;
    double teaspoons = cups * 48;
    
    printf("Pints: %f\n", pints);
    printf("Gills: %f\n", gills);
    printf("Tablespoons: %f\n", tablespoons);
    printf("Teaspoons: %f\n", teaspoons);
    
    // 使用浮点类型是因为转换结果可能不是整数，用整数可能丢失精度 
    return 0;
}