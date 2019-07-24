#include<stdio.h>
#include<iostream>
#include<cmath>
#include<complex>
#include<string.h>
#include<assert.h>
#include<iomanip>
#include<ctype.h>
using namespace std;

#if 0
/*
给出一个不多于五位的正整数，要求：
（1）求出它是几位数
（2）分别输出每一位数字
（3）按逆序输出每一位数字
*/
unsigned char CountNumber(int digit)
{
	unsigned char count = 0;
	while (digit != 0)
	{
		digit /= 10;
		count++;
	}
	return count;
}

void PrintOrder(int digit)
{
	unsigned char figures = CountNumber(digit);
	int power = (int)pow((float)10, (float)figures - 1);//获取最高位的权重
	int temp;

	if (digit == 0)
	{
		cout << 0;
	}

	if (digit < 0)
	{
		cout << "-";
		digit = -digit;
	}

	while (power != 0)
	{
		temp = digit/power;
		digit %= power;
		power /= 10;
		cout << temp;
	}
	cout << endl;
}

void PrintRev(int digit)
{
	if (digit == 0)
	{
		cout << 0 ;
	}
	if (digit < 0)
	{
		digit = -digit;
		cout << "-";
	}

	while (digit != 0)
	{
		cout << digit % 10;
		digit /= 10;
	}
	cout << endl;
}

/*
输入两个正整数，求其最大公约数，和最小公倍数
*/
void Div_Mul(int a, int b)
{
	assert(a*b != 0);
	int m = a*b;
	int tmp;
	if (a < b)
	{
		tmp = a;
		a = b;
		b = tmp;
	}
	while (a%b != 0)
	{
		tmp = a%b;
		a = b;
		b = tmp;
	}
	cout << "最大公约数：" << b << endl;
	cout << "最小公倍数：" << m / b << endl;
}
/*
求Sn = a+aa+aaa+……+a…a 之和。
*/

int Sum_a(int a, int n)
{
	int tmp = 0;
	int sum = 0;
	for (int i = 0; i < n;i++)
	{
		tmp = tmp * 10 + a;
		sum += tmp;
	}
	return sum;
}
/*
求阶乘和
*/
static long long Fac(int n)
{
	long long sum = 0;
	for(int i = 1 ; i <= n ;i++)
	{ 
		long long tmp = 1;
		for (int j = 1; j <= i; j++)
		{
			tmp *= j;
		}
		sum += tmp;
	}
	return sum;
}

/*
中国古代数学家张丘建在他的《算经》中提出了一个著名的“百钱买百鸡问题”，
鸡翁一，值钱五，鸡母一，值钱三，鸡雏三，值钱一，百钱买百鸡，问翁、母、雏各几何？
*/
void chicken()
{
	int cock, hen, chick;   /*定义变量为基本整型*/
	for (cock = 0; cock <= 20; cock++)   /*公鸡范围在 0~20 之间*/
		for (hen = 0; hen <= 33; hen++)   /*母鸡范围在 0~33 之间*/
			for (chick = 3; chick <= 99; chick++)   /*小鸡范围在 3~99 之间*/
				if (5 * cock + 3 * hen + chick / 3 == 100)   /*判断钱数是否等于 100*/
					if (cock + hen + chick == 100)   /*判断购买的鸡数是否等于 100*/
						if (chick % 3 == 0)   /*判断小鸡数是否能被 3 整除*/
							printf("公鸡：%d，母鸡：%d，小鸡：%d\n", cock, hen, chick);
}

/*
编程：07/18
01. 如果一个渔夫从 2011 年 1 月 1 日开始每三天打一次渔，两天晒一次网，
	编程实现当输入 2011 年 1 月 1 日以后的任意一天，输出该渔夫是在打渔还是在晒网。
思路： 首先判断输入的年份是否是闰年，闰年366天，平年365天，再求出输入的日期距离2011年1月1日
有多少天，再用算出来的天数对5 取余，余数为1，2，3就是在打鱼，其他就是在晒网。
*/
bool Isleap(int a)
{
	if (a % 4 == 0 && a % 100 != 0 || a % 400 == 0)
		return true;
	else
		return false;
}
int days(int year, int month, int day)
{
	int sum = 0;
	int a[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };//闰年的每月的天数
	int b[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//非闰年每月的天数
	
	if (Isleap(year))//是闰年，就要加等闰年 前month-1 个月的天数
	{
		for (int i = 0; i <= month; i++)
		{
			sum += a[i];
		}
	}
	else
	{
		for (int i = 0; i <= month; i++)
		{
			sum += b[i];
		}
	}

	for (int i = 2011; i <= year; i++)
	{
		if (Isleap(year))
			sum += 366;
		sum += 365;
	}
	return sum;
}

void GetFish()
{
	int year;
	int month;
	int day;
	cin >> year >> month >> day;
	int Days = days(year, month, day);
	if (Days % 5 >= 1 && Days % 5 < 4)
	{
		cout << "打鱼" << endl;
	}
	else
	{ 
		cout << "晒网" << endl;
	}
}
/*
编程：07/18
02. 根据输入的三角形的三条边判断三角形的类型，并输出其面积和类型。
思路：	1.根据三边长度判断是否是三角形
		2.判断是否有三边相等，若有则为等边三角形
		  判断是否有两边相等，若有则为等腰三角形
		  判断是否两边平方和等于第三条边的平方，则为直角三角形
		  否则为普通三角形
*/

void Triangle(int a,int b,int c)
{
	assert(a > 0 && b > 0 && c > 0);

	if (!(a + b > c && a + c > b && a + b > c))
	{
		cout << "三角形不存在" << endl;
		return;
	}
	float p = (float)(a + b + c) / 2;
	cout << "面积：" << (float)sqrt(p*((p - a)*(p - b)*(p - c))) << endl;
	cout << "类型：";
	if (a == b && a == c)
	{
		cout << "等边三角形" << endl;
	}
	else if (a == b || a == c || b == c)
	{
		cout << "等腰三角形" << endl;
	}

	else if ((a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a))
	{
		cout << "直角三角形" << endl;
	}

	else
	{
		cout << "其他三角形" << endl;
	}
}



/*
编程：07/18
03. 自然底数 e=2.718281828…，e 的计算公式如下：
		e=1+1/1!+1/2!+1/3!+…
	要求当最后一项的值小于 10^-10 时结束。
思路：使用循环进行累加,判断下一次的值是否小于 10^-10，小于则退出
*/

void GetE()
{
	double e = 1.0, n = 1.0;
	int i = 1;
	while (1/n > 1e-10)
	{
		e += 1 / n;
		i++;
		n = i*n;
	}
	cout << "e:" << e << endl;
}

/*
编程07.20
01.任意的整数，当从左向右读与从右向左读是相同的，且为素数时，称为回文素数。求 1000 以内的所有回文素数。
思路：写两个函数，一个函数判断是否是回文，
	 第二个函数判断是否素数，并输出	
*/
bool IsPalindrome(int digit)
{
	int num = digit;
	bool res = false;
	int tmp = 0;
	while (digit != 0)
	{
		tmp = tmp * 10 + digit % 10;
		digit /= 10;
	}
	if (num == tmp)
	{
		res = true;
	}
	return res;
}

bool IsPrime(int n) 
{
	if (n <= 3) {
		return n > 1;
	}
	for (int i = 2; i < n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

void Palin_prime(int num)
{
	while (num != 0 && num >= 10)
	{
		if (IsPalindrome(num))
		{
			if(IsPrime(num))
			{
				cout << num << " "; 
			}
		}
		num--;
	}
	cout << endl;
}
/*
02. 设有一矩阵为 m×n 阶（即 m 行 n 列），第 i 行 j 列的元素是 a(i,j)，
需要将该矩阵转置为 n×m 阶的矩阵，使其中元素满足 b(j,i)=a(i,j)。
思路： 二维数组保存矩阵,键盘输入矩阵的行列数，
		定义两个数组，交换对应位置上的值，数组最大为100*100
*/

void RevMatrix()
{
	int row ; //行
	int col ; //列
	int a[101][101];
	int b[101][101];
	cout << "enter array row and col:" << endl;
	cin >> row >> col;
	if(row <= 0 || col <= 0)
	{
		return;
	}
	cout << "enter array elements:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "Array pre-transpose:" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setiosflags(ios::left) << setw(5) << a[i][j];
		}
		cout <<  endl;
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			b[j][i] = a[i][j];
		}
	}
	cout << "After array transpose" << endl;
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < row; j++)
		{
			cout <<setiosflags(ios::left) << setw(5) << b[i][j];
		}
		cout << endl;
	}	
}

/*
03.	假设一对兔子的成熟期是一个月，即一个月可长成成兔，那么，
	如果每对成兔每个月都生一对小兔，一对新生的小兔从第二个
	月起就开始生兔子，试问从一对兔子开始繁殖，以后每个月会
	有多少对兔子？
*/

void rabbit()
{
	int month;
	int r1 = 1;
	int r2 = 1;
	int sum = 1;
	cout << "entry month:" << endl;
	cin >> month;
	cout << "the rabbit is:";
	if (month == 1 || month == 2)
	{
		cout << sum << endl;
	}
	else if(month > 2 && month <= 12)
	{
		for (int i = 3; i <= month; i++)
		{
			sum = r1 + r2;
			r1 = r2;
			r2 = sum;
		}
		cout << sum << endl;
	}
	else
	{
		cout << "error!" << endl;
	}
}


/*
04.	一只兔子躲进了 10 个环形分布的洞的某一个，狼在第一个洞没有找到兔子，
	就隔一个洞，到第三个洞去找，也没有找到，就隔两个洞，到第六个洞去找，
	以后每次多隔一个洞 去找兔子……这样下去，结果一直找不到兔子，
	请问：兔子可能躲在哪个洞中？
思路:采用穷举法，定义10个元素的数组都置为0，代表10个洞，
	采用循环对10取余，如果访问过，将元素置为1 ，最后遍历
	数组，没有被修改过，就说明兔子可能藏在哪个洞(设置查找次数为100)
*/
void get_rabbit()
{
	bool pos[10] = { 0 };
	int lang = 0;
	for (int i = 0; i < 10; i++)
	{
		pos[lang] = true;
		lang++;
		lang += i;
		lang = lang % 10;
	}
	for (int i = 0; i<10; i++)
		if (!pos[i])
			cout << "兔子可能在第" <<  i + 1 << "洞中" << endl;
}

/*
编程07.21
01.	张、王、李三家各有三个小孩。一天，三家的九个孩子在一起比赛短跑，
	规定不分年龄大小，跑第一得 9 分，跑第二得 8 分，依次类推。
	比赛结果显示各家的总分相同，且这些孩子没有同时到达终点的，
	也没有一家的两个或三个孩子获得相连的名次。已知获第一名的
	是李家的孩子，获第二名的是王家的孩子。获得最后一名的是谁家的孩子？
思路：使用二维数组来存放九个孩子的分数，第一行存放张，第二行存放王
第三行存放李。
*/
void LastChild()
{
	int score[4][4];
	int i, j, k, who;
	score[1][1] = 7;
	score[2][1] = 8;
	score[3][1] = 9;
	for (i = 4; i < 6; i++)
		for (j = 4; j < 7; j++)
			for (k = 4; i!=j&&k<7; k++)
				if (k != i&&k != j && 15 - i - score[1][1] != 15 - j - score[2][1]
					&& 15 - i - score[1][1] != 15 - k - score[3][1]
					&& 15 - j - score[2][1] != 15 - k - score[3][1])
				{
					score[1][2] = i; score[1][3] = 15 - i - 7;
					score[2][2] = j; score[2][3] = 15 - j - 8;
					score[3][2] = k; score[3][3] = 15 - k - 9;
				}
	for (who = 0, i = 1; i <= 3; i++, printf("\n"))
		for (j = 1; j <= 3; j++)
		{
			printf("%3d", score[i][j]);
			if (score[i][j] == 1)
				who = i;
		}
	if (who == 1)
		cout << "最后一名是张家孩子" << endl;
	else if (who == 2)
		cout << "最后一名是王家孩子" << endl;
	else
		cout << "最后一名是李家孩子" << endl;
}
/*
02.如何又快、又准确地统计一篇英文文章中的单词数？
思路：当前为字母，并且下一个为空格
*/
void totalWords(char * str)
{
	assert(str != NULL);
	int count = 0;
	while (*str != '\0')
	{
 		if (isalpha(*str)&&(isspace(*(str+1)) || *(str+1) == '\0'))
		{
			count++;			
		}
		str++;
	}
	printf("%d\n", count);
}

/*
编程07.22
01.	在本实例中要求设计一个加密和解密算法。在对一个指定的字符串加密之后，
	利用解密函数能够对密文解密，显示明文信息。加密的方式是将字符串中每
	个字符加上它在字符串中的位置和一个偏移值 5。以字符串“mrsoft”为例，
	第一个字符“m”在字符串中的位置为 0，那么它对应的密文是“'m'+0+5"，即 r。
思路：编写两个函数：加密函数和解密函数
*/
void Screct(char * str)
{
	char screct[128] = { 0 };
	int i = 0;
	int j = 0;
	while (*str != '\0')
	{
		screct[i] = *str + i + 5;
		i++;
		str++;
	}
	screct[i] = '\0';
	
	while (screct[j] != 0)
	{
		printf("%c", screct[j]);
		j++;
	}
	printf("\n");
}
#endif
/*
编程07.23
01.	编号为 1，2，3，…，n 的 n 个人围坐一圈，任选一个正整数 m 作为报数上限值，
	从第一个人开始按顺时针方向报数，报数到 m 时停止，报数为 m 的人出列。从出
	列人的顺时针方向的下一个人开始又从 1 重新报数，如此下去，直到所有人都全部
	出列为止。(约瑟夫环)
思路：
	

*/
#define MAX 100
void Josephus(int a[],int n,int m)
{	//n:总人数 m:停止
	int i;
	int	j;//统计报的数
	int	k = 0;
	for (i = 0; i<n; i++)
	{
		j = 1;
		while (j<m)
		{
			while (a[k] == 0)
				k = (k + 1) % n;
			j++;
			k = (k + 1) % n;
		}

		while (a[k] == 0)
			k = (k + 1) % n;
		printf("%d ", a[k]);
		a[k] = 0;
	}
}
void JosephusOutput(int n,int m)
{
	int a[MAX];
	for (int i = 0; i<n; i++)
		a[i] = i + 1;

	Josephus(a, n, m);
	printf("\n");
}


int ysfdg(int sum, int value, int n)
{
	if (n == 1)
		return (sum + value - 1) % sum;
	else
		return (ysfdg(sum - 1, value, n - 1) + value) % sum;
}

int main()
{
	/*int a = 123456789;
	cout << (int)CountNumber(a) << endl;
	PrintOrder(a);
	PrintRev(a);*/
	//Div_Mul(134,13);
	//cout << Sum_a(2, 5) << endl;
	//cout << Fac(4) << endl;
	//cout << IsFlowersNum(153) << endl;
	//chicken();
	//GetFish();
	//Triangle(5, 4, 3);
	//GetE();
	//Palin_prime(1000);
	//RevMatrix();
	//rabbit();
	//get_rabbit();
	//LastChild();
	//totalWords("I am a student");
	//Screct("hello");
	JosephusOutput(100,10);
	return 0;
}

