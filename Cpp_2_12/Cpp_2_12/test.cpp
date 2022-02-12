#include"date.h"

int main()
{
	Date a(2001, 7, 28);
	a.print();
	a += 10;
	a.print();
	Date b;
	b = (a + 7);
	b.print();
	return 0;
}