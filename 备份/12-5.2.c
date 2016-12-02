/*
��Ŀ����ѧ����Ϣ����ϵͳ���

ѧ����Ϣ������

ѧ�ţ����������䣬�Ա𣬳������£���ַ���绰��E-mail�ȡ�

�����һѧ����Ϣ����ϵͳ��ʹ֮���ṩ���¹��ܣ�

��1�� ϵͳ�Բ˵���ʽ����
��2�� ѧ����Ϣ¼�빦�ܣ�ѧ����Ϣ���ļ����棩---����
��3�� ѧ����Ϣ�������---���
��4�� ��ѯ��������---�㷨
��5�� ��ѧ�Ų�ѯ
��6�� ��������ѯ
��7�� ѧ����Ϣ��ɾ�����޸ģ���ѡ�
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
void print_head();
void print_body(ss);
void print_end();
void show();
void find();
void sort();//����\ѧ��\��������
void change(ss *, ss *);
void revise();//�޸�\ɾ��

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
    menue();
    return 0;
}

void menue() {
    int choose;
    do {
        printf("������������������������������������������������������������\n");
        printf("��                   1) ѧ����Ϣ¼��                      ��\n");
        printf("��                   2) ѧ����Ϣ���                      ��\n");
        printf("��                   3) ѧ����Ϣ��ѯ                      ��\n");
        printf("��                   4) ѧ����Ϣ����                      ��\n");
        printf("��                   0)     �˳�                          ��\n");
        printf("������������������������������������������������������������\n");
        do {
            scanf("%d", &choose);
            fflush(stdin);
        } while(choose < 0 || choose > 4);
        switch (choose) {
            case 0: return;
            case 1: message_input(); break;
            case 2: show(); break;
            case 3: find(); break;
            case 4: sort(); break;
        }
    } while(choose > 0 && choose < 5);
}

void message_input() {
    FILE *fp = fopen("students.txt", "a+");
    if(!fp)
    {
        printf("errror!\n");
        return;
    }
    while(1) {
        ss student;
        printf("����������: ");
        scanf("%s", student.name);
        printf("������ѧ��: ");
        scanf("%s", student.number);
        printf("�������Ա�: ");
        scanf("%s", student.sex);
        printf("����������: ");
        scanf("%d", &student.age);
        getchar();
        printf("����������: ");
        scanf("%d-%d-%d", &student.birth.year, &student.birth.month, &student.birth.day);
        getchar();
        printf("������绰: ");
        scanf("%s", student.phone);
        printf("����������: ");
        scanf("%s", student.email);
        printf("�������ַ: ");
        scanf("%s", student.address);
        fwrite(&student, sizeof(student), 1, fp);
        printf("�������,�Ƿ��������?(y/n): ");
        getchar();
        if(getchar() == 'n') { //�Ƿ������������
            break;
        }
        fclose(fp);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf("\n��Ϣ¼����ɣ�\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}

void show() {
    ss student;
    FILE *fp = fopen("students.txt", "r");
    print_head();
    fread(&student, sizeof(student), 1, fp);
    while(!feof(fp)){
        print_body(student);
        fread(&student, sizeof(student), 1, fp);
        if(!feof(fp)) {
            printf("�ǩ������ߩ��ש������ש����ש����ש����������ש�������������\n");
        }
    }
    fclose(fp);
    print_end();
}

void find() {
    FILE *fp = fopen("students.txt", "r");
    char findstr[20];
    int choose, find = 0;
    ss student;
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
                print_head();
                print_body(student);
                print_end();
                find = 1;
                break;
            }
            fread(&student, sizeof(student), 1, fp);
        }
        if(!find) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            printf("\n***δ�ҵ�***\n\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
        }
        find = 0;
        rewind(fp);
    } while(choose > 0 && choose <= 2);
    fclose(fp);
}

void print_head() {
    printf("�������������ש������ש����ש����ש����������ש�������������\n");
    printf("��   ѧ��   �� ���� ���Ա����䩧 �������� ��    �绰    ��\n");
    printf("�ǩ����������贈�����贈���贈���贈���������贈������������\n");
}

void print_end() {
    printf("���������ߩ�������������������������������������������������\n");
}

void print_body(ss student) {
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
}

void change(ss *a, ss *b) {
    ss c = *a;
    *a = *b;
    *b = c;
}

void sort() {
    FILE *fp = fopen("students.txt", "r+");
    ss student, students[50];
    int i, j, k;
    fread(&student, sizeof(student), 1, fp);
    for(i = 0; !(feof(fp)); i++) { //���ļ��еĽṹ������ڴ�
        students[i] = student;
        fread(&student, sizeof(student), 1, fp);
    }
    for(j = i - 1; j > 0; j--) { // ���ṹ�����ڴ�������
        for(k = 0; k < j; k++) {
            if(strcmp(students[k].number, students[k + 1].number) > 0) {
                change(&students[k], &students[k + 1]);
            }
        }
    }
    rewind(fp); //���ļ�ָ��ָ���ļ�ͷ����ʼд�뾭�����������
    for(j = 0; j < i; j++) {
        fwrite(&students[j], sizeof(student), 1, fp);
    }
    fclose(fp);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    printf("\n������ɣ�\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
}
