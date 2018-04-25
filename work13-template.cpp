#include <iostream>
#include <stdlib.h>
#include<sstream>
#include <vector>
#include <string>
#include <time.h> 
using namespace std;
template<typename T, size_t N>
void func(T(&arr)[N]) {
	int sum = 0, product = 1, squareOfSum = 0;
	for (size_t i = 0; i < N; i++)
	{
		sum += arr[i];
		product *= arr[i];
		squareOfSum += (arr[i] * arr[i]);
	}
	cout << "Sum¡G" << sum << endl;
	cout << "Product¡G" << product << endl;
	cout << "Square of Sum¡G" << squareOfSum << endl;
}
int main() {
	int intList[] = { 5, -2, 4 };
	func(intList);
	system("PAUSE");
}
