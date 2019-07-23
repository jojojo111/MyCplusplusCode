#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void prefix_table(char pattern[], int prefix[], int n) {
	prefix[0] = 0;
	int len = 0;
	int i = 1;
	while (i < n)
	{
		if (pattern[i] == pattern[len])
		{
			len++;
			prefix[i] = len;
			i++;
		}
		else if (len > 0)
		{
			len = prefix[len - 1];
		}
		else
		{
			prefix[i] = len;
			i++;
		}
	}
}


void move_prefix_table(int prefix[], int n)
{
	for (int i = n; i > 0; i--)
	{
		prefix[i] = prefix[i - 1];
	}
	prefix[0] = -1;
}


/*传参：text：主串
*		pattern: 待匹配字符串
* */
void KMP_Search(char text[], char pattern[])
{
	bool flag = true;
	int n = (int)strlen(pattern);//待匹配字符串长度
	int m = (int)strlen(text);//主串字符串长度
	int i = 0; //定位主串text[i]
	int j = 0; //定位待匹配串pattern[j]
			   //动态申请内存作为前缀表
	int * prefix = (int *)malloc(sizeof(int)*n);
	//生成前缀表
	prefix_table(pattern, prefix, n);
	//移动前缀表
	move_prefix_table(prefix, n);
	//进行匹配操作
	while (i < m)
	{
		if (j == n - 1 && text[i] == pattern[j])
		{
			flag = false;
			printf("find pattern at index:%d\n", i - j);
			j = prefix[j];
		}
		if (text[i] == pattern[j])
		{
			i++;
			j++;
		}
		else
		{
			j = prefix[j];
			if (j == -1)
			{
				i++;
				j++;
			}
		}
	}
	if (flag)
	{
		printf("can't find the pattern!\n");
	}
}


int main()
{
	char pattern[] = "abcde";
	char text[] = "ababcabcacbab";
 	KMP_Search(text, pattern);
	return 0;
}

