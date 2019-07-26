#include<stdio.h>
#include<math.h>
#include<ctype.h>


/*
编程07.26
01.	定义一个表示日期的结构体类型，再分别定义函数完成下列功能：
	计算某一天是对应年的第几天，这一年一共多少天；
	计算两个日期之间相隔的天数。两个日期由键盘输入。
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
02.	九九乘法表
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
03.	如果整数A的全部因子（包括1，不包括A本身）之和等于B；
	且整数B的全部因子（包括1，不包括B本身）之和等于A，
	则将整数A和B称为亲密数。求3000以内的全部亲密数。
思路：首先将整数A的全部因子之和算出，保存在b中，再算出b的
	全部因子之和，判断是否等于a。
*/
#define MAX 3000
void DearDigit()
{
	int a, i, b, n;
	for (a = 1; a<MAX; a++)  /*穷举3000以内的全部整数*/
	{
		for (b = 0, i = 1; i <= a / 2; i++)  /*计算数a的各因子，各因子之和存放于b*/
			if (!(a%i))
				b += i;
		for (n = 0, i = 1; i <= b / 2; i++)  /*计算b的各因子，各因子之和存于n*/
			if (!(b%i))
				n += i;
		if (n == a && a<b)  /*使每对亲密数只输出一次*/
			printf("%3d--%3d    \n", a, b);  /*若n=a，则a和b是一对亲密数，输出*/
	}
}


int main()
{
	//Days();
	//multip1();
	DearDigit();
	return 0;
}
