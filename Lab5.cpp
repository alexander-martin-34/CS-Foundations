#include <iostream>
using namespace std;
int main()
{
	/* Operator     Expression     Equivalent To
	   ------------------------------------------------
	   +=			x += 5;		x = x + 5;
	   -=			y -= x;		y = y - x;
	   *=			z *= 7;		z = z * 7;
	   /=			w /= y;		w = w / y;  */

	int y = 3;

	cout << "y = " << y << endl;

	y += 5;

	cout << "y += 5  =>  y = " << y << endl << endl;

	y *= 3;

	cout << "y *= 3  =>  y = " << y << endl << endl;

	y /= 2;

	cout << "y /= 2  =>  y = " << y << endl << endl;

	return 0;

}
