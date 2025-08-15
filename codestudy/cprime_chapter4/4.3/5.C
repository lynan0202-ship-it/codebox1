#include <stdio.h>

int main(void) {
    float speed_mbps, size_mb;
    printf("请输入下载速度（Mbps）：");
    scanf("%f", &speed_mbps);
    printf("请输入文件大小（MB）：");
    scanf("%f", &size_mb);

    // 计算：时间 = 大小(MB) * 8(位/字节) / 速度(Mbps)
    float time_sec = (size_mb * 8.0) / speed_mbps;
    printf("At %.2f megabits per second, a file of %.2f megabytes\n", speed_mbps, size_mb);
    printf("downloads in %.2f seconds\n", time_sec);

    return 0;
}
/*
请输入下载速度（Mbps）：8
请输入文件大小（MB）：245
At 8.00 megabits per second, a file of 245.00 megabytes
downloads in 245.00 seconds
*/