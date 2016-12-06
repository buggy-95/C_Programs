#include <stdio.h>
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
  int  age;
  char sex[4];
  bir  birth;
  char address[50];
  char phone[12];
  char email[30];
} ss;

void menue(); //-----------菜单
void input(); //-----------信息录入
void show(); //------------信息显示
void find(); //------------信息查找
void sort(); //------------信息排序
void change(ss *, ss *); //交换数据
int  no_data(); //----------判断空文件
void warn(int, const char *); //-输入错误提示
void print_head(); //------打印表头
void print_body(ss); //----打印表体
void print_end(); //-------打印表尾

int main() {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
  menue();
  return 0;
}

void menue() {
  int choose;
  do {
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                    1) 学生信息录入                     ┃\n");
    printf("┃                    2) 学生信息浏览                     ┃\n");
    printf("┃                    3) 学生信息查询                     ┃\n");
    printf("┃                    4) 学生信息排序(按学号)             ┃\n");
    printf("┃                    0)     退出                         ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    do {
      scanf("%d", &choose);
      fflush(stdin);
      switch (choose) {
        case 0: return;
        case 1: input(); break;
        case 2: show();  break;
        case 3: find();  break;
        case 4: sort();  break;
        default: warn(12, "没有该选项，请重新输入：");
      }
    } while(choose < 0 || choose > 4);
  } while(choose > 0 && choose < 5);
}

void input() {
  char jixu;
  FILE *fp = fopen("students.txt", "a+");
  do {
    ss student;
    printf("请输入姓名: ");
    scanf("%s", student.name);
    printf("请输入学号: ");
    scanf("%s", student.number);
    printf("请输入性别: ");
    scanf("%s", student.sex);
    printf("请输入年龄: ");
    scanf("%d", &student.age);
    fflush(stdin);
    printf("请输入生日: ");
    scanf("%d-%d-%d", &student.birth.year, &student.birth.month, &student.birth.day);
    fflush(stdin);
    printf("请输入电话: ");
    scanf("%s", student.phone);
    printf("请输入邮箱: ");
    scanf("%s", student.email);
    printf("请输入地址: ");
    scanf("%s", student.address);
    fwrite(&student, sizeof(student), 1, fp);
    printf("输入完成,是否继续输入?(y/n): ");
    fflush(stdin);
    jixu = getchar();
  } while(jixu != 'n');
  fclose(fp);
  warn(10, "\n****信息录入完成！****\n\n");
}

void show() {
  if(no_data()) { return; }
  ss student;
  FILE *fp = fopen("students.txt", "r");
  print_head();
  fread(&student, sizeof(student), 1, fp);
  while(!feof(fp)){
    print_body(student);
    fread(&student, sizeof(student), 1, fp);
    if(!feof(fp)) {
      printf("┣━━━┻━┳━━━┳━━┳━━┳━━━━━┳━━━━━━┫\n");
    }
  }
  fclose(fp);
  print_end();
}

void find() {
  if(no_data()) { return; }
  FILE *fp = fopen("students.txt", "r");
  char find_data[20];
  int choose, find = 0;
  ss student;
  do {
    printf("1) 按学号查找\n");
    printf("2) 按姓名查找\n");
    printf("0) 返回\n");
    do {
      scanf("%d", &choose);
      fflush(stdin);
      if(choose == 0) {
        return;
      } else if(choose == 1) {
        printf("请输入学号：");
      } else if(choose == 2) {
        printf("请输入姓名：");
      } else { warn(12, "没有该选项，请重新输入："); }
    } while(choose < 0 || choose > 2);
    scanf("%s", find_data);
    fread(&student, sizeof(student), 1, fp);
    while(!feof(fp)) {
      char *student_info = (choose == 1) ? student.number : student.name;
      if(0 == strcmp(student_info, find_data)) {
        print_head();
        print_body(student);
        print_end();
        find = 1;
        break;
      }
      fread(&student, sizeof(student), 1, fp);
    }
    if(!find) { warn(12, "\n****未找到****\n\n"); }
    rewind(fp);
    find = 0;
  } while(choose > 0 && choose <= 2);
  fclose(fp);
}

void sort() {
  if(no_data()) { return; }
  FILE *fp = fopen("students.txt", "r+");
  ss student, students[50];
  int i, j, k;
  fread(&student, sizeof(student), 1, fp);
  for(i = 0; !(feof(fp)); i++) { //将文件中的结构体读入内存
    students[i] = student;
    fread(&student, sizeof(student), 1, fp);
  }
  for(j = i - 1; j > 0; j--) { // 将结构体在内存中排序
    for(k = 0; k < j; k++) {
      if(strcmp(students[k].number, students[k + 1].number) > 0) {
        change(&students[k], &students[k + 1]);
      }
    }
  }
  rewind(fp); //将文件指针指向文件头，开始写入经过排序的数据
  for(j = 0; j < i; j++) {
    fwrite(&students[j], sizeof(student), 1, fp);
  }
  fclose(fp);
  warn(10, "\n****排序完成！****\n\n");
}

void change(ss *a, ss *b) {
  ss c = *a;
  *a = *b;
  *b = c;
}

int no_data() {
  FILE *fp = fopen("students.txt", "r");
  if(NULL == fp || EOF == fgetc(fp)) {
    warn(12, "\n****没有任何数据，请先录入学生信息！****\n\n");
    fclose(fp);
    return 1;
  }
  fclose(fp);
  return 0;
}

void warn(int color, const char *error) {
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
  printf("%s", error);
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}       

void print_head() {
  printf("┏━━━━━┳━━━┳━━┳━━┳━━━━━┳━━━━━━┓\n");
  printf("┃   学号   ┃ 姓名 ┃性别┃年龄┃ 出生日期 ┃    电话    ┃\n");
  printf("┣━━━━━╋━━━╋━━╋━━╋━━━━━╋━━━━━━┫\n");
}

void print_body(ss student) {
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
}

void print_end() {
  printf("┗━━━┻━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
}
