#include<stdio.h>
#include<math.h>
#include<ctype.h>


/*
���07.26
01.	����һ����ʾ���ڵĽṹ�����ͣ��ٷֱ��庯��������й��ܣ�
	����ĳһ���Ƕ�Ӧ��ĵڼ��죬��һ��һ�������죻
	������������֮����������������������ɼ������롣
*/
typedef struct Date
{
	int year;
	int month;
	int day;
}D;

void Days()
{
	int totalday = 365;
	int sumday = 0;
	int month[13] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	D d;
	printf("entry year month day:\n");
	scanf_s("%d %d %d", &d.year, &d.month, &d.day);
	if (d.year % 4 == 0 && d.year % 100 != 0 || d.year % 400 == 0)
	{
		totalday = 366;
		month[1] = 29;
	}
	for (int i = 0; i < d.month; i++)
	{
		sumday += month[i];
	}
	sumday += d.day;
	printf("%d %d\n", sumday, totalday);
}
/*
02.	�žų˷���
*/
void multip()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			printf(" %d*%d=%-2d\t", i, j, i*j);
		}
		printf("\n");
	}
}
void multip1()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (i < j)
			{
				printf("      ");
			}
			else
				printf(" %d*%d=%-2d", i, j, i*j);
		}
		printf("\n");
	}
}
/*
03.	�������A��ȫ�����ӣ�����1��������A����֮�͵���B��
	������B��ȫ�����ӣ�����1��������B����֮�͵���A��
	������A��B��Ϊ����������3000���ڵ�ȫ����������
˼·�����Ƚ�����A��ȫ������֮�������������b�У������b��
	ȫ������֮�ͣ��ж��Ƿ����a��
*/
#define MAX 3000
void DearDigit()
{
	int a, i, b, n;
	for (a = 1; a<MAX; a++)  /*���3000���ڵ�ȫ������*/
	{
		for (b = 0, i = 1; i <= a / 2; i++)  /*������a�ĸ����ӣ�������֮�ʹ����b*/
			if (!(a%i))
				b += i;
		for (n = 0, i = 1; i <= b / 2; i++)  /*����b�ĸ����ӣ�������֮�ʹ���n*/
			if (!(b%i))
				n += i;
		if (n == a && a<b)  /*ʹÿ��������ֻ���һ��*/
			printf("%3d--%3d    \n", a, b);  /*��n=a����a��b��һ�������������*/
	}
}


int main()
{
	//Days();
	//multip1();
	DearDigit();
	return 0;
}
