#include <iostream>
#include <stdlib.h>
#include<sstream>
#include <vector>
#include <string>
#include <time.h> 
using namespace std;
string toString(char s);
int main() {
	string str;
	int input;
	cout << "choose function：";
	cin >> input;
	int size, bit, count;
	if (input == 1)
	{
		cout << "Function 1" << endl;
		cin >> str;
		std::vector<char> cstr(str.c_str(), str.c_str() + str.size() + 1);
		size = cstr.size();
		for (int i = 0; i < size; i++)
		{
			str = toString(cstr[i]);
			cout << str;
		}
	}
	else if (input == 2)
	{
		cout << "Function 2" << endl;
		cin >> str >> bit;
		std::vector<char> cstr(str.c_str(), str.c_str() + str.size() + 1);
		size = cstr.size();
		for (int i = 0; i < size; i++)
		{
			cout << cstr[i];
			if ((i + 1) % bit == 0) cout << " ";
		}
	}
	else if (input == 3)
	{
		cout << "Function 3" << endl;
		cin.get();
		getline(cin, str);
		stringstream ss(str);
		string line;
		while (getline(ss, line, ' '))//按空格分割  
		{
			if (!line.empty())
				cout << line << "[" << line.length() << "] ";
		}
	}
	else cout << "error" << endl;
	system("PAUSE");
}

string toString(char s)
{
	string str;
	if (s == '0') str = "Zero";
	else if (s == '1') str = "One";
	else if (s == '2') str = "Two";
	else if (s == '3') str = "Three";
	else if (s == '4') str = "Four";
	else if (s == '5') str = "Five";
	else if (s == '6') str = "Six";
	else if (s == '7') str = "Seven";
	else if (s == '8') str = "Eight";
	else if (s == '9') str = "Nine";
	return str;
}