/* *题目：
 *  1011
 *  复数类
 * *思路：
 *  
 * *技法：
 *  
 */

#include <iostream>
#include <iomanip> 
using namespace std;
 
class MyComplex
{
	friend MyComplex operator+(const MyComplex &c1, const MyComplex &c2);
	friend MyComplex operator-(const MyComplex &c1, const MyComplex &c2);
	friend MyComplex operator*(const MyComplex &c1, const MyComplex &c2);
	friend MyComplex operator/(const MyComplex &c1, const MyComplex &c2);
	friend ostream & operator<<(ostream &os, const MyComplex &obj);
	friend istream & operator>>(istream &is, MyComplex &obj);
private:
	double x, y;
public:
	MyComplex(double a = 0.0, double b = 0.0){
		x = a;
		y = b;
	}
	MyComplex & operator+=(const MyComplex &right);
	MyComplex & operator-=(const MyComplex &right);
	MyComplex & operator*=(const MyComplex &right);
	MyComplex & operator/=(const MyComplex &right);
};
 
MyComplex & MyComplex::operator+=(const MyComplex &right)
{
	x += right.x;
	y += right.y;
	return *this;
}
 
MyComplex & MyComplex::operator-=(const MyComplex &right)
{
	x -= right.x;
	y -= right.y;
	return *this;
}
 
MyComplex & MyComplex::operator*=(const MyComplex &right)
{
	double x1 = x, y1 = y;
	x = x1 * right.x - y1 * right.y;
	y = y1 * right.x + x1 * right.y;
	return *this;
}
 
MyComplex & MyComplex::operator/=(const MyComplex &right)
{
	double x1 = x, y1 = y;
	double den = right.x * right.x + right.y * right.y;
	x = (x1 * right.x + y1 * right.y) / den;
	y = (y1 * right.x - x1 * right.y) / den;
	return *this;
}
 
MyComplex operator+(const MyComplex &c1, const MyComplex &c2)
{
	MyComplex tmp;
	tmp.x = c1.x + c2.x;
	tmp.y = c1.y + c2.y;
	return tmp;
}
 
MyComplex operator-(const MyComplex &c1, const MyComplex &c2)
{
	MyComplex tmp;
	tmp.x = c1.x - c2.x;
	tmp.y = c1.y - c2.y;
	return tmp;
}
 
MyComplex operator*(const MyComplex &c1, const MyComplex &c2)
{
	MyComplex tmp;
	tmp.x = c1.x * c2.x - c1.y * c2.y;
	tmp.y = c1.y * c2.x + c1.x * c2.y;
	return tmp;
}
 
 
MyComplex operator/(const MyComplex &c1, const MyComplex &c2)
{
	MyComplex tmp;
	double den = c2.x * c2.x + c2.y * c2.y;
	tmp.x = (c1.x * c2.x + c1.y * c2.y) / den;
	tmp.y = (c1.y * c2.x - c1.x * c2.y) / den;
	return tmp;
}
 
ostream & operator<<(ostream &os, const MyComplex &obj)
{
	os << obj.x <<' '<< obj.y;
	return os;
}
 
istream & operator>>(istream &is, MyComplex &obj)
{
	is >> obj.x >> obj.y;
	return is;
}
 
int main()
{
	MyComplex z1;
	MyComplex z2;
 
	cin >> z1 >> z2;
 
	cout << fixed << setprecision(2);
 
	cout << z1 + z2 << endl;
	cout << z1 - z2 << endl;
	cout << z1 * z2 << endl;
	cout << z1 / z2 << endl;
	cout << (z1 += z2) << endl;
	cout << (z1 -= z2) << endl;
	cout << (z1 *= z2) << endl;
	cout << (z1 /= z2) << endl;
 
    return 0;
}
