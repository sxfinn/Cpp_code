#include<iostream>
using namespace std;
class Date
{
public:
	Date()
		:
		_year()
	{

	}
	void print(int& i);
	int Add(int x, int y)
	{
		return x + y;
	}
private:
	int _year;
};


int main()
{
	int& a = Add(1, 2);
	return 0;
}