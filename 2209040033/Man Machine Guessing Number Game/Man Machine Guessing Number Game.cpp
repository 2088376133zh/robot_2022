#include<stdio.h>
#include<time.h>
#include<windows.h>
int check(int n, int *s)
{
	int i=3,t;
	t=n;
	while (n)
	{
		s[i] = n%10;
		if (s[i]==0)
			return 0;
		n /= 10;
		i--;
	}
	if (s[0]!=s[1]&&s[0]!=s[2]&&s[0]!=s[3] && s[1]!=s[2]&&s[1]!=s[3] && s[2]!=s[3])
		return t;
    return 0;
}
int main()
{
	int number,numberplay,a[4],b[4];
	int A=0,B=0,i,j,t=0;
    srand(time(NULL));
	printf("����������֣�");
	while (1) //
	{
		number = rand() % (10000 - 1000 + 1) + 1000; //�������Χ��% ����� + С����
		number = check(number, a);//���ɺϷ���
		if (number)
		{
			break;
		}
	}
    while (1)//�������������
	{
		A=B=0;
		scanf("%d",&numberplay);
		numberplay = check(numberplay, b);
		//���벻�Ϸ�
		if (!numberplay)
		{
			printf("��������λ����ͬ�Ҷ���Ϊ0������\n");
			continue;
		}
		printf("%d %d\n",number,numberplay);
		//λ����ͬ��������ͬ
		for (i=0;i<4;i++)
		{
			if (a[i]==b[i])
				A++;
		}
		//������ͬ��λ�ò�ͬ
		for (i=0;i<3;i++)
		{
			for (j=i+1;j<4;j++)
			{
				if (a[i]==b[j]&&i!=j)
					B++;
			}
		}
		printf("���ν����\nλ����ͬ��������ͬ������%d\n������ͬ��λ�ò�ͬ������%d\n",A,B);
		t=t+1;
		if (A==4)
		{
			printf("��ȷ!�Ҵ���Ϊ��%d\n",t);
			break;
		}
	}
	return 0;
}
