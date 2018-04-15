#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <climits>
using namespace std;

int main() {
	unsigned int value = 1;
	try
	{
		for (int i = 1; i < 14; i++)
		{
			if (((long long)value * i) > UINT_MAX)
				throw i;
			value = value * i;
			cout << setw(3) << i << "!:" << setw(10) << value << endl;
		}
	}
	catch (const int i)
	{
		cout << setw(3) << i << "!:" << setw(10) << "==ERROR==" << endl;
	}
	system("pause");
}