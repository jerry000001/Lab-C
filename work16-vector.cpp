#include <iostream>
#include <stdlib.h>
#include <string>
#include <queue> 
#include <vector>
using namespace std;

struct vQueue
{
	vector<int> vQ;
	int front() const
	{
		return vQ.front();
	}
	void push(const int &element)
	{
		vQ.push_back(element);
	}
	void pop() 
	{
		for (int i = 0; i < vQ.size()-1; i++)
			vQ[i] = vQ[i + 1];
		vQ.pop_back();
	}
	int size()
	{
		return vQ.size();
	}
};
void fuction1(int input)
{
	vQueue vQ;
	int count = 0;
	cout << "Push¡G" << endl;
	for (int i = 0; i < input; i++)
	{
		vQ.push(input - i - 1);
		cout << "	Step " << i << "¡G" << (input - i - 1) << endl;
	}
	cout << "Pop¡G" << endl;
	while (vQ.size() != 0) {
		cout << "	Step " << count++ << "¡G" << vQ.front() << endl;
		vQ.pop();
	}
}
void fuction2(int input)
{
	queue<int> q;
	int count = 0;
	cout << "Push¡G" << endl;
	for (int i = 0; i < input; i++)
	{
		q.push(input - i - 1);
		cout << "	Step " << i << "¡G" << (input - i - 1) << endl;
	}
	cout << "Pop¡G" << endl;
	while (q.size() != 0) {
		cout << "	Step " << count++ << "¡G" << q.front() << endl;
		q.pop();
	}
}
void fuction3(string &str1, string &str2) 
{
	deque<char> ch1(str1.begin(), str1.end());
	deque<char> ch2(str2.begin(), str2.end());
	deque<char> chAdd(str1.begin(), str1.end());
	deque<char> chSub(str1.begin(), str1.end());
	deque<char>::iterator it1, it2;
	int i;
	for (it2 = ch2.begin(); it2 < ch2.end(); it2++)
	{
		chAdd.push_back(*it2);
	}
	it2 = ch2.begin();
	for (it1 = ch1.begin(); it1 < ch1.end(); it1++)
	{
		if (*it1 == *it2)
		{
			if (it2 != ch2.end() - 1) it2++;
			else break;
		}
		else it2 = ch2.begin();
	}
	chSub.erase(it1 - ch2.size() + 1, it1 + 1);
	cout << "a = ";
	for (it1 = ch1.begin(); it1 < ch1.end(); it1++) cout << *it1;
	cout << endl << "b = ";
	for (it1 = ch2.begin(); it1 < ch2.end(); it1++) cout << *it1;
	cout << endl << "c = a + b = ";
	for (it1 = chAdd.begin(); it1 < chAdd.end(); it1++) cout << *it1;
	cout << endl << "d = a - b = ";
	for (it1 = chSub.begin(); it1 < chSub.end(); it1++) cout << *it1;
}
void main() {
	int input, chFuction;
	string str1, str2;
	cout << "Choose Fuction¡G(1) queue (2) vQueue (3) deque ->";
	cin >> chFuction;
	switch (chFuction)
	{
	case 1:
		cout << "How many number you want to push ?";
		cin >> input;
		fuction1(input);
		break;
	case 2:
		cout << "How many number you want to push ?";
		cin >> input;
		fuction2(input);
		break;
	case 3:
		cin >> str1 >> str2;
		fuction3(str1, str2);
		break;
	default:
		cout << "ERROR" << endl;
		break;
	}
	system("pause");
}