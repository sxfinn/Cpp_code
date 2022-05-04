#include<iostream>

using namespace std;

class T
{
public:
	T()
	{
		cout << "T()" << endl;
	}
	
	~T()
	{
		cout << "~T()" << endl;
	}
	int x;
};
class T1
{
public:
	T1()
	{
		cout << "T1()" << endl;
	}

	~T1()
	{
		cout << "~T1()" << endl;
	}
	int x;
};
class S
{
public:
	S()
		:a(1),
		b(2)
	{
		cout << "S()" << endl;
	}
	~S()
	{
		a = 0;
		b = 0;
		cout << "~S()" << endl;
	}
	
	int a;
	int b;
	
	T1 t1;
	T t;
};
int main()
{
	S s;
	return 0;
}
//int test(int a, int b)
//{
//	return a > b ? a : b;
//}
//int main()
//{
//	const int a = 1;
//	int b = a;
//	test(a, b);
//	return 0;
//}