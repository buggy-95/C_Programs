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
void show();
ss seek();//����\ѧ�Ų���
void sort();//����\ѧ��\��������
void revise();//�޸�\ɾ��


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

void show() { //��ʾ���ݵ��б�
    ss student;
    FILE *fp = fopen("students.txt", "r");
    fread(&student, sizeof(student), 1, fp);
    printf("�������������ש������ש����ש����ש����������ש�������������\n");
    printf("��   ѧ��   �� ���� ���Ա����䩧 �������� ��    �绰    ��\n");
    printf("�ǩ����������贈�����贈���贈���贈���������贈������������\n");
    // printf("��%10s��%-6s�� %2s �� %2d ��%4d-%02d-%02d��%11s ��\n", student.number, student.name, student.sex, student.age, student.birth.year, student.birth.month, student.birth.day, student.phone);
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
    fclose(fp);
}