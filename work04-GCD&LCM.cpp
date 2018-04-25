#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int GCD(int x, int y)
{
	int temp = 0;
	while (y != 0)
	{	
		temp = x % y;
		x = y;		
		y = temp;	  
	}
	return x;
}
int LCM(int x, int y)
{
	return x*y / GCD(x, y);
}
int main() {
	int x, y;
	cin >> x >> y;
	cout << "G.C.D :" << GCD(x, y) << endl;
	cout << "L.C.M :" << LCM(x, y) << endl;
	system("pause");
}