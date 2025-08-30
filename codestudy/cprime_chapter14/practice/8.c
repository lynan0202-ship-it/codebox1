// ------------------------------
// 题干：巨人航空公司的机群由 12 个座位的飞机组成。它每天飞行一个航班。根据下面的要求，编写一个座位预订程序。
// a. 该程序使用一个内含 12 个结构的数组。每个结构中包括：一个成员表示座位编号、一个成员表示座位是否已被预订、一个成员表示预订人的名、一个成员表示预订人的姓。
// b. 该程序显示下面的菜单：
// To choose a function, enter its letter label:
// a) Show number of empty seats
// b) Show list of empty seats
// c) Show alphabetical list of seats
// d) Assign a customer to a seat assignment
// e) Delete a seat assignment
// f) Quit
// c. 该程序能成功执行上面给出的菜单。选择 d)和 e)要提示用户进行额外输入，每个选项都能让用户中止输入。
// d. 执行特定程序后，该程序再次显示菜单，除非用户选择 f)。
// 知识要点：
//  1. 结构体的定义与数组使用 - 封装座位多类信息并批量管理
//  2. 循环结构（do-while） - 实现菜单重复显示与功能循环执行
//  3. 分支结构（switch-case） - 根据用户选择执行不同功能
//  4. 字符串操作（输入、复制、比较） - 处理预订人姓名与排序
//  5. 用户交互处理 - 获取输入并反馈操作结果
// 总体逻辑：
//  1. 定义包含座位号、预订状态、预订人姓名的结构体，初始化12个座位的结构体数组（座位号1-12，初始未预订，姓名为空）
//  2. 用do-while循环重复显示菜单，直到用户选"f"退出
//  3. 根据用户输入的选项（a-f）执行对应功能：统计空座位、显示空座位列表、按姓氏字母序显示座位、分配座位、删除预订、退出
#include <stdio.h>
#include <string.h>

// 定义座位结构体，包含座位编号、预订状态、预订人姓名
typedef struct {
    int seatNum;          // 座位编号（1-12）
    int isReserved;       // 是否预订：0=未预订，1=已预订
    char firstName[50];   // 预订人名
    char lastName[50];    // 预订人姓
} Seat;

int main() {
    // 初始化12个座位的结构体数组
    Seat seats[12];
    for (int i = 0; i < 12; i++) {
        seats[i].seatNum = i + 1;       // 座位号从1到12
        seats[i].isReserved = 0;        // 初始状态：未预订
        strcpy(seats[i].firstName, ""); // 初始姓名为空字符串
        strcpy(seats[i].lastName, "");
    }

    char choice; // 存储用户选择的菜单选项
    do {
        // 显示菜单
        printf("\nTo choose a function, enter its letter label:\n");
        printf("a) Show number of empty seats\n");
        printf("b) Show list of empty seats\n");
        printf("c) Show alphabetical list of seats\n");
        printf("d) Assign a customer to a seat assignment\n");
        printf("e) Delete a seat assignment\n");
        printf("f) Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice); // 加空格跳过输入前的空白符（如换行）

        switch (choice) {
            case 'a': { // 显示空座位数量
                int emptyCount = 0;
                for (int i = 0; i < 12; i++) {
                    if (seats[i].isReserved == 0) {
                        emptyCount++;
                    }
                }
                printf("Number of empty seats: %d\n", emptyCount);
                break;
            }
            case 'b': { // 显示空座位编号列表
                printf("Empty seats: ");
                int hasEmpty = 0; // 标记是否有空座位
                for (int i = 0; i < 12; i++) {
                    if (seats[i].isReserved == 0) {
                        printf("%d ", seats[i].seatNum);
                        hasEmpty = 1;
                    }
                }
                if (!hasEmpty) { // 没有空座位时的提示
                    printf("None");
                }
                printf("\n");
                break;
            }
            case 'c': { // 按姓氏字母序显示所有座位（用冒泡排序）
                Seat temp;
                // 冒泡排序：按lastName的字母顺序升序排列
                for (int i = 0; i < 11; i++) {
                    for (int j = 0; j < 11 - i; j++) {
                        if (strcmp(seats[j].lastName, seats[j + 1].lastName) > 0) {
                            temp = seats[j];
                            seats[j] = seats[j + 1];
                            seats[j + 1] = temp;
                        }
                    }
                }
                // 显示排序后的座位信息
                printf("Seats (alphabetical by last name):\n");
                printf("Seat #\tFirst Name\tLast Name\tStatus\n");
                for (int i = 0; i < 12; i++) {
                    printf("%d\t%s\t\t%s\t\t%s\n", 
                           seats[i].seatNum, 
                           seats[i].firstName, 
                           seats[i].lastName, 
                           seats[i].isReserved ? "Reserved" : "Empty");
                }
                // 恢复座位号的原始顺序（排序会打乱，避免影响后续操作）
                for (int i = 0; i < 12; i++) {
                    seats[i].seatNum = i + 1;
                }
                break;
            }
            case 'd': { // 分配座位给用户
                int seatNum;
                char fName[50], lName[50];
                printf("Enter seat number (1-12, enter 0 to cancel): ");
                scanf("%d", &seatNum);
                if (seatNum == 0) { // 用户选择取消分配
                    printf("Assignment canceled.\n");
                    break;
                }
                if (seatNum < 1 || seatNum > 12) { // 座位号无效
                    printf("Invalid seat number!\n");
                    break;
                }
                if (seats[seatNum - 1].isReserved) { // 座位已被预订
                    printf("Seat %d is already reserved.\n", seatNum);
                    break;
                }
                printf("Enter first name: ");
                scanf("%s", fName);
                printf("Enter last name: ");
                scanf("%s", lName);
                // 分配座位：标记为已预订，记录姓名
                seats[seatNum - 1].isReserved = 1;
                strcpy(seats[seatNum - 1].firstName, fName);
                strcpy(seats[seatNum - 1].lastName, lName);
                printf("Seat %d assigned to %s %s.\n", seatNum, fName, lName);
                break;
            }
            case 'e': { // 删除座位预订
                int seatNum;
                printf("Enter seat number to delete (1-12, enter 0 to cancel): ");
                scanf("%d", &seatNum);
                if (seatNum == 0) { // 用户选择取消删除
                    printf("Deletion canceled.\n");
                    break;
                }
                if (seatNum < 1 || seatNum > 12) { // 座位号无效
                    printf("Invalid seat number!\n");
                    break;
                }
                if (!seats[seatNum - 1].isReserved) { // 座位未被预订
                    printf("Seat %d is not reserved.\n", seatNum);
                    break;
                }
                // 删除预订：标记为未预订，清空姓名
                seats[seatNum - 1].isReserved = 0;
                strcpy(seats[seatNum - 1].firstName, "");
                strcpy(seats[seatNum - 1].lastName, "");
                printf("Reservation for seat %d deleted.\n", seatNum);
                break;
            }
            case 'f': // 退出程序
                printf("Exiting program.\n");
                break;
            default: // 处理无效选择
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'f'); // 选择'f'时退出循环

    return 0;
}

// 测试验证方案：
//  1. 怎么运行：①用GCC编译代码（`gcc seat_reserve.c -o seat_reserve`）；②运行可执行文件（`./seat_reserve`）。
//  2. 预期结果：程序显示菜单，输入不同选项执行对应功能。如选a初始空座位数为12；选d分配座位后空座位数减少；选e删除后空座位数恢复；选c按姓氏字母序显示座位。
//  3. 检查点：空座位数量是否准确、空座位列表是否正确、分配/删除后座位状态是否改变、按姓氏排序是否正确。
// 易错点提醒：
//  1. `scanf(" %c", &choice);` 中`%c`前的空格必须加，否则会读取换行符导致选择错误。
//  2. 座位号转数组索引时要减1（如`seatNum - 1`），容易忘记导致数组越界。
//  3. 排序后要恢复座位号的原始顺序，否则后续按座位号操作会出错。
//  4. 使用`strcpy`时要确保目标数组有足够空间（本题中姓名数组设为50足够）。
// 拓展思考：
//  1. 若要支持多架飞机，可将结构体数组改为二维数组或添加“飞机编号”成员。
//  2. 如何保存座位状态到文件？用`fopen`/`fwrite`保存，启动时用`fread`读取初始化。
//  3. 如何支持输入中途取消？可检测特定输入（如空字符串）或用`fgets`灵活处理。
//  4. 如何添加“按座位号排序显示”？新增菜单选项，修改排序逻辑为按`seatNum`升序。