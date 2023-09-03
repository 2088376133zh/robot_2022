#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000 // ѧ����Ϣ�������󳤶�
#define FILE_NAME "students.txt" // ѧ����Ϣ�ļ���

// ѧ����Ϣ�ṹ��
typedef struct {
    char id[20]; // ѧ��
    char name[20]; // ����
    int age; // ����
    char gender[10]; // �Ա�
    char birth[20]; // ��������
    char address[100]; // ��ַ
    char phone[20]; // �绰
    char email[50]; // ����
} Student;

// ѧ����Ϣ�����ѧ����Ϣ����
Student students[MAX_SIZE];
int count = 0;

// ��������
void displayMenu();

void addStudent();

void viewStudents();

void searchStudent();

void deleteStudent();

void modifyStudent();

void saveToFile();

void readFromFile();

int main() {
    int choice;
    readFromFile(); // ���ļ��ж�ȡѧ����Ϣ

    do {
        displayMenu(); // ��ʾ�˵�
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                modifyStudent();
                break;
            case 6:
                saveToFile();
                printf("����ɹ�\n");
                break;
            case 7:
                printf("�˳�����\n");
                break;
            default:
                printf("��������ȷ��ѡ��\n");
        }
    } while (choice != 7);

    return 0;
}

// ��ʾ�˵�
void displayMenu() {
    printf("\nѧ����Ϣ����ϵͳ\n");
    printf("-----------------\n");
    printf("1. ���ѧ����Ϣ\n");
    printf("2. ���ѧ����Ϣ\n");
    printf("3. ��ѯѧ����Ϣ\n");
    printf("4. ɾ��ѧ����Ϣ\n");
    printf("5. �޸�ѧ����Ϣ\n");
    printf("6. ���浽�ļ�\n");
    printf("7. �˳�����\n");
    printf("������ѡ�");
}

// ���ѧ����Ϣ
void addStudent() {
    Student student;

    printf("\n������ѧ����Ϣ��\n");
    printf("ѧ�ţ�");
    scanf("%s", student.id);
    for (int i = 0; i < count; i++){
        if(strcmp(students[i].id, student.id) == 0){
            printf("ѧ���Ѵ��ڣ����������롣\n");
            return;
        }
    }
    printf("������");
    scanf("%s", student.name);
    printf("���䣺");
    scanf("%d", &student.age);
    printf("�Ա�");
    scanf("%s", student.gender);
    printf("�������£�");
    scanf("%s", student.birth);
    printf("��ַ��");
    scanf("%s", student.address);
    printf("�绰��");
    scanf("%s", student.phone);
    printf("E-mail��");
    scanf("%s", student.email);

    students[count++] = student;
}

// ���ѧ����Ϣ
void viewStudents() {
    printf("\n����ѧ����Ϣ��\n");
    printf("%-15s%-10s%-10s%-10s%-15s%-30s%-20s%-30s\n", "ѧ��", "����", "����", "�Ա�", "��������", "��ַ", "�绰", "E-mail");
    // ���ÿ��ѧ������Ϣ
    for (int i = 0; i < count; i++) {
        printf("%-15s%-10s%-10d%-10s%-15s%-30s%-20s%-30s\n", students[i].id, students[i].name, students[i].age,
               students[i].gender, students[i].birth, students[i].address, students[i].phone, students[i].email);
    }
}

// ��ѯѧ����Ϣ
void searchStudent() {
    int choice;
    char id[20];
    char name[20];
    int found = 0;

    printf("\n��ѯѧ����Ϣ��\n");
    printf("1. ��ѧ�Ų�ѯ\n");
    printf("2. ��������ѯ\n");
    printf("��ѡ���ѯ��ʽ��");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("������Ҫ��ѯ��ѧ�ţ�");
            scanf("%s", id);
            printf("\n%-15s%-10s%-10s%-10s%-15s%-30s%-20s%-30s\n", "ѧ��", "����", "����", "�Ա�", "��������", "��ַ", "�绰", "E-mail");
            for (int i = 0; i < count; i++) {
                if (strcmp(students[i].id, id) == 0) {
                    printf("%-15s%-10s%-10d%-10s%-15s%-30s%-20s%-30s\n", students[i].id, students[i].name,
                           students[i].age, students[i].gender, students[i].birth, students[i].address,
                           students[i].phone, students[i].email);
                    found = 1;
                    break;
                }
            }
            break;
        case 2:
            printf("������Ҫ��ѯ��������");
            scanf("%s", name);
            printf("\n%-15s%-10s%-10s%-10s%-15s%-30s%-20s%-30s\n", "ѧ��", "����", "����", "�Ա�", "��������", "��ַ", "�绰", "E-mail");
            for (int i = 0; i < count; i++) {
                if (strcmp(students[i].name, name) == 0) {
                    printf("%-15s%-10s%-10d%-10s%-15s%-30s%-20s%-30s\n", students[i].id, students[i].name,
                           students[i].age, students[i].gender, students[i].birth, students[i].address,
                           students[i].phone, students[i].email);
                    found = 1;
                }
            }
            break;
        default:
            printf("��������ȷ��ѡ��\n");
    }

    if (!found) {
        printf("δ�ҵ���ѧ����Ϣ\n");
    }
}

// ɾ��ѧ����Ϣ
void deleteStudent() {
    char id[20];
    int found = 0;

    printf("\n������Ҫɾ����ѧ��ѧ�ţ�");
    scanf("%s", id);

// �������е�ѧ����Ϣ���ҵ�Ҫɾ����ѧ����Ϣ
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            found = 1;
            // ����ѧ����Ϣ��������ɾ��
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("ɾ���ɹ�\n");
            break;
        }
    }

    if (!found) {
        printf("δ�ҵ���ѧ����Ϣ\n");
    }
}

// �޸�ѧ����Ϣ
void modifyStudent() {
    char id[20];
    int found = 0;

    printf("\n������Ҫ�޸ĵ�ѧ��ѧ�ţ�");
    scanf("%s", id);

// �������е�ѧ����Ϣ���ҵ�Ҫ�޸ĵ�ѧ����Ϣ
    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            found = 1;
            printf("\n������ѧ����Ϣ��\n");
            printf("ѧ�ţ�%s�������޸ģ�\n", students[i].id);
            printf("������");
            scanf("%s", students[i].name);
            printf("���䣺");
            scanf("%d", &students[i].age);
            printf("�Ա�");
            scanf("%s", students[i].gender);
            printf("�������£�");
            scanf("%s", students[i].birth);
            printf("��ַ��");
            scanf("%s", students[i].address);
            printf("�绰��");
            scanf("%s", students[i].phone);
            printf("E-mail��");
            scanf("%s", students[i].email);
            printf("�޸ĳɹ�\n");
            break;
        }
    }

    if (!found) {
        printf("δ�ҵ���ѧ����Ϣ\n");
    }
}

// ��ѧ����Ϣ���浽�ļ�
void saveToFile() {
    FILE *fp;
    fp = fopen(FILE_NAME, "w");

    for (int i = 0; i < count; i++) {
        fprintf(fp, "%s,%s,%d,%s,%s,%s,%s,%s\n", students[i].id, students[i].name, students[i].age, students[i].gender,
                students[i].birth, students[i].address, students[i].phone, students[i].email);
    }

    fclose(fp);
}

// ���ļ��ж�ȡѧ����Ϣ
void readFromFile() {
    FILE *fp;
    char line[500];
    char *token;
    const char delim[2] = ",";
    fp = fopen(FILE_NAME, "r");

    if (fp) {
        count = 0;
        while (fgets(line, 500, fp)) {
            // ����ȡ����ѧ����Ϣ�����ŷָ�����������䵽ѧ����Ϣ�ṹ����
            token = strtok(line, delim);
            strcpy(students[count].id, token);
            token = strtok(NULL, delim);
            strcpy(students[count].name, token);
            token = strtok(NULL, delim);
            students[count].age = atoi(token);
            token = strtok(NULL, delim);
            strcpy(students[count].gender, token);
            token = strtok(NULL, delim);
            strcpy(students[count].birth, token);
            token = strtok(NULL, delim);
            strcpy(students[count].address, token);
            token = strtok(NULL, delim);
            strcpy(students[count].phone, token);
            token = strtok(NULL, delim);
            // �����ǰ�ַ��ǻ��з�������������ַ�
            if (token[strlen(token) - 1] == '\n') {
                token[strlen(token) - 1] = '\0';
            }
            strcpy(students[count].email, token);
            count++;
        }

        fclose(fp);
    }
}

