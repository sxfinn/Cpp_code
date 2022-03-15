#include<iostream>
using namespace std;
class person
{
public:
	person()
		:
		age(10),
		sex(1)
		//teachage(99)
	{}
	void print()
	{
		cout << age;
	}
//private:
//protected:
	int age;
	int sex;
	//int teachage;
};

class stu:public person
{
public:
	stu()
		:
		id(0)
	{

	}
	void print()
	{
		printf("%d", id);
	}
	int id;
};
class teacher
{
public:
	teacher()
		:
		teachage(50)
	{}
	class person;
	int teachage;

};
class S
{
public:
	S()
		:
		a(101)
	{}
	int a;
};

void test2()
{

}
int main()
{
	//test1();
	return 0;
}
//void test1()
//{
//	stu s1;
//	//cout << s1.teachage;
//	cout << s1.age;
//	teacher t1;	
//	cout << sizeof(t1);
//}
//int main()
//{
//	
//	//test1();
//	double d = 901.9;
//	int* t1 = (int*)& d;
//	int& t2 = (int&)d;
//	cout << *t1 << " " << t2;
//	return 0;
//}

//int main()
//{
//	cout << S().a;
//	S s;
//	cout << s.a;
//	//cout << s.a;
//	//int cur(99);
//	//cout << cur;
//	//stu s1;
//	//cout << s1.age;
//	//s1.print();
//	return 0;
//}