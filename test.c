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
void sort(FILE *);
void change(ss, ss);
//-------------------------------------------------------------------------------------------
int main()
{
    show();
    // printf("\nAfter sort:\n\n");

    // FILE *fp = fopen("students.txt", "w");
    // sort(fp);
    // fclose(fp);
    // show();
    return 0;
}
//-------------------------------------------------------------------------------------------
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
void sort(FILE *fp) {
    ss student, students[50];
    int i, j, k;
    fread(&student, sizeof(student), 1, fp);
    for(i = 0; !(feof(fp)); i++) { //将文件中的结构体读入内存
        students[i] = student;
        printf("test2\n");
        fread(&student, sizeof(student), 1, fp);
    }
    printf("test3\n");
    for(j = i - 1; j > 0; j--) { // 将结构体在内存中排序
        for(k = 0; k < j; k++) {
            if(strcmp(students[k].number, students[k + 1].number) > 0) {
                change(students[k], students[k + 1]);
            }
        }
    }
    printf("test4\n");
    for(j = 0; j < i; j++) {
        fwrite(&students[j], sizeof(student), 1, fp);
    }
}
void change(ss a, ss b) {
    ss c = a;
    a = b;
    b = c;
}