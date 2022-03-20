//#include<iostream>
//
//using namespace std;
//
//
//

//继承：几乎未封装的一个无名对象
//因为几乎无封装效果，可以直接看作子类的成员，当命名冲突时，需要指定继承的父类或者是子类原生成员
// 并且继承关系遵循权限缩小不能放大的原则继承。
//但在默认构造函数里，其被当作一个匿名对象。
//class S
//{
//public:
//	S()
//		:
//		a(1),
//		b(2)
//	{}
//protected:
//	int b;
//
//	int a;
//};
//class B:public S
//{
//public:
//	B()
//		:
//		b(7),
//		c(10)
//	{
//
//	}
//	void print()
//	{
//		cout << a << b << c;
//		
//	}
//	int c;
//
//};
//int main()
//{
//	B k;
//	k.c;
//	k.print();
//	return 0;
//}

//int main()
//{
//	printf("%c", "'");
//	print("%c", """);
//	return 0;
//}
//	

