#include <stdio.h>

int main(void) {
    float height_inch, height_m;
    char name[20];

    // 按英寸输入
    printf("请输入你的姓名：");
    scanf("%s", name);
    printf("请输入你的身高（英寸）：");
    scanf("%f", &height_inch);

    // 英寸转英尺（1 英尺 = 12 英寸）
    float height_feet = height_inch / 12.0;
    printf("%s, you are %.3f feet tall\n", name, height_feet);

    // 按米输入（额外扩展）
    printf("请输入你的身高（米）：");
    scanf("%f", &height_m);
    // 米转英尺（1 米 ≈ 3.28084 英尺）
    height_feet = height_m * 3.28084;
    printf("%s, you are %.3f feet tall\n", name, height_feet);

    return 0;
}
/*
请输入你的姓名：LIUNIANIAN
请输入你的身高（英寸）：234
LIUNIANIAN, you are 19.500 feet tall
*/