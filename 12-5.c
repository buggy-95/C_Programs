/*
题目六：学生信息管理系统设计

学生信息包括：

学号，姓名，年龄，性别，出生年月，地址，电话，E-mail等。

试设计一学生信息管理系统，使之能提供以下功能：

（1） 系统以菜单方式工作
（2） 学生信息录入功能（学生信息用文件保存）---输入
（3） 学生信息浏览功能---输出
（4） 查询、排序功能---算法
（5） 按学号查询
（6） 按姓名查询
（7） 学生信息的删除与修改（可选项）
*/
#include <stdio.h>
#include <windows.h>

typedef struct birthday {
    int year;
    int month;
    int day;
} bir;
typedef struct Students {
    char number[20];
    char name[10];
    int age;
    char sex[4];
    bir birth;
    char address[50];
    char phone[12];
    char email[30];
} ss;

void menue();
void message_input();
void show();
ss seek();//姓名\学号查找
void sort();//姓名\学号\生日排序
void revise();//修改\删除


int main()
{
    message_input();
    show();
    return 0;
}

void message_input() {
    FILE *fp;
    fp = fopen("students.txt", "a");
    if(!fp)
    {
        printf("errror!\n");
        return;
    }

    while(1) {
        ss student;
        printf("请输入姓名: ");
        scanf("%s", student.name);
        printf("请输入学号: ");
        scanf("%s", student.number);
        printf("请输入性别: ");
        scanf("%s", student.sex);
        printf("请输入年龄: ");
        scanf("%d", &student.age);
        getchar();
        printf("请输入生日: ");
        scanf("%d-%d-%d", &student.birth.year, &student.birth.month, &student.birth.day);
        getchar();
        printf("请输入电话: \n");
        scanf("%s", student.phone);
        printf("请输入邮箱: \n");
        scanf("%s", student.email);
        printf("请输入地址: \n");
        scanf("%s", student.address);
        fwrite(&student, sizeof(student), 1, fp);
        printf("输入完成,是否继续输入?(y/n): ");
        getchar();
        if(getchar() == 'n') { //是否继续输入数据
            break;
        }
    }
    fclose(fp);
}

void show() { //显示数据的列表
    ss student;
    FILE *fp = fopen("students.txt", "r");
    fread(&student, sizeof(student), 1, fp);
    printf("┏━━━━━┳━━━┳━━┳━━┳━━━━━┳━━━━━━┓\n");
    printf("┃   学号   ┃ 姓名 ┃性别┃年龄┃ 出生日期 ┃    电话    ┃\n");
    printf("┣━━━━━╋━━━╋━━╋━━╋━━━━━╋━━━━━━┫\n");
    // printf("┃%10s┃%-6s┃ %2s ┃ %2d ┃%4d-%02d-%02d┃%11s ┃\n", student.number, student.name, student.sex, student.age, student.birth.year, student.birth.month, student.birth.day, student.phone);
    printf("┃");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    printf("%10s", student.number);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    printf("┃");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    printf("%-6s", student.name);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    printf("┃ %2s ┃ %2d ┃%4d-%02d-%02d┃%11s ┃\n", student.sex, student.age, student.birth.year, student.birth.month, student.birth.day, student.phone);
    printf("┣━━━┳━┻━━━┻━━┻━━┻━━━━━┻━━━━━━┫\n");
    printf("┃地址: ┃%-48s┃\n", student.address);
    printf("┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
    printf("┃邮件: ┃%-48s┃\n", student.email);
    printf("┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    fclose(fp);
}