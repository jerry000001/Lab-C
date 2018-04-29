#include <iostream>
using namespace std;
void hanoi(int n, char a, char b, char c)
{
	if (n == 1) 
		cout << "Move disk " << n << " from " << a << " to " << c << endl;
	else
	{
		hanoi(n - 1, a, c, b);
		cout << "Move disk " << n << " from " << a << " to " << c << endl;
		hanoi(n - 1, b, a, c);
	}
}
void main()
{
	int n;
	cin >> n;
	hanoi(n, 'A', 'B', 'C');
	system("pause");
}