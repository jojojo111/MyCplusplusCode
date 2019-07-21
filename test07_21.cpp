//String类的写时拷贝的实现
class Mstring
{
public:
	//构造函数的实现
	//加引用计数的string前四个字节存放四个字节的整型，作为引用计数
	Mstring(const char *str = NULL)//NULL = '\0' 
	{
		if (NULL == str)
		{
			_str = new char[1 + 4];//多申请四个字节，存放引用计数
			getNum() = 1; //初始化引用计数为1

			*(getHead()) = 0;
			_len = 0;
			return;
		}

		_str = new char[strlen(str) + 1 + 4];
		getNum() = 1;
		_len = strlen(str);
		strcpy_s(getHead(), _len + 1, str); //
	}
	//拷贝构造函数的实现
	Mstring(const Mstring &src)
	{
		_str = src._str;
		_len = src._len;

		getNum()++; //引用计数 +1
	}
	//重载 = 运算符
	Mstring& operator=(const Mstring& src)
	{
		if (&src == this) //防止自赋值
		{
			return *this;
		}

		Mdelete();

		_str = src._str;
		_len = src._len;

		getNum()++;

		return*this;
	}

	//重载解引用运算符
	char &operator*()
	{
		if (getNum() == 1)
		{
			return *getHead();
		}

		char* tmp = new char[_len + 1 + 4];
		strcpy_s(tmp + 4, _len + 1, getHead());

		getNum()--;

		_str = tmp;
		getNum() = 1;

		return *getHead();
	}

	//重载 [] 运算符
	char& operator[](int sit)
	{
		if (getNum() == 1)
		{
			return getHead()[sit];
		}

		char*tmp = new char[_len + 1 + 4];
		strcpy_s(tmp + 4, _len + 1, getHead());

		getNum()--;

		_str = tmp;
		getNum() = 1;

		return getHead()[sit];
	}
	//重载 输出流运算符
	ostream& operator << (ostream& out)
	{
		out << getNum() << "  ";
		out << getHead() << endl;

		return out;
	}
	//析构函数  调用自己实现的Mdelete
	~Mstring()
	{
		Mdelete();
	}

private:
	int& getNum()//获取当前的引用计数
	{
		return *((int *)_str);
	}

	char* getHead()//获取字符串的首元素
	{
		return _str + 4;
	}

	void Mdelete()//自己实现delete
	{
		if (--getNum() == 0)
		{
			delete _str;
		}
	}

	char*_str; //字符串
	int _len; //字符串长度
};

int main()
{
	Mstring str1 = "hello";
	str1.operator<<(cout);

	Mstring str2 = str1;
	str1.operator<<(cout);
	str2.operator<<(cout);


	Mstring str3;
	str3.operator<<(cout);

	str3 = str1;
	str1.operator<<(cout);
	str2.operator<<(cout);
	str3.operator<<(cout);
	cout << "==========================" << endl;

	//str3[2] = 'm';
	*str2 = 'm';
	str1.operator<<(cout);
	str2.operator<<(cout);
	str3.operator<<(cout);
	return 0;
}
