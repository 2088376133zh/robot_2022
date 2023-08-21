#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM 10
typedef struct
{
	int a[NUM];
	int b[NUM];
	char oper[NUM];
	int ans[NUM];
}StuTest;

StuTest CreateStuTest();
int add(int a, int b);
int sub(int a, int b);
void PutAndJudge(StuTest S);

StuTest CreateStuTest() {
	StuTest S;
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; i++) {
		S.oper[i] = (rand() % 2) ? '+' : '-';
		do {
			S.a[i] = rand() % 50;
			S.b[i] = rand() % 50;
			switch (S.oper[i]) {
			case '+':S.ans[i] = add(S.a[i], S.b[i]); break;
			case '-':S.ans[i] = sub(S.a[i], S.b[i]); break;
			}
		} while (S.ans[i] > 50 || S.ans[i] < 0);
	}
	return S;
}

int add(int a, int b) {
	return a + b;
}

int sub(int a, int b) {
	return a - b;
}

void PutAndJudge(StuTest S) {
	int ans, count = 0, score = 0;
	for (int i = 0; i < 10; i++) {
		count = 0;
		do {
			printf("%d %c %d = ", S.a[i], S.oper[i], S.b[i]);
			scanf("%d", &ans);
			if (ans == S.ans[i]) {
				switch (count) {
				case 0: score += 10; break;
				case 1: score += 7; break;
				case 2: score += 5; break;
				}
				printf("��ϲ��ش���ȷ��Ŀǰ�ĵ÷� %d��\n\n", score);
				break;
			}
			else {
				count++;
				if (count < 3) printf("�𰸴������������룡�㻹��%d�λ���\n\n", 3 - count);
				else printf("�𰸴��󣬱�����ȷ���� %d\n���������һ��\n\n", S.ans[i]);
			}
		} while (count < 3);
	}
	printf("-------------------------------\n");
	printf("�����β��Ե��ܷ��� %d ��", score);
}

int main() {
	printf("Сѧ������ϵͳ\n");
	printf("-------------------------------\n");
	StuTest S = CreateStuTest();
	PutAndJudge(S);
	system("pause");
}
