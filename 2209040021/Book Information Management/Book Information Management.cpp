#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int count=0;//ȫ�ֱ����������鼮�� 
typedef struct book{//�ṹ�� 
    long bianhao;
    char bookname[20];
    char writer[20];
    char press[20];
    char time[20];
    int money;
}boo;
void gongnengqu(){//�˵�Ŀ¼ 
    
        printf("��ӭʹ��ͼ�����ϵͳ\n�밴��ʾѡ�����¹���\n");
    printf("**********************************\n\n");
    printf("    ¼��ͼ����Ϣ��1\n");
    printf("    ���ͼ����Ϣ��2\n");
    printf("    ��ѯͼ����Ϣ��3\n");
    printf("    �޸�ͼ����Ϣ��4\n");
    printf("    ɾ��ͼ����Ϣ��5\n");
    printf("    ������������ͼ����Ϣ��6\n");
    printf("    �������ͼ����Ϣ��7\n");
    printf("    �˳���0\n\n");
    printf("*********************************\n\n");
}
 
void wenjian1(boo books[]){//�洢�ļ��ģ��������� 
    FILE *fp;
fp=fopen("D:Demo/tushu.txt","w");
fprintf(fp,"ͼ����  ����  ����  ������  ����ʱ��  �۸�\n");
for(int i=0;i<count;i++) 
{
    if(books[i].bookname==NULL)
    break;
    fprintf(fp,"%ld  ",books[i].bianhao);
    fprintf(fp,"%s  ",books[i].bookname);
    fprintf(fp,"%s  ",books[i].writer);
    fprintf(fp,"%s  ",books[i].press);
    fprintf(fp,"%s  ",books[i].time);
    fprintf(fp,"%d  ",books[i].money);
    fprintf(fp,"\n");
}
fclose(fp);
}
void wenjian2(boo books[]){//�洢�ļ��ģ������������� 
    FILE *fp;
fp=fopen("D:Demo/tushu1.txt","w");
fprintf(fp,"ͼ����  ����  ����  ������  ����ʱ��  �۸�\n");
for(int i=0;i<count;i++) 
{
    if(books[i].bookname==NULL)
    break;
    fprintf(fp,"%ld  ",books[i].bianhao);
    fprintf(fp,"%s  ",books[i].bookname);
    fprintf(fp,"%s  ",books[i].writer);
    fprintf(fp,"%s  ",books[i].press);
    fprintf(fp,"%s  ",books[i].time);
    fprintf(fp,"%d  ",books[i].money);
    fprintf(fp,"\n");
}
fclose(fp);
}
void paixu1(boo books[]);
void luru(boo books[]){//���Լ�Ҫ������鼮����¼�룬¼��ֻ�ܽ���һ�Σ��ٴν��л���и��� 
    for(int i=0;;i++)
    {
        if(i>0)
        {
        printf("���Ҫֹͣ¼�����0�������������1:");
        int q;
        scanf("%d",&q);
        if(q==0) break;
    }
    printf("��������ͼ����:");
    scanf("%ld",&books[i].bianhao); 
        printf("����������:");
    scanf("%s",&books[i].bookname); 
        printf("������������:");
    scanf("%s",&books[i].writer); 
        printf("�������������:");
    scanf("%s",&books[i].press); 
        printf("�����������ʱ��:");
    scanf("%s",&books[i].time); 
        printf("��������۸�:");
    scanf("%d",&books[i].money); 
    count++; 
    system("cls");//���� 
}
paixu1(books);
wenjian1(books);
}
void paixu1(boo books[]) {
    char a[20];
    int t;
    long x;
    if(count>1){
    for(int i=0;i<count-1;i++){
        for(int j=i+1;j<count;j++)
        if(books[i].bianhao>books[j].bianhao){
                            t=books[i].money;books[i].money=books[j].money;books[j].money=t;
                x=books[i].bianhao;books[i].bianhao=books[j].bianhao;books[j].bianhao=x;
                strcpy(a,books[i].bookname);strcpy(books[i].bookname,books[j].bookname);strcpy(books[j].bookname,a);
                strcpy(a,books[i].writer);strcpy(books[i].writer,books[j].writer);strcpy(books[j].writer,a);
                strcpy(a,books[i].press);strcpy(books[i].press,books[j].press);strcpy(books[j].press,a);
                strcpy(a,books[i].time);strcpy(books[i].time,books[j].time);strcpy(books[j].time,a);
        }
    }
}
}
void tianjia(boo books[]){//��� �����鼮������� 
    printf("��������ͼ����:");
    scanf("%ld",&books[count].bianhao); 
        printf("����������:");
    scanf("%s",&books[count].bookname); 
        printf("������������:");
    scanf("%s",&books[count].writer); 
        printf("�������������:");
    scanf("%s",&books[count].press); 
        printf("�����������ʱ��:");
    scanf("%s",&books[count].time); 
        printf("��������۸�:");
    scanf("%d",&books[count].money); 
    printf("��ӳɹ�\n");
    system("pause"); 
    paixu1(books);
    FILE *fp;
    fp=fopen("D:Demo/tushu.txt","a");
    fprintf(fp,"%ld  ",books[count].bianhao);
    fprintf(fp,"%s  ",books[count].bookname);
    fprintf(fp,"%s  ",books[count].writer);
    fprintf(fp,"%s  ",books[count].press);
    fprintf(fp,"%s  ",books[count].time);
    fprintf(fp,"%d  ",books[count].money);
    fprintf(fp,"\n");
    fclose(fp);
    count++;
}
void chaxun(boo books[]){//��������Ҫ���鼮���в�ѯ 
    printf("��������Ҫ��ѯ������:");
    char abc[20];
    int flag=0;
    scanf("%s",&abc); 
    for(int i=0;i<101;i++)
    {
        char a;
        if(books[i].money==NULL)
        break;
        if(strcmp(books[i].bookname,abc)==0)//�Ƚ��ַ��� 
        {
            flag=1;
            printf("ͼ����Ϊ:%ld\n",books[i].bianhao);
            printf("����Ϊ:%s\n",books[i].bookname);
            printf("������Ϊ:%s\n",books[i].writer);
            printf("������Ϊ:%s\n",books[i].press);
            printf("����ʱ��Ϊ:%s\n",books[i].time);
            printf("�۸�Ϊ:%d\n",books[i].money);
            system("pause");
            break;
        }
    }
    if(flag==0)
    printf("���鼮Ϊ�ҵ��򲻴��ڡ�\n");
    system("pause"); 
}
void xiugai(boo books[]){//��������Ҫ���鼮�����޸� 
        printf("��������Ҫ��ѯ��������");
    char abc[20];
    scanf("%s",&abc); 
    for(int i=0;i<101;i++)
    {
        char a;
        if(books[i].money==NULL)
        break;
        if(strcmp(books[i].bookname,abc)==0)
        {
            printf("ԭͼ����Ϊ:%ld\n",books[i].bianhao);
            printf("ԭ����Ϊ%s\n",books[i].bookname);
            printf("������������:\n"); 
            scanf("%s",&books[i].bookname);
            printf("ԭ������Ϊ:%s\n",books[i].writer);
            printf("������������:\n"); 
            scanf("%s",&books[i].writer);
            printf("ԭ������Ϊ:%s\n",books[i].press);
            printf("�������³�����:\n"); 
            scanf("%s",&books[i].press);
            printf("ԭ����ʱ��Ϊ:%s\n",books[i].time);
            printf("�������³���ʱ��\n"); 
            scanf("%s",&books[i].time);
            printf("ԭ�۸�Ϊ:%d\n",books[i].money);
            printf("�������¼۸�:\n");
            scanf("%d",&books[i].money); 
            system("pause");
            break;
        }
    }
wenjian1(books);    
}
void shanchu(boo books[]){//ɾ���鼮 
    printf("��������Ҫɾ�������:\n");
    int x,i,flag=1;
    scanf("%ld",&x); 
    for(;i<count;i++){
     if(x==books[i].bianhao&i<count-1){
         printf("��%s���鼮��ɾ��\n",books[i].bookname);
         for(int z=i;z<count;z++){
         books[z].bianhao=books[z+1].bianhao;
         strcpy(books[z].bookname,books[z+1].bookname);
         strcpy(books[z].writer,books[z+1].writer);
         strcpy(books[z].press,books[z+1].press);
         strcpy(books[z].time,books[z+1].time);
         books[z].money=books[z+1].money;
         count--;}    flag=0;
        system("pause");break;}
     else if(x==books[i].bianhao&i==count-1){
          printf("��%s���鼮��ɾ��\n",books[i].bookname);flag=0;    count--;    
    system("pause");break;
          }
     }
if(flag==1)
{
printf("�鼮δ�ҵ�\n");
system("pause");} 
paixu1(books);
wenjian1(books);
}
 
void paixu(boo books[]){//�Գ������������ 
    char a[20];
    int t;
    long x;
    for(int i=0;i<count-1;i++){
        for(int j=i+1;j<count;j++){
            if((strcmp(books[i].press,books[j].press))>0)
            {
                t=books[i].money;books[i].money=books[j].money;books[j].money=t;
                x=books[i].bianhao;books[i].bianhao=books[j].bianhao;books[j].bianhao=x;
                strcpy(a,books[i].bookname);strcpy(books[i].bookname,books[j].bookname);strcpy(books[j].bookname,a);
                strcpy(a,books[i].writer);strcpy(books[i].writer,books[j].writer);strcpy(books[j].writer,a);
                strcpy(a,books[i].press);strcpy(books[i].press,books[j].press);strcpy(books[j].press,a);
                strcpy(a,books[i].time);strcpy(books[i].time,books[j].time);strcpy(books[j].time,a);
            }
        }
    }
    printf("���������\n");
    printf("ͼ����  ����  ����  ������  ����ʱ��  �۸�\n");
    for(int i=0;i<count;i++)
    {
        printf("%ld  ",books[i].bianhao);
        printf("%s  ",books[i].bookname);
        printf("%s  ",books[i].writer);
        printf("%s  ",books[i].press);
        printf("%s  ",books[i].time);
        printf("%d  \n",books[i].money);
    }
    system("pause"); 
    wenjian2(books);
    paixu1(books);
    wenjian1(books);
}
void read(boo books[])//�������е��鼮������� 
{
    FILE *fp;
    int i;
    if ((fp = fopen("D:Demo/tushu.txt","r")) == NULL) 
    { 
        printf("Failure to open 1.txt!\n");
        exit(0);
    }
char b[1000];
        fscanf(fp,"%[^n]",b);//��������ļ��Ķ��� 
        printf("%s",b);    
    system("pause");
    fclose(fp);
    
 }
int main(){
    boo books[100];
    for(;;){
    gongnengqu();
    int key=0;
    scanf("%d",&key);
    switch(key){
        case 1:printf("��¼�롿\n");luru(books);break;
        case 2:printf("����ӡ�\n");tianjia(books);break;
        case 3:printf("����ѯ��\n");chaxun(books);break;
        case 4:printf("���޸ġ�\n");xiugai(books);break;
        case 5:printf("��ɾ����\n");shanchu(books);break;
        case 6:printf("������\n");paixu(books);break;
        case 7:printf("�������\n");read(books);break;
        case 0:printf("���˳���\n");
                printf("�˳��ɹ�!��л����ʹ�ã�\n");
                system("pause");//��ͣ������������� 
                   exit(0);
                break;
        default:
                printf("��error��\n");
    } 
    system("cls");
    }
    return 0;
}
