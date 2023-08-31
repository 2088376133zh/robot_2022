#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stunode
{
	char sport[20];
	char sex[10];
	char name[10];
	char college[20];
	char grade[10];
	int rank;
	struct stunode* next;
}STU;  			/*����������Ľṹ������struct stunode,ȡ����STU*/
STU head;		/
char stu[20][20];		/
void maininterface();
void createList();
void printall();
void findperson();
void findcollege();
void freelist();
void findcollogescore();
void modify();
void allscore();
void getprize();
int getscore();
int N, M, W;		/*��������N��M��W�����ڳ�ʼ����Ų���Ժϵ���������Ӿ�����Ŀ����Ů�Ӿ�����Ŀ��*/
int k = 0;		/*���ڴ�������ʱ�ļ����������״δ���������ٴδ�������*/
int main(int argc, char* argv[])
{
	int i;
	int select;
	head.next = NULL;		/*��ͷ����next��ΪNULL*/
	printf("\t\t\t------------------------\n");
	printf("\t\t\t*******ϵͳ��ʼ��*******\n");
	printf("\t\t\t1.���������Ժϵ������");
	scanf("%d", &N);
	printf("\t\t\t2.���������Ӿ�����Ŀ����");
	scanf("%d", &M);
	printf("\t\t\t3.������Ů�Ӿ�����Ŀ����");
	scanf("%d", &W);
	printf("\t\t\t4.�����������Ժϵ����");
	for (i = 0;i < N;i++)
	{
		scanf("%s", &stu[i]);
	}
	printf("\n\t\t\t-----------------------\n");
	printf("\t\t\t  �˶������ѧԺ�У�");
	for (i = 0;i < N;i++)
	{
		printf("%s ", stu[i]);
	}
	printf("\n\t\t\t");
	system("pause");
	while (1)
	{
		maininterface();
		printf("\n*��ѡ����Ҫ�Ĳ�����");
		scanf("%d", &select);
		fflush(stdin);	/*������̻�����*/
		switch (select)	/*�����û�ѡ�񣬵�����Ӧ������ɲ���*/
		{
		case 1:createList();break;
		case 2:findperson();break;
		case 3:findcollege();break;
		case 4:findcollogescore();break;
		case 5:allscore();break;
		case 6:getprize();break;
		case 7:modify();break;
		case 8:printall();break;
		case 0:freelist();exit(0);
		default:printf("�������\n");
		}
		system("pause");
	}
	return 0;
}
/*�������ܣ���ʾ�˵�*/
void maininterface()
{
	system("cls");	/*����*/
	printf("\t\t--------------------------\n");
	printf("\t\t******�˶������ϵͳ******\n");
	printf("\t\t1.������Ŀ����Ϣ\n");
	printf("\t\t2.��ѯ���˵ı����ɼ�\n");
	printf("\t\t3.��ѯԺϵ�ı�����Ϣ\n");
	printf("\t\t4.��ѯԺϵ�ı����ɼ�\n");
	printf("\t\t5.���������ֱܷ���\n");
	printf("\t\t6.�鿴����Ŀ���˶�Ա��Ϣ\n");
	printf("\t\t7.�޸���Ŀ��Ϣ\n");
	printf("\t\t8.��ʾ������Ϣ\n");
	printf("\t\t0.�˳�\n");
	printf("\t\t--------------------------\n");
	return;
}