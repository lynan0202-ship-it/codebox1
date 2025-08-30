// ------------------------------
// 题干：巨人航空公司需要另一架飞机（容量相同），每天飞4班（航班102、311、444和519）。把程序扩展为可以处理4个航班。用一个顶层菜单提供航班选择和退出。选择一个特定航班，就会出现和编程练习8类似的菜单。但是该菜单要添加一个新选项：确认座位分配。而且，菜单中的退出是返回顶层菜单。每次显示都要指明当前正在处理的航班号。另外，座位分配显示要指明确认状态。
// 知识要点：
//  1. 结构体嵌套 - 用结构体包含航班信息和座位数组
//  2. 多层菜单系统 - 顶层选航班，子菜单处理单航班座位操作
//  3. 二维结构体数组 - 管理多个航班的座位数据
//  4. 函数封装 - 将单航班的操作封装为函数，提高代码复用性
// 总体逻辑：
//  1. 定义座位结构体（含编号、预订状态、姓名）和航班结构体（含航班号、座位数组）
//  2. 初始化4个航班的结构体数组，每个航班12个座位（初始未预订）
//  3. 显示顶层菜单，让用户选择航班或退出程序
//  4. 选择航班后，进入该航班的子菜单（含练习8的功能+“确认座位分配”选项）
//  5. 子菜单操作完成后返回顶层菜单，直到用户选择退出
#include <stdio.h>
#include <string.h>

// 定义座位结构体：包含座位号、预订状态、预订人姓名
typedef struct {
    int seatNum;          // 座位编号（1-12）
    int isReserved;       // 是否预订：0=未预订，1=已预订
    int isConfirmed;      // 是否确认：0=未确认，1=已确认
    char firstName[50];   // 预订人名
    char lastName[50];    // 预订人姓
} Seat;

// 定义航班结构体：包含航班号和12个座位的数组
typedef struct {
    int flightNum;        // 航班号（102、311、444、519）
    Seat seats[12];       // 该航班的12个座位
} Flight;

// 函数声明：处理单个航班的子菜单操作
void handleFlight(Flight *flight);

int main() {
    // 初始化4个航班的结构体数组
    Flight flights[4] = {
        {102, {0}}, {311, {0}}, {444, {0}}, {519, {0}}
    };
    // 初始化每个航班的12个座位
    for (int f = 0; f < 4; f++) {
        for (int s = 0; s < 12; s++) {
            flights[f].seats[s].seatNum = s + 1;
            flights[f].seats[s].isReserved = 0;
            flights[f].seats[s].isConfirmed = 0;
            strcpy(flights[f].seats[s].firstName, "");
            strcpy(flights[f].seats[s].lastName, "");
        }
    }

    int choice; // 顶层菜单的选择（1-4对应航班，5退出）
    do {
        // 显示顶层菜单
        printf("\n=== Top-Level Menu: Choose a Flight ===\n");
        printf("1) Flight 102\n");
        printf("2) Flight 311\n");
        printf("3) Flight 444\n");
        printf("4) Flight 519\n");
        printf("5) Quit Program\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4) {
            // 选择了某个航班，调用函数处理该航班的子菜单
            handleFlight(&flights[choice - 1]);
        } else if (choice != 5) {
            // 无效选择（除了5以外的错误输入）
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5); // 选择5时退出程序

    printf("Program exited.\n");
    return 0;
}

// 处理单个航班的子菜单操作
void handleFlight(Flight *flight) {
    char choice; // 子菜单的选择（a-f，g返回顶层）
    do {
        // 显示子菜单（包含当前航班号）
        printf("\n=== Flight %d - Seat Assignment Menu ===\n", flight->flightNum);
        printf("To choose a function, enter its letter label:\n");
        printf("a) Show number of empty seats\n");
        printf("b) Show list of empty seats\n");
        printf("c) Show alphabetical list of seats\n");
        printf("d) Assign a customer to a seat assignment\n");
        printf("e) Delete a seat assignment\n");
        printf("f) Confirm seat assignment\n"); // 新增的确认选项
        printf("g) Return to Top-Level Menu\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice); // 加空格跳过输入前的空白符

        switch (choice) {
            case 'a': { // 显示空座位数量
                int emptyCount = 0;
                for (int i = 0; i < 12; i++) {
                    if (flight->seats[i].isReserved == 0) {
                        emptyCount++;
                    }
                }
                printf("Number of empty seats: %d\n", emptyCount);
                break;
            }
            case 'b': { // 显示空座位编号列表
                printf("Empty seats for Flight %d: ", flight->flightNum);
                int hasEmpty = 0;
                for (int i = 0; i < 12; i++) {
                    if (flight->seats[i].isReserved == 0) {
                        printf("%d ", flight->seats[i].seatNum);
                        hasEmpty = 1;
                    }
                }
                if (!hasEmpty) {
                    printf("None");
                }
                printf("\n");
                break;
            }
            case 'c': { // 按姓氏字母序显示所有座位
                Seat temp;
                // 冒泡排序：按lastName字母升序
                for (int i = 0; i < 11; i++) {
                    for (int j = 0; j < 11 - i; j++) {
                        if (strcmp(flight->seats[j].lastName, flight->seats[j + 1].lastName) > 0) {
                            temp = flight->seats[j];
                            flight->seats[j] = flight->seats[j + 1];
                            flight->seats[j + 1] = temp;
                        }
                    }
                }
                // 显示排序后的座位信息（含确认状态）
                printf("Seats for Flight %d (alphabetical by last name):\n", flight->flightNum);
                printf("Seat #\tFirst Name\tLast Name\tReserved\tConfirmed\n");
                for (int i = 0; i < 12; i++) {
                    printf("%d\t%s\t\t%s\t\t%s\t\t%s\n", 
                           flight->seats[i].seatNum, 
                           flight->seats[i].firstName, 
                           flight->seats[i].lastName, 
                           flight->seats[i].isReserved ? "Yes" : "No",
                           flight->seats[i].isConfirmed ? "Yes" : "No");
                }
                // 恢复座位号的原始顺序
                for (int i = 0; i < 12; i++) {
                    flight->seats[i].seatNum = i + 1;
                }
                break;
            }
            case 'd': { // 分配座位给用户
                int seatNum;
                char fName[50], lName[50];
                printf("Enter seat number (1-12, enter 0 to cancel): ");
                scanf("%d", &seatNum);
                if (seatNum == 0) {
                    printf("Assignment canceled.\n");
                    break;
                }
                if (seatNum < 1 || seatNum > 12) {
                    printf("Invalid seat number!\n");
                    break;
                }
                if (flight->seats[seatNum - 1].isReserved) {
                    printf("Seat %d is already reserved.\n", seatNum);
                    break;
                }
                printf("Enter first name: ");
                scanf("%s", fName);
                printf("Enter last name: ");
                scanf("%s", lName);
                // 分配座位（初始未确认）
                flight->seats[seatNum - 1].isReserved = 1;
                flight->seats[seatNum - 1].isConfirmed = 0;
                strcpy(flight->seats[seatNum - 1].firstName, fName);
                strcpy(flight->seats[seatNum - 1].lastName, lName);
                printf("Seat %d assigned to %s %s (not confirmed yet).\n", seatNum, fName, lName);
                break;
            }
            case 'e': { // 删除座位预订
                int seatNum;
                printf("Enter seat number to delete (1-12, enter 0 to cancel): ");
                scanf("%d", &seatNum);
                if (seatNum == 0) {
                    printf("Deletion canceled.\n");
                    break;
                }
                if (seatNum < 1 || seatNum > 12) {
                    printf("Invalid seat number!\n");
                    break;
                }
                if (!flight->seats[seatNum - 1].isReserved) {
                    printf("Seat %d is not reserved.\n", seatNum);
                    break;
                }
                // 删除预订（同时重置确认状态）
                flight->seats[seatNum - 1].isReserved = 0;
                flight->seats[seatNum - 1].isConfirmed = 0;
                strcpy(flight->seats[seatNum - 1].firstName, "");
                strcpy(flight->seats[seatNum - 1].lastName, "");
                printf("Reservation for seat %d deleted.\n", seatNum);
                break;
            }
            case 'f': { // 确认座位分配
                int seatNum;
                printf("Enter seat number to confirm (1-12, enter 0 to cancel): ");
                scanf("%d", &seatNum);
                if (seatNum == 0) {
                    printf("Confirmation canceled.\n");
                    break;
                }
                if (seatNum < 1 || seatNum > 12) {
                    printf("Invalid seat number!\n");
                    break;
                }
                if (!flight->seats[seatNum - 1].isReserved) {
                    printf("Seat %d is not reserved, cannot confirm.\n", seatNum);
                    break;
                }
                flight->seats[seatNum - 1].isConfirmed = 1;
                printf("Seat %d for %s %s is confirmed.\n", 
                       seatNum, 
                       flight->seats[seatNum - 1].firstName, 
                       flight->seats[seatNum - 1].lastName);
                break;
            }
            case 'g': { // 返回顶层菜单
                printf("Returning to Top-Level Menu.\n");
                break;
            }
            default: // 处理无效选择
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 'g'); // 选择'g'时返回顶层菜单
}

// 测试验证方案：
//  1. 怎么运行：①用GCC编译代码（`gcc flight_reserve.c -o flight_reserve`）；②运行可执行文件（`./flight_reserve`）。
//  2. 预期结果：顶层菜单显示4个航班选项，选择某航班后进入子菜单（含新增的“f) Confirm seat assignment”选项）；子菜单操作后选'g'返回顶层，选'5'退出程序。
//  3. 检查点：
//     - 顶层菜单能否正确选择航班并进入对应子菜单；
//     - 子菜单的“确认座位分配”功能是否只对已预订座位生效，且能标记为已确认；
//     - 按姓氏排序显示时，是否包含“确认状态”；
//     - 操作后返回顶层菜单是否正常，退出程序是否正常。
// 易错点提醒：
//  1. 顶层菜单选择航班时，数组索引是`choice - 1`，容易忘记减1导致访问错误航班。
//  2. `scanf(" %c", &choice);` 中`%c`前的空格必须加，否则会读取换行符导致选择错误。
//  3. 确认座位时，要先检查座位是否已预订，否则会错误确认未预订的座位。
//  4. 排序后要恢复座位号的原始顺序，否则后续按座位号操作会出错。
// 拓展思考：
//  1. 若要支持更多航班，如何修改？可将航班数组的大小改为变量，或用动态内存分配（`malloc`）。
//  2. 如何将所有航班的座位状态保存到文件？用`fopen`/`fwrite`循环写入每个航班的信息，启动时`fread`读取初始化。
//  3. 如何添加“取消确认”功能？新增子菜单选项，将已确认的座位重置为未确认。
//  4. 若要统计每个航班的已确认座位数，如何扩展？在子菜单中新增选项，遍历座位统计`isConfirmed == 1`的数量。