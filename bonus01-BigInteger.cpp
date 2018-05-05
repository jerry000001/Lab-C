#include <iostream>
#include <stdlib.h>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

void display(vector<int> &answer, bool &negative)
{
	if(negative) cout << "-";
	for (int i = answer.size() - 1; i >= 0; i--)
		cout << answer[i];
}
void display(vector<int> &answer, int &quotient)
{
	cout << "quotient：" << quotient << endl;
	cout << "remainder：";
	for (int i = answer.size() - 1; i >= 0; i--)
		cout << answer[i];
}
void add(const vector<int> &augend, const vector<int> &addend, vector<int> &answer)
{
	int carry = 0, ansTmp;
	for (int i = 0; i < augend.size(); i++)
	{
		if(i < addend.size()) ansTmp = addend[i];
		else ansTmp = 0;
		ansTmp = ansTmp + augend[i] + carry;
		if (ansTmp >= 10)
		{
			ansTmp = ansTmp % 10;
			carry = 1;
		}
		else carry = 0;
		answer.push_back(ansTmp);
	}
	if (carry != 0) answer.push_back(carry); //最後進位
}
void sub(vector<int> &minuend, vector<int> &subtrahend, vector<int> &diffrence)
{
	int borrow = 0, difTmp;
	diffrence.clear();
	for (int i = 0; i < minuend.size(); i++)
	{
		if (i < subtrahend.size()) difTmp = subtrahend[i];
		else difTmp = 0;
		if (minuend[i] < difTmp)
		{
			minuend[i + 1] -= 1;
			borrow = 1;
		}
		else borrow = 0;
		diffrence.push_back((borrow * 10) + minuend[i] - difTmp);
	}
}
void multi(vector<int> &mulitplicand, vector<int> &multiplier, vector<int> &product)
{
	int prTmp, carry = 0;
	product.assign(mulitplicand.size() + multiplier.size(), 0);
	for (int i = 0; i < multiplier.size(); i++)
	{
		for (int j = 0; j < mulitplicand.size(); j++)
		{
			product[i + j] += mulitplicand[j] * multiplier[i] + carry;
			carry = product[i + j] / 10;
			product[i + j] %= 10;
		}
		if (carry != 0 && i != multiplier.size() - 1)
		{
			product[mulitplicand.size()+i] += carry;
			carry = 0;
		}
	}
	if (carry != 0) product.push_back(carry);
}
bool compare(string &str1, string &str2)
{
	if (str1.size() < str2.size())
		return true;
	if (str1.size() == str2.size() && str1 < str2)
		return true;
	return false;
}
bool compare(vector<int> &bN1, vector<int> &bN2)
{
	int ptr1, ptr2;
	if (bN1.size() > bN2.size()) return true;
	else if (bN1.size() < bN2.size()) return false;
	else{
		for (int i = 1; i < bN1.size(); i++)
		{
			ptr1 = *(bN1.end() - i);
			ptr2 = *(bN2.end() - i);
			if (ptr1 > ptr2)
				return true;
			else if (ptr1 < ptr2)
				return false;
		}
	}
	return true;
}
int preDiv(string &str1, string &str2, bool &exchange)
{
	int len = 0, i;
	if (!exchange)
	{
		len = str1.length() - str2.length();
		for (i = 0; i < len; i++) str2 += "0";
		if (str1 < str2) len = len - 1;
	}
	else
	{
		len = str2.length() - str1.length();
		for (i = 0; i < len; i++) str1 += "0";
		if (str1 > str2) len = len - 1;
	}
	return len;
}
int div(vector<int> &dividend, vector<int> &divisor, int &len, vector<int> &answer)
{
	int i, quotient = 0, count = 0;
	for (i = 0; i < len; i++)
		divisor.insert(divisor.begin(), 0);
	while (true)
	{
		sub(dividend, divisor, answer);	
		count++;
		if (count == 8)
			int a = 0;
		int end = answer.back();
		while (end == 0) //把最高位的0去掉
		{
			answer.pop_back();
			end = answer.back();
		}
		dividend.assign(answer.begin(), answer.end());
		if (!compare(answer, divisor))
		{
			quotient += (count * pow(10, len));
			count = 0;
			if (len > 0)
			{
				divisor.erase(divisor.begin());
				len--;
			}
			if (!compare(answer, divisor)) break;
		}
	}
	return quotient;
}
void strToVector(string &str, vector<int> &bNum) //從低位開始push
{
	for (int i = str.size() - 1; i >= 0; i--)
	{
		bNum.push_back(str[i] - '0');
	}
	int end = bNum.back(); 
	while (end == 0) //把最高位的0去掉
	{
		bNum.pop_back();
		end = bNum.back();
	}
}
int main() {
	vector<int> bNum1, bNum2, answer;
	vector<int> *bN1, *bN2;
	bool exchange = false, negative = false;
	char symbol;
	string str1, str2;
	int len, quotient;
	cin >> symbol >> str1 >> str2;
	strToVector(str1, bNum1);
	strToVector(str2, bNum2);
	exchange = compare(str1, str2);
	if (!exchange)
	{
		bN1 = &bNum1;
		bN2 = &bNum2;
	}
	else
	{
		bN1 = &bNum2;
		bN2 = &bNum1;
	}
	switch (symbol)
	{
	case '+':
		add(*bN1, *bN2, answer);
		break;
	case '-':
		sub(*bN1, *bN2, answer);
		if (exchange) negative = true;
		break;
	case '*':
		multi(*bN1, *bN2, answer);
		break;
	case '/':
		len = preDiv(str1, str2, exchange);
		quotient = div(*bN1, *bN2, len, answer);
		break;
	default:
		cout << "ERROR" << endl;
		break;
	}
	if(symbol == '/') display(answer, quotient);
	else display(answer, negative);
	system("pause");
}