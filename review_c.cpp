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
����һ����������λ����������Ҫ��
��1��������Ǽ�λ��
��2���ֱ����ÿһλ����
��3�����������ÿһλ����
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
	int power = (int)pow((float)10, (float)figures - 1);//��ȡ���λ��Ȩ��
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
�����������������������Լ��������С������
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
	cout << "���Լ����" << b << endl;
	cout << "��С��������" << m / b << endl;
}
/*
��Sn = a+aa+aaa+����+a��a ֮�͡�
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
��׳˺�
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
�й��Ŵ���ѧ�����������ġ��㾭���������һ�������ġ���Ǯ��ټ����⡱��
����һ��ֵǮ�壬��ĸһ��ֵǮ������������ֵǮһ����Ǯ��ټ������̡�ĸ���������Σ�
*/
void chicken()
{
	int cock, hen, chick;   /*�������Ϊ��������*/
	for (cock = 0; cock <= 20; cock++)   /*������Χ�� 0~20 ֮��*/
		for (hen = 0; hen <= 33; hen++)   /*ĸ����Χ�� 0~33 ֮��*/
			for (chick = 3; chick <= 99; chick++)   /*С����Χ�� 3~99 ֮��*/
				if (5 * cock + 3 * hen + chick / 3 == 100)   /*�ж�Ǯ���Ƿ���� 100*/
					if (cock + hen + chick == 100)   /*�жϹ���ļ����Ƿ���� 100*/
						if (chick % 3 == 0)   /*�ж�С�����Ƿ��ܱ� 3 ����*/
							printf("������%d��ĸ����%d��С����%d\n", cock, hen, chick);
}

/*
��̣�07/18
01. ���һ������ 2011 �� 1 �� 1 �տ�ʼÿ�����һ���棬����ɹһ������
	���ʵ�ֵ����� 2011 �� 1 �� 1 ���Ժ������һ�죬�����������ڴ��滹����ɹ����
˼·�� �����ж����������Ƿ������꣬����366�죬ƽ��365�죬�������������ھ���2011��1��1��
�ж����죬�����������������5 ȡ�࣬����Ϊ1��2��3�����ڴ��㣬����������ɹ����
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
	int a[] = { 31,29,31,30,31,30,31,31,30,31,30,31 };//�����ÿ�µ�����
	int b[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };//������ÿ�µ�����
	
	if (Isleap(year))//�����꣬��Ҫ�ӵ����� ǰmonth-1 ���µ�����
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
		cout << "����" << endl;
	}
	else
	{ 
		cout << "ɹ��" << endl;
	}
}
/*
��̣�07/18
02. ��������������ε��������ж������ε����ͣ����������������͡�
˼·��	1.�������߳����ж��Ƿ���������
		2.�ж��Ƿ���������ȣ�������Ϊ�ȱ�������
		  �ж��Ƿ���������ȣ�������Ϊ����������
		  �ж��Ƿ�����ƽ���͵��ڵ������ߵ�ƽ������Ϊֱ��������
		  ����Ϊ��ͨ������
*/

void Triangle(int a,int b,int c)
{
	assert(a > 0 && b > 0 && c > 0);

	if (!(a + b > c && a + c > b && a + b > c))
	{
		cout << "�����β�����" << endl;
		return;
	}
	float p = (float)(a + b + c) / 2;
	cout << "�����" << (float)sqrt(p*((p - a)*(p - b)*(p - c))) << endl;
	cout << "���ͣ�";
	if (a == b && a == c)
	{
		cout << "�ȱ�������" << endl;
	}
	else if (a == b || a == c || b == c)
	{
		cout << "����������" << endl;
	}

	else if ((a*a + b*b == c*c) || (a*a + c*c == b*b) || (b*b + c*c == a*a))
	{
		cout << "ֱ��������" << endl;
	}

	else
	{
		cout << "����������" << endl;
	}
}



/*
��̣�07/18
03. ��Ȼ���� e=2.718281828����e �ļ��㹫ʽ���£�
		e=1+1/1!+1/2!+1/3!+��
	Ҫ�����һ���ֵС�� 10^-10 ʱ������
˼·��ʹ��ѭ�������ۼ�,�ж���һ�ε�ֵ�Ƿ�С�� 10^-10��С�����˳�
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
���07.20
01.��������������������Ҷ���������������ͬ�ģ���Ϊ����ʱ����Ϊ������������ 1000 ���ڵ����л���������
˼·��д����������һ�������ж��Ƿ��ǻ��ģ�
	 �ڶ��������ж��Ƿ������������	
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
02. ����һ����Ϊ m��n �ף��� m �� n �У����� i �� j �е�Ԫ���� a(i,j)��
��Ҫ���þ���ת��Ϊ n��m �׵ľ���ʹ����Ԫ������ b(j,i)=a(i,j)��
˼·�� ��ά���鱣�����,��������������������
		�����������飬������Ӧλ���ϵ�ֵ���������Ϊ100*100
*/

void RevMatrix()
{
	int row ; //��
	int col ; //��
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
03.	����һ�����ӵĳ�������һ���£���һ���¿ɳ��ɳ��ã���ô��
	���ÿ�Գ���ÿ���¶���һ��С�ã�һ��������С�ôӵڶ���
	����Ϳ�ʼ�����ӣ����ʴ�һ�����ӿ�ʼ��ֳ���Ժ�ÿ���»�
	�ж��ٶ����ӣ�
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
04.	һֻ���Ӷ���� 10 �����ηֲ��Ķ���ĳһ�������ڵ�һ����û���ҵ����ӣ�
	�͸�һ����������������ȥ�ң�Ҳû���ҵ����͸�������������������ȥ�ң�
	�Ժ�ÿ�ζ��һ���� ȥ�����ӡ���������ȥ�����һֱ�Ҳ������ӣ�
	���ʣ����ӿ��ܶ����ĸ����У�
˼·:������ٷ�������10��Ԫ�ص����鶼��Ϊ0������10������
	����ѭ����10ȡ�࣬������ʹ�����Ԫ����Ϊ1 ��������
	���飬û�б��޸Ĺ�����˵�����ӿ��ܲ����ĸ���(���ò��Ҵ���Ϊ100)
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
			cout << "���ӿ����ڵ�" <<  i + 1 << "����" << endl;
}

/*
���07.21
01.	�š����������Ҹ�������С����һ�죬���ҵľŸ�������һ��������ܣ�
	�涨���������С���ܵ�һ�� 9 �֣��ܵڶ��� 8 �֣��������ơ�
	���������ʾ���ҵ��ܷ���ͬ������Щ����û��ͬʱ�����յ�ģ�
	Ҳû��һ�ҵ��������������ӻ�����������Ρ���֪���һ����
	����ҵĺ��ӣ���ڶ����������ҵĺ��ӡ�������һ������˭�ҵĺ��ӣ�
˼·��ʹ�ö�ά��������žŸ����ӵķ�������һ�д���ţ��ڶ��д����
�����д���
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
		cout << "���һ�����żҺ���" << endl;
	else if (who == 2)
		cout << "���һ�������Һ���" << endl;
	else
		cout << "���һ������Һ���" << endl;
}
/*
02.����ֿ졢��׼ȷ��ͳ��һƪӢ�������еĵ�������
˼·����ǰΪ��ĸ��������һ��Ϊ�ո�
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
���07.22
01.	�ڱ�ʵ����Ҫ�����һ�����ܺͽ����㷨���ڶ�һ��ָ�����ַ�������֮��
	���ý��ܺ����ܹ������Ľ��ܣ���ʾ������Ϣ�����ܵķ�ʽ�ǽ��ַ�����ÿ
	���ַ����������ַ����е�λ�ú�һ��ƫ��ֵ 5�����ַ�����mrsoft��Ϊ����
	��һ���ַ���m�����ַ����е�λ��Ϊ 0����ô����Ӧ�������ǡ�'m'+0+5"���� r��
˼·����д�������������ܺ����ͽ��ܺ���
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
���07.23
01.	���Ϊ 1��2��3������n �� n ����Χ��һȦ����ѡһ�������� m ��Ϊ��������ֵ��
	�ӵ�һ���˿�ʼ��˳ʱ�뷽������������ m ʱֹͣ������Ϊ m ���˳��С��ӳ�
	���˵�˳ʱ�뷽�����һ���˿�ʼ�ִ� 1 ���±����������ȥ��ֱ�������˶�ȫ��
	����Ϊֹ��(Լɪ��)
˼·��
	

*/
#define MAX 100
void Josephus(int a[],int n,int m)
{	//n:������ m:ֹͣ
	int i;
	int	j;//ͳ�Ʊ�����
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

