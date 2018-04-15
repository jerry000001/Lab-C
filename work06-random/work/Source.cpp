#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h> 
using namespace std;

int main() {
	int input;
	unsigned seed;
	seed = (unsigned)time(NULL); // 取得時間序列
	srand(seed); // 以時間序列當亂數種子
	cin >> input;
	int *rList = new int[input];
	int *list = new int[input];
	for (int i = 0; i < input; i++)
	{
		rList[i] = rand() % input;
		list[i] = rList[i];
	}
	for (int i = input - 1; i > 0; --i)
	{
		bool swapped = false;
		for (int j = 0; j < i; ++j)
			if (list[j] > list[j + 1])
			{
				double tmp = list[j];
				list[j] = list[j + 1];
				list[j + 1] = tmp;
				swapped = true;
			}
		if (!swapped)
			break;
	}
	cout << "array => { ";
	for (int i = 0; i < input; i++)
	{
		cout << setw(2) << rList[i];
		if (i + 1 == input) cout << " }" << endl;
		else cout << ", ";
	}
	cout << "array => { ";
	for (int i = 0; i < input; i++)
	{
		cout << setw(2) << list[i];
		if (i + 1 == input) cout << " }" << endl;
		else cout << ", ";
	}
	system("PAUSE");
}