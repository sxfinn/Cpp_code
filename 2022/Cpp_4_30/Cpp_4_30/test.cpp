#include<iostream>
#include<string.h>
using namespace std;

class S
{
public:
	S(int& x, int y = 2)
		:_x(x),_y(y)
	{
		cout << "S" << endl;
		
	}
	S(S& s)
		:_x(s._x),_y(s._y)
	{
		
	}
	void print()
	{
		cout << &_x << " " << &_y << endl;
	}
private:
	int& _x;
	const int _y;
};

void test(int a = 1, int b = 2)
{
	cout << "testab" << endl;
}

void test()
{
	cout << "test" << endl;
}
int main()
{
	int a = 1;
	S s(a);
	S s1(s);
	s.print();
	s1.print();
	return 0;
}

//int main()
//{
//	const char* s = "hello";
//	char  ps[6] = "hello";
//	ps[0] = 1;
//	return 0;
//}
//void ShellSort(char* arr, int sz)
//{
//	int gap = 0;
//	for (gap = sz / 2; gap >= 1; gap /= 2)
//	{
//		for (int i = gap; i < sz; i++)
//		{
//			int cur = arr[i];
//			int j = 0;
//			for (j = i - gap; j >= 0; j -= gap)
//			{
//				if (arr[j] > cur)
//				{
//					arr[j + gap] = arr[j];
//				}
//				else
//					break;
//			}
//			arr[j + gap] = cur;
//		}
//	}
//}
//
//int main()
//{
//	char arr[21] = { 0 };
//	while (cin >> arr)
//	{
//		int len = strlen(arr);
//		ShellSort(arr, len);
//		cout << arr << endl;
//	}
//	return 0;
//}
//struct ListNode {
//	int val;
//	struct ListNode* next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//class Remove {
//public:
//	bool removeNode(ListNode* pNode)
//	{
//		if (pNode->next == nullptr)
//			return false;
//		ListNode* cur = pNode;
//		ListNode* prev = nullptr;
//		while (cur->next)
//		{
//			prev = cur;
//			cur = cur->next;
//		}
//		int tmp = cur->val;
//		cur->val = pNode->val;
//		pNode->val = tmp;
//		free(cur);
//		return true;
//	}
//};
//int main()
//{
//	int a = 1;
//	int& quote1 = a;
//	int& quote2 = quote1;
//	return 0;
//}

//void swap(int& num1, int& num2)
//{
//	int tmp = num1;
//	num1 = num2;
//	num2 = tmp;
//}
//
//int& count()
//{
//	static int n = 1;
//	++n;
//	cout << "int& count()" << endl;
//	return n;
//}
//
//int Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}
////int main()
////{
////	int a = 1;
////	int& quote;
////	quote = a;
////	//int ret = Add(2, 8);
////	//cout << ret << endl;
////	//count();
////	//int n1 = 3;
////	//int n2 = 5;
////	//swap(n1, n2);
////	//cout << "n1=" << n1 << endl << "n2=" << n2 << endl;
////	return 0;
////}
//
////void test()
////{
////	int a = 1;
////	int& quote = a;
////	cout << a << quote << endl;
////	quote = 2;
////	cout << a << quote << endl;
////}
//
////int main()
////{
////	const int a = 1;
////	int& quote = a;
////	quote = 2;
////	return 0;
////}
////int main()
////{
////	cout << "you\n" << endl;
////	cout << "are";
////	return 0;
////}