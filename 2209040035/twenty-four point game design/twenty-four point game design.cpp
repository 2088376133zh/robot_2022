#include <stdio.h>
#include <string.h>
#include <math.h>
 
#define LING 1E-6
#define CONT 4
#define VOLUE 24
 
float num[CONT];  
char E[CONT][20] ;    
bool m_judge = false;   //�ж��Ƿ��н⡣
int count = 0;
 
void Find(int n)
{
 int i = 0, j = 0;
 
 if (n == 1)
 {
  if ( fabs(num[i] - 24) <= LING)
  {
   for (i = 0; i < 20; i++) 
   {
    printf("%c", E[0][i]) ;
   }
   printf("\t\t") ;
   m_judge = true;
   count ++;                       //�������
   if((count % 2)==0)     //ʹ���ʱÿ�ж������ʽ
    printf("\n") ;
  }
 }
 for(i = 0; i < n; i++)    //����
 {
  for (j = i + 1; j < n; j++)  //�������Ĳ��ҽ��м���
  {
   float a, b; 
   char Ea[20], Eb[20];
    
   a = num[i] ;
   b = num[j] ;
   num[j] = num[n - 1];
 
   strcpy(Ea, E[i]) ;
   strcpy(Eb, E[j]) ;
   strcpy(E[j], E[n - 1]) ;
   
   sprintf(E[i], "(%s+%s)", Ea, Eb) ;
   num[i] = a + b;
   Find(n-1);
  
   sprintf(E[i], "(%s-%s)",Ea, Eb) ;
   num[i] = a - b;
   Find(n-1);
   
   sprintf(E[i], "(%s-%s)", Eb, Ea) ;
   num[i] = b - a;
   Find(n-1);
   
   sprintf(E[i], "(%s*%s)", Ea, Eb) ;
   num[i] = a * b;
   Find(n-1);
   
   if (b != 0)
   {
    sprintf(E[i], "(%s/%s)", Ea, Eb) ;
    num[i] = a / b;
    Find(n-1);
   }
   if (a != 0)
   {
    sprintf(E[i], "(%s/%s)", Eb, Ea) ;
    num[i] = b / a;
    Find(n-1);
   }
   num[i] = a;       // ���һ��number[0]
   num[j] = b;       
   strcpy(E[i], Ea) ; 
   strcpy(E[j], Eb) ;
  }
 }
}
 
int Input() //��Ҫ����������
{
 int i, j ;
 printf("�������ĸ���������1����13֮�䣩:\n") ;
 for (i = 0; i < CONT; i++)
 {
  char ch[20], s;
  int a ;
  printf("��%d����:", i+1) ;
  scanf("%f", &num[i]) ;
  a = (int)num[i] ;
  s = char(a + 48);
  ch[0] = s ;
  for (j = 1; j < 20; j++) 
  {
   ch[j] = 0 ;
  }
  strcpy(E[i], ch) ;
 }
 
 printf("\n") ;
 return 0;
}
 
int main()          //������
{
    Input();         //���뺯������������
 Find(CONT) ;     //���Һ������ҳ����
 if(m_judge==true)
 {
  printf("\n�ɹ�:���������п��ܣ�\n") ;
  printf("�ܹ��ļ��㷽������:%d\n", count) ;
 }
 else
 {
  printf("ʧ�ܣ�û�н����") ;
 }
 printf("\n\n\n");
 return Input();
}
 
