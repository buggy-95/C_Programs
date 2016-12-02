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
    printf("�������������ש������ש����ש����ש����������ש�������������\n");
    printf("��   ѧ��   �� ���� ���Ա����䩧 �������� ��    �绰    ��\n");
    printf("�ǩ����������贈�����贈���贈���贈���������贈������������\n");
    ss student;
    FILE *fp = fopen("students.txt", "r");
	fread(&student, sizeof(student), 1, fp);
    while(!feof(fp)){
	    printf("��");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	    printf("%10s", student.number);
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	    printf("��");
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	    printf("%-6s", student.name);
	    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	    printf("�� %2s �� %2d ��%4d-%02d-%02d��%11s ��\n", student.sex, student.age, student.birth.year, student.birth.month, student.birth.day, student.phone);
	    // printf("��%10s��%-6s�� %2s �� %2d ��%4d-%02d-%02d��%11s ��\n", student.number, student.n��Webǰ�˿������ʵ����ame, student.sex, student.age, student.birth.year, student.birth.month, student.birth.day, student.phone);
	    printf("�ǩ������ש��ߩ������ߩ����ߩ����ߩ����������ߩ�������������\n");
	    printf("����ַ: ��%-48s��\n", student.address);
	    printf("�ǩ������贈������������������������������������������������\n");
	    printf("���ʼ�: ��%-48s��\n", student.email);
	    fread(&student, sizeof(student), 1, fp);
	    if(!feof(fp))
	        printf("�ǩ������ߩ��ש������ש����ש����ש����������ש�������������\n");
    }
    printf("���������ߩ�������������������������������������������������\n");
    fclose(fp);
}
void find() {
    char findstr[20];
    int choose, find = 0;
    ss student;
    FILE *fp = fopen("students.txt", "r");
    do {
	    printf("1) ��ѧ�Ų��ң�\n");
	    printf("2) ���������ң�\n");
	    printf("0) �˳���\n");
	    do {
	    	scanf("%d", &choose);
		    fflush(stdin);
		    if(choose == 0) {
		    	return;
		    } else if(choose == 1) {
		    	printf("������ѧ�ţ�");
		    } else if(choose == 2) {
		    	printf("������������");
		    } else {
		    	printf("����������������룺");
		    }
		} while(choose < 0 || choose > 2);
		scanf("%s", findstr);
		fflush(stdin);

        fread(&student, sizeof(student), 1, fp);

        while(!feof(fp)) {
	        char* student_info = (choose == 1) ? student.number : student.name;
	        if(0 == strcmp(student_info, findstr)) {
	            printf("�������������ש������ש����ש����ש����������ש�������������\n");
			    printf("��   ѧ��   �� ���� ���Ա����䩧 �������� ��    �绰    ��\n");
			    printf("�ǩ����������贈�����贈���贈���贈���������贈������������\n");
			    printf("��");
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
			    printf("%10s", student.number);
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			    printf("��");
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			    printf("%-6s", student.name);
			    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			    printf("�� %2s �� %2d ��%4d-%02d-%02d��%11s ��\n", student.sex, student.age, student.birth.year, student.birth.month, student.birth.day, student.phone);
			    printf("�ǩ������ש��ߩ������ߩ����ߩ����ߩ����������ߩ�������������\n");
			    printf("����ַ: ��%-48s��\n", student.address);
			    printf("�ǩ������贈������������������������������������������������\n");
			    printf("���ʼ�: ��%-48s��\n", student.email);
			    printf("���������ߩ�������������������������������������������������\n");
			    find = 1;
			    break;
	        }
	        fread(&student, sizeof(student), 1, fp);
    	}
	    if(!find) {
	    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		    printf("***δ�ҵ�***\n");
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
    //         printf("�������������ש������ש����ש����ש����������ש�������������\n");
		  //   printf("��   ѧ��   �� ���� ���Ա����䩧 �������� ��    �绰    ��\n");
		  //   printf("�ǩ����������贈�����贈���贈���贈���������贈������������\n");
		  //   printf("��");
		  //   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		  //   printf("%10s", student.number);
		  //   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		  //   printf("��");
		  //   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		  //   printf("%-6s", student.name);
		  //   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		  //   printf("�� %2s �� %2d ��%4d-%02d-%02d��%11s ��\n", student.sex, student.age, student.birth.year, student.birth.month, student.birth.day, student.phone);
		  //   printf("�ǩ������ש��ߩ������ߩ����ߩ����ߩ����������ߩ�������������\n");
		  //   printf("����ַ: ��%-48s��\n", student.address);
		  //   printf("�ǩ������贈������������������������������������������������\n");
		  //   printf("���ʼ�: ��%-48s��\n", student.email);
		  //   printf("���������ߩ�������������������������������������������������\n");
		  //   find = 1;
		  //   break;
    //     }
    //     // printf("running\n");
    // }
    // if(!find)
    // 	printf("δ�ҵ�\n");
    // fclose(fp);
}
void sort(FILE *fp) {
    ss student, students[50];
    int i, j, k;
    fread(&student, sizeof(student), 1, fp);
    for(i = 0; !(feof(fp)); i++) { //���ļ��еĽṹ������ڴ�
        students[i] = student;
        printf("test2\n");
        fread(&student, sizeof(student), 1, fp);
    }
    printf("test3\n");
    for(j = i - 1; j > 0; j--) { // ���ṹ�����ڴ�������
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