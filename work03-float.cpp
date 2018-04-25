#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main() {
	double value, precision;
	int c = 1;
	int *precisionCounter = &c;
	bool flag = true;
	while (true)
	{
		cin >> value >> precision;
		while (flag)
		{
			if (precision*(pow(10, *precisionCounter)) != 1)
				*precisionCounter += 1;
			else
				flag = false;
		}
		cout << setprecision(*precisionCounter) << value << endl;
		*precisionCounter = 1;
	}
	return 0;
}