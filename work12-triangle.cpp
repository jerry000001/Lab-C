#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const double PI = 3.141592654;
struct Point {
	double xValue = 0;
	double yValue = 0;
	Point(double x = 0, double y = 0) 
	{
		xValue = x;
		yValue = y;
	}
	Point translate(const Point& pt, double rX, double rY)
	{
		return Point(pt.xValue + rX, pt.yValue + rY);
	}
	Point rotate(const Point& pt, float angle) //旋轉矩陣
	{ 
		double xTemp = pt.xValue;
		double yTemp = pt.yValue;
		double theta = angle * PI / 180;
		double c = cos(theta);
		double s = sin(theta);
		xValue = xTemp * c - yTemp * s;
		yValue = xTemp * s + yTemp * c;
		return Point(xValue, yValue);
	}
	Point mirror(const Point& pt, float angle) //鏡射矩陣
	{
		double xTemp = pt.xValue;
		double yTemp = pt.yValue;
		double theta = angle * PI / 180;
		double c = cos(2 * theta);
		double s = sin(2 * theta);
		xValue = xTemp * c + yTemp * s;
		yValue = xTemp * s - yTemp * c;
		return Point(xValue, yValue);
	}
	Point zoom(const Point& pt, float magnification) //伸縮矩陣
	{
		double xTemp = pt.xValue;
		double yTemp = pt.yValue;
		xValue = xTemp * magnification;
		yValue = yTemp * magnification;
		return Point(xValue, yValue);
	}
	friend  ostream&  operator << (ostream& out, const Point& pt)
	{
		out.setf(ios::fixed, ios::floatfield);
		out.precision(1);
		return  cout << "(" << pt.xValue << ", " << pt.yValue << ")";
	}
};
struct triangle : public Point
{
	Point pt1, pt2, pt3;
	triangle(const Point& p1, const Point& p2, const Point& p3)
	{
		pt1 = p1;
		pt2 = p2;
		pt3 = p3;
	}
	triangle*  rotate(float angle)
	{
		return  new  triangle(Point::rotate(pt1, angle), Point::rotate(pt2, angle), Point::rotate(pt3, angle));
	}
	triangle*  translate(double rX, double rY)
	{
		return  new  triangle(Point::translate(pt1, rX, rY), Point::translate(pt2, rX, rY), Point::translate(pt3, rX, rY));
	}
	triangle* mirror(float angle)
	{
		return  new  triangle(Point::mirror(pt1, angle), Point::mirror(pt2, angle), Point::mirror(pt3, angle));
	}
	triangle* zoom(float magnification)
	{
		return  new  triangle(Point::zoom(pt1, magnification), Point::zoom(pt2, magnification), Point::zoom(pt3, magnification));
	}
	void display()
	{
		cout << "坐標：" << pt1 << ", " << pt2 << ", " << pt3 << endl;
		cout << "-----------------------------------------------" << endl;
	}
};

void main() {
	//順序：先將坐標平移到原點0, 0(全坐標-基準坐標) -> 旋轉/鏡射/縮放 ->  加回 基準坐標
	Point refCoordinate(3, 2);
	float angle = 90;
	float magnification = 2.0;
	triangle tr = triangle(Point(2, 1), Point(3, 3), Point(4, 2));
	cout << "原三角形座標：" << endl;
	tr.display();
	triangle *ptr;
	cout << "移動：[(" << refCoordinate.xValue << ", " << refCoordinate.yValue << ")]" << endl;
	ptr = tr.translate(refCoordinate.xValue, refCoordinate.yValue);
	ptr->display();
	cout << "旋轉：[" << angle << "度, 基準坐標(" << refCoordinate.xValue << ", " << refCoordinate.yValue << ")]" << endl;
	ptr = tr.translate(-refCoordinate.xValue, -refCoordinate.yValue)->rotate(angle)->translate(refCoordinate.xValue, refCoordinate.yValue);
	ptr->display();;
	cout << "鏡射：[" << angle << "度, 基準坐標(" << refCoordinate.xValue << ", " << refCoordinate.yValue << ")]" << endl;
	ptr = tr.translate(-refCoordinate.xValue, -refCoordinate.yValue)->mirror(angle)->translate(refCoordinate.xValue, refCoordinate.yValue);
	ptr->display();
	cout << "鏡射：[" << magnification << "倍, 基準坐標(" << refCoordinate.xValue << ", " << refCoordinate.yValue << ")]" << endl;
	ptr = tr.translate(-refCoordinate.xValue, -refCoordinate.yValue)->zoom(magnification)->translate(refCoordinate.xValue, refCoordinate.yValue);
	ptr->display();
	delete ptr;
	system("pause");
}