#include<iostream>
#include<stack>
#include<queue>
using namespace std;
void test1()
{
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}
void test2()
{
	queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);
	while (!q1.empty())
	{
		cout << q1.front() << " ";
		q1.pop();
	}
	cout << endl;
	//cout << q1.front();
}
void test3()
{
	int data = 0;
	int min = 100;
	stack<int> s1;
	stack<int> minst;
	while (cin >> data)
	{
		s1.push(data);
		if (min >= data)
		{
			minst.push(data);
			min = data;
		}
	}

}
int main()
{
	test3();
	//test1();
	//test2();
	return 0;
}