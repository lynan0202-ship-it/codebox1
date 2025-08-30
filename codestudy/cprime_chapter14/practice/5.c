// ------------------------------
// 题干：编写一个程序满足下面的要求。
// a. 外部定义一个有两个成员的结构模板name：一个字符串储存名，一个字符串储存姓。
// b. 外部定义一个有3个成员的结构模板student：一个name类型的结构，一个grade数组储存3个浮点型分数，一个变量储存3个分数平均数。
// c. 在main()函数中声明一个内含CSIZE（CSIZE = 4）个student类型结构的数组，并初始化这些结构的名字部分。用函数执行d、e、f和g中描述的任务。
// d. 以交互的方式获取每个学生的成绩，提示用户输入学生的姓名和分数。把分数储存到grade数组相应的结构中。可以在main()函数或其他函数中用循环来完成。
// e. 计算每个结构的平均分，并把计算后的值赋给合适的成员。
// f. 打印每个结构的信息。
// g. 打印班级的平均分，即所有结构的数值成员的平均值。
// 知识要点：
//  1. 结构体的定义与嵌套使用（name结构体被student结构体嵌套）
//  2. 数组的定义与使用（student数组、grade数组）
//  3. 函数的定义与调用（用于输入成绩、计算平均分、打印信息等）
//  4. 输入输出操作（scanf、printf的使用）
//  5. 循环结构（for循环处理多个学生和多个分数）
// 总体逻辑：
//  1. 定义结构体name和student，以及常量CSIZE表示学生数量。
//  2. 在main函数中，定义student数组并初始化每个学生的姓名部分。
//  3. 调用inputGrades函数，通过循环让用户输入每个学生的3门成绩。
//  4. 调用calculateAverages函数，计算每个学生的3门成绩平均分，存入对应成员。
//  5. 调用printStudents函数，打印每个学生的姓名、各科成绩和平均分。
//  6. 调用calculateClassAverage函数，计算并打印整个班级所有科目的平均分。
#include <stdio.h>

// 定义结构模板name，包含“名”和“姓”两个字符串成员
struct name {
    char first[20];  // 用于储存“名”的字符串数组
    char last[20];   // 用于储存“姓”的字符串数组
};

// 定义结构模板student，包含name结构、成绩数组、平均分
struct student {
    struct name fullname;     // 嵌套name结构，存储学生姓名
    float grade[3];           // 存储3门浮点型成绩的数组
    float average;            // 存储3门成绩的平均分
};

#define CSIZE 4  // 宏定义，指定学生数量为4

// 函数声明（提前说明函数的作用，方便main中调用）
// 输入学生成绩的函数
void inputGrades(struct student students[], int n);
// 计算每个学生平均分的函数
void calculateAverages(struct student students[], int n);
// 打印所有学生信息的函数
void printStudents(struct student students[], int n);
// 计算班级平均分的函数
float calculateClassAverage(struct student students[], int n);

int main() {
    // 定义student数组，并初始化每个学生的“姓名”部分
    struct student students[CSIZE] = {
        {{"Zhang", "San"}},    // 第一个学生：名Zhang，姓San
        {{"Li", "Si"}},        // 第二个学生：名Li，姓Si
        {{"Wang", "Wu"}},      // 第三个学生：名Wang，姓Wu
        {{"Zhao", "Liu"}}      // 第四个学生：名Zhao，姓Liu
    };

    // 步骤1：调用函数，输入每个学生的3门成绩
    inputGrades(students, CSIZE);

    // 步骤2：调用函数，计算每个学生的平均分
    calculateAverages(students, CSIZE);

    // 步骤3：调用函数，打印每个学生的详细信息
    printStudents(students, CSIZE);

    // 步骤4：调用函数计算班级平均分，并打印结果
    float classAvg = calculateClassAverage(students, CSIZE);
    printf("班级的平均分是：%.2f\n", classAvg);

    return 0;  // 程序正常结束
}

// 函数定义：输入每个学生的3门成绩
void inputGrades(struct student students[], int n) {
    for (int i = 0; i < n; i++) {  // 循环处理每个学生
        printf("请输入学生 %s %s 的3门成绩：\n", 
               students[i].fullname.first, students[i].fullname.last);
        for (int j = 0; j < 3; j++) {  // 循环处理该学生的3门成绩
            printf("科目 %d 的成绩：", j + 1);  // 提示输入第j+1门成绩
            scanf("%f", &students[i].grade[j]);  // 将输入的成绩存入对应数组元素
        }
    }
}

// 函数定义：计算每个学生的3门成绩平均分
void calculateAverages(struct student students[], int n) {
    for (int i = 0; i < n; i++) {  // 循环处理每个学生
        float sum = 0;  // 用于累加该学生3门成绩的变量
        for (int j = 0; j < 3; j++) {  // 循环累加3门成绩
            sum += students[i].grade[j];
        }
        students[i].average = sum / 3;  // 计算平均分，存入average成员
    }
}

// 函数定义：打印每个学生的姓名、各科成绩、平均分
void printStudents(struct student students[], int n) {
    for (int i = 0; i < n; i++) {  // 循环处理每个学生
        printf("学生：%s %s\n", students[i].fullname.first, students[i].fullname.last);
        printf("  各科成绩：");
        for (int j = 0; j < 3; j++) {  // 循环打印3门成绩
            printf("%.2f ", students[i].grade[j]);
        }
        printf("\n  平均分：%.2f\n", students[i].average);  // 打印该学生的平均分
    }
}

// 函数定义：计算班级所有科目的平均分（所有学生的所有成绩的平均值）
float calculateClassAverage(struct student students[], int n) {
    float total = 0;  // 用于累加所有成绩的变量
    int count = 0;    // 用于统计科目总数的变量
    for (int i = 0; i < n; i++) {  // 循环处理每个学生
        for (int j = 0; j < 3; j++) {  // 循环处理该学生的3门成绩
            total += students[i].grade[j];  // 累加当前成绩
            count++;  // 科目数加1
        }
    }
    return total / count;  // 返回所有成绩的平均分
}

// 测试验证方案：
//  1. 怎么运行：将代码保存为student.c，用gcc编译（如：gcc student.c -o student），然后运行生成的student可执行文件。
//  2. 预期结果：程序会依次提示输入4个学生的3门成绩（共12个成绩），然后打印每个学生的“姓名+各科成绩+个人平均分”，最后打印“班级所有科目的平均分”。
//  3. 检查点：
//     - 输入成绩后，打印的“个人各科成绩”是否和输入一致。
//     - 打印的“个人平均分”是否是该学生3门成绩的正确平均值（可手动计算验证）。
//     - 打印的“班级平均分”是否是所有12门成绩的正确平均值（可手动累加所有成绩后除以12验证）。
// 易错点提醒：
//  1. scanf输入成绩时，容易忘记写&取地址符（如写成scanf("%f", students[i].grade[j])，正确是&students[i].grade[j]），导致输入失败。
//  2. 计算班级平均分时，容易错误统计科目数量（比如误算成“学生数量”而不是“学生数×科目数”）。
//  3. 结构体嵌套访问时，容易写错成员名（如把fullname.first写成fullname_first）。
// 拓展思考：
//  1. 如果科目数量不是3门，如何修改？可以把科目数量也定义为宏（如#define GRADE_NUM 3），然后代码中所有“3”都替换为GRADE_NUM，这样修改宏值即可支持不同科目数。
//  2. 如何从文件读取成绩而不是手动输入？可以修改inputGrades函数，使用fopen打开文件，用fscanf读取数据。
//  3. 结构体传递方式对比：本代码中函数参数是结构体数组（本质是指针传递），所以函数内修改数组元素会影响main中的数组；如果是传递单个结构体变量，默认是“值传递”（拷贝一份），函数内修改不影响原变量；若要修改原变量，需传递“结构体指针”（指针传递）。