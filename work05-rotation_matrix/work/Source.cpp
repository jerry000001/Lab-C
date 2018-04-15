#include <iostream>
#include <stdlib.h>
#include <queue>  
using namespace std;
int main() {
	int length, width, lengthTmp, widthTmp, x, y, xTmp, yTmp;
	int count = 0;
	int direction = 0;
	x = 0;
	xTmp = 0;
	y = 0;
	yTmp = 0;
	cin >> length >> width;
	lengthTmp = length;
	widthTmp = width;
	int **list = new int*[length];
	for (int i = 0; i < width; i++) {
		list[i] = new int[length];
	}
	bool flag = true;
	while (flag) {
		list[x][y] = count;
		if (count + 1 < length*width)
		{
			count++;
			switch (direction)
			{
			case 0: //往右
				if (y < widthTmp - 1) y += 1;
				else
				{
					widthTmp -= 1;
					xTmp += 1;
					x += 1;
					direction = 1;
				}
				break;
			case 1: //往下
				if (x < lengthTmp - 1) x += 1;
				else
				{
					lengthTmp -= 1;
					y -= 1;
					direction = 2;
				}
				break;
			case 2: //往左
				if (y > yTmp) y -= 1;
				else
				{
					x = x - 1;
					yTmp += 1;
					direction = 3;
				}
				break;
			case 3: //往上
				if (x > xTmp) x -= 1;
				else
				{
					y += 1;
					direction = 0;
				}
				break;
			default:
				cout << endl << "error" << endl;
				break;
			}
		}
		else flag = false;
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (list[i][j] + 1 < 10) cout << "0" << list[i][j] + 1 << "  ";
			else cout << list[i][j] + 1 << "  ";
		}
		cout << endl;
	}
	system("PAUSE");
}