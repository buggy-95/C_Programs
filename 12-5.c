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

int iseof(FILE *);
void menue();
void message_input();
void show();
ss seek();//����\ѧ�Ų���
void sort();//����\ѧ��\��������
void revise();//�޸�\ɾ��
void find();

int main()
{
    // message_input();
    show();
    return 0;
}

void message_input() {
    FILE *fp = fopen("students.txt", "a");
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
        printf("������绰: \n");
        scanf("%s", student.phone);
        printf("����������: \n");
        scanf("%s", student.email);
        printf("�������ַ: \n");
        scanf("%s", student.address);
        fwrite(&student, sizeof(student), 1, fp);
        printf("�������,�Ƿ��������?(y/n): ");
        getchar();
        if(getchar() == 'n') { //�Ƿ������������
            break;
        }
    }
    fclose(fp);
}

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
        // printf("��%10s��%-6s�� %2s �� %2d ��%4d-%02d-%02d��%11s ��\n", student.number, student.name, student.sex, student.age, student.birth.year, student.birth.month, student.birth.day, student.phone);
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
void find() {
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
                break;
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
        
        char* student_info = (choose == 1) ? student.number : student.name;

    } while(choose > 0 && choose <= 2);


    // scanf("%s", number);
    FILE *fp = fopen("students.txt", "r");
    while(!feof(fp)) {
        fread(&student, sizeof(student), 1, fp);
        if(0 == strcmp(student.number, findstr)) {
            fseek(fp, -sizeof(student), 1);
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
        // printf("running\n");
    }
    if(!find)
        printf("δ�ҵ�\n");
    fclose(fp);
}