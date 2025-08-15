/*show_pt.c--一两种方式显示float的值

#include <stdio.h>


int main(void) 
{
    
    float aboat =32000.0f;
    double abet=2.14e6;
    long double dip =5.32e-6L;

    printf("%f can be written %e\n",abet,abet);
    printf("%f can be written %e\n",aboat,aboat);
    printf("%lf can be written %e\n",dip,dip);

    return 0;
}

*/

#include <stdio.h>

int main(void) 
{
    float aboat = 32000.0f;       // 单精度浮点数
    double abet = 2.14e6;          // 双精度浮点数（默认科学计数法为double）
    long double dip = 5.32e-6L;    // 扩展精度浮点数

    // 修正：%f和%e用于double类型，匹配abet的double类型
    printf("%f can be written %e\n", abet, abet);
    
    // 修正：为float类型添加l修饰符（%f → %f），但printf会自动将float提升为double
    printf("%f can be written %e\n", aboat, aboat);
    
    // 修正：long double需要使用%Lf和%Le格式说明符
    printf("%Lf can be written %Le\n", dip, dip);

    float toobig =3.4E38 * 100.0f;
    printf("%e\n",toobig);

    return 0;
}