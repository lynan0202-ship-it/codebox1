#include <stdio.h>
int main() {
    double grams;
    // 水分子质量 
    const double WATER_MOLECULE_MASS = 3.0e-23; 
    // 1 夸脱水质量 
    const double QUART_WATER_MASS = 950; 
    printf("Enter the number of quarts of water: ");
    scanf("%lf", &grams);
    grams = grams * QUART_WATER_MASS;
    double molecules = grams / WATER_MOLECULE_MASS;
    printf("The number of water molecules: %e\n", molecules);
    return 0;
}