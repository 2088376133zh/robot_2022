#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    srand(time(NULL));
    int score = 0;
    
    
	for (int i = 0; i < 10; i++) {
	int num1,num2,result, answer, attempt = 0;
	
	char operator1;
		do{
			num1 = generateRandomNumber(0, 50);
			num2 = generateRandomNumber(0, 50);
        
			int operation = generateRandomNumber(1, 2);
			if (operation == 1) {
				operator1 = '+';
				result = num1 + num2;
			} else {
				operator1 = '-';
				if(num1>num2)
					result = num1 - num2;
				else{
					int temp=num1;
					num1=num2;
					num2=temp;
					result = num1 - num2;
				}
			}
			if(result >= 0 && result <= 50)
				break;
        }while(true);

        printf("���� %d:\n", i+1);
        printf("%d %c %d = ?\n", num1, operator1, num2);
        
        do {
            printf("��������Ĵ�: ");
            if (scanf("%d", &answer) != 1) {
                printf("������Ч��������һ����Ч��������\n");
                while (getchar() != '\n');
                continue;
            }
            
            attempt++;
            
            if (answer == result) {
                if (attempt == 1) {
                    score += 10;
                } else if (attempt == 2) {
                    score += 7;
                } else if (attempt == 3) {
                    score += 5;
                }
                
                break;
            } else {
                printf("�𰸴��������ԡ�\n");
            }
        } while (attempt < 3);
        
        if (attempt >= 3) {
            printf("������ȷ���� %d\n", result);
        }
        
        printf("\n");
    }
    
    printf("������յ÷���: %d\n", score);
    
    return 0;
}