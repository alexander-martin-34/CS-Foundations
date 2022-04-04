#include <iostream>
using namespace std;

int main()
{

	int p = 3;
	int s = 3;

	cout << "p = " << p << "     s = " << s << endl;

	cout << "++p is " << ++p << "  s++ is " << s++ << endl;

	cout << "p = " << p << "     s = " << s << endl << endl;

	// output:
	// p = 3     s = 3
	// ++p is 4  s++ is 3
	// p = 4     s = 4

	// Example 2
	p = 3;
	s = 3;
	int a;
	int b;

	a = ++p + 5; // add 1 to p before evaluating expression
	b = s++ + 5; // add 1 to s after evaluating expression

	cout << "a = " << a << ", b = " << b << ", p = " << p << ", s = " << s
	     << endl << endl;
	// output : a = 9, b = 8, p = 4, s = 4

	return 0;
}
