#include <iostream>
#include <iomanip>
using namespace std;
struct fraction 
{
private:
	int num; // だ
	int den; // だダ
public:
	fraction(int n, int d)
	{
		num = n;
		den = d;
	}
	fraction(int mixedN, int n, int d)
	{
		if (mixedN < 0)
			num = -(n - mixedN*d);
		else 
			num = n + mixedN*d;
		den = d;
	}
	void showFraction() 
	{
		if (abs(this->num) >= this->den)
			cout << (this->num / this->den) << ", " << abs(this->num % this->den) << ", " << this->den << endl;
		else
			cout << this->num << ", " <<this->den << endl;
	}	
	operator int()// рだ计锣传Θ int
	{
		return this->num / this->den;
	}
	operator double()//рだ计锣传Θ double
	{
		double tmp = (static_cast<double>(this->num) / static_cast<double>(this->den));
		return tmp;
	}
	operator float()//рだ计锣传Θ float
	{
		float tmp = (static_cast<float>(this->num) / static_cast<float>(this->den));
		return tmp;
	}
};
void main() {
	fraction fr = fraction(-1, 1, 2);
	fr.showFraction();
	cout << "int = " << int(fr) << ", ";
	cout << "float = " << fixed << setprecision(5) << float(fr) << ", ";
	cout << "double = " << fixed <<setprecision(5) << double(fr)<< endl;
	system("pause");
}