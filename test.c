#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void find();
void show();
int iseof(FILE *);
int main()
{
    find();
    return 0;
}
void show() {
    printf("┏━━━━━┳━━━┳━━┳━━┳━━━━━┳━━━━━━┓\n");
    printf("┃   学号   ┃ 姓名 ┃性别┃年龄┃ 出生日期 ┃    电话    ┃\n");
    printf("┣━━━━━╋━━━╋━━╋━━╋━━━━━╋━━━━━━┫\n");
    ss student;
    FILE *fp = fopen("students.txt", "r");
	fread(&student, sizeof(student), 1, fp);
    while(!feof(fp)){
	    printf("┃");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	    printf("%10s", student.number);
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	    printf("┃");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	    printf("%-6s", student.name);
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	    printf("┃ %2s ┃ %2d ┃%4d-%02d-%02d┃%11s ┃\n", student.sex, student.age, student.birth.year, student.birth.month, student.birth.day, student.phone);
	    // printf("┃%10s┃%-6s┃ %2s ┃ %2d ┃%4d-%02d-%02d┃%11s ┃\n", student.number, student.n《Web前端开发最佳实践》ame, student.sex, student.age, student.birth.year, student.birth.month, student.birth.day, student.phone);
	    printf("┣━━━┳━┻━━━┻━━┻━━┻━━━━━┻━━━━━━┫\n");
	    printf("┃地址: ┃%-48s┃\n", student.address);
	    printf("┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
	    printf("┃邮件: ┃%-48s┃\n", student.email);
	    fread(&student, sizeof(student), 1, fp);
	    if(!feof(fp))
	        printf("┣━━━┻━┳━━━┳━━┳━━┳━━━━━┳━━━━━━┫\n");
    }
    printf("┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    fclose(fp);
}
void find() {
    char findstr[20];
    int choose, find = 0;
    ss student;
    FILE *fp = fopen("students.txt", "r");
    do {
	    printf("1) 按学号查找；\n");
	    printf("2) 按姓名查找；\n");
	    printf("0) 退出。\n");
	    do {
	    	scanf("%d", &choose);
		    fflush(stdin);
		    if(choose == 0) {
		    	return;
		    } else if(choose == 1) {
		    	printf("请输入学号：");
		    } else if(choose == 2) {
		    	printf("请输入姓名：");
		    } else {
		    	printf("输入错误，请重新输入：");
		    }
		} while(choose < 0 || choose > 2);
		scanf("%s", findstr);
		fflush(stdin);

        fread(&student, sizeof(student), 1, fp);

        while(!feof(fp)) {
	        char* student_info = (choose == 1) ? student.number : student.name;
	        if(0 == strcmp(student_info, findstr)) {
	            printf("┏━━━━━┳━━━┳━━┳━━┳━━━━━┳━━━━━━┓\n");
			    printf("┃   学号   ┃ 姓名 ┃性别┃年龄┃ 出生日期 ┃    电话    ┃\n");
			    printf("┣━━━━━╋━━━╋━━╋━━╋━━━━━╋━━━━━━┫\n");
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
			    find = 1;
			    break;
	        }
	        fread(&student, sizeof(student), 1, fp);
    	}
	    if(!find) {
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		    printf("***未找到***\n");
		    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	    }
	    rewind(fp);
	    find = 0;
	} while(choose > 0 && choose <= 2);
	fclose(fp);

    // scanf("%s", number);
    // while(!feof(fp)) {
    //     fread(&student, sizeof(student), 1, fp);
    //     if(0 == strcmp(student.number, findstr)) {
    //         fseek(fp, -sizeof(student), 1);
    //         printf("┏━━━━━┳━━━┳━━┳━━┳━━━━━┳━━━━━━┓\n");
		  //   printf("┃   学号   ┃ 姓名 ┃性别┃年龄┃ 出生日期 ┃    电话    ┃\n");
		  //   printf("┣━━━━━╋━━━╋━━╋━━╋━━━━━╋━━━━━━┫\n");
		  //   printf("┃");
		  //   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		  //   printf("%10s", student.number);
		  //   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		  //   printf("┃");
		  //   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		  //   printf("%-6s", student.name);
		  //   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		  //   printf("┃ %2s ┃ %2d ┃%4d-%02d-%02d┃%11s ┃\n", student.sex, student.age, student.birth.year, student.birth.month, student.birth.day, student.phone);
		  //   printf("┣━━━┳━┻━━━┻━━┻━━┻━━━━━┻━━━━━━┫\n");
		  //   printf("┃地址: ┃%-48s┃\n", student.address);
		  //   printf("┣━━━╋━━━━━━━━━━━━━━━━━━━━━━━━┫\n");
		  //   printf("┃邮件: ┃%-48s┃\n", student.email);
		  //   printf("┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		  //   find = 1;
		  //   break;
    //     }
    //     // printf("running\n");
    // }
    // if(!find)
    // 	printf("未找到\n");
    // fclose(fp);
}
int iseof(FILE *fp) {
	fseek(fp, 1L, 1);
	if(feof(fp)) {
		fseek(fp, -1L, 1);
		return 1;
	} else {
		fseek(fp, -1L, 1);
		return 0;
	}
}