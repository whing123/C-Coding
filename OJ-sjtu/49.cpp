/* *题目：
 *  1249
 *  有序分数序列
 * *思路：
 *  
 * *技法：
 *  
 */

#include <iostream>
#include <vector>
using namespace std;
 
class Rational {
	friend bool operator<(const Rational &r1, const Rational &r2);
	friend bool operator>(const Rational &r1, const Rational &r2);
	friend bool operator==(const Rational &r1, const Rational &r2);
	friend ostream & operator<<(ostream &os, const Rational &r1);
	private:
		int num, den;
		void ReductFraction();
	public:
		Rational(int a = 1, int b = 1) :num(a), den(b) { ReductFraction(); }
		Rational(const Rational &r1) {
			num = r1.num;
			den = r1.den;
		}
};
 
void Rational::ReductFraction() {
	int minTmp = num < den ? num : den;
	while (minTmp > 1) {
		if (den % minTmp == 0 && num % minTmp == 0) {
			den /= minTmp;
			num /= minTmp;
			break;
		}
		minTmp--;
	}
}
 
bool operator<(const Rational &r1, const Rational &r2)
{
	return r1.num * r2.den < r1.den * r2.num;
}
 
bool operator>(const Rational &r1, const Rational &r2)
{
	return r1.num * r2.den > r1.den * r2.num;
}
 
bool operator==(const Rational &r1, const Rational &r2)
{
	return r1.num == r2.num && r1.den == r2.den;
}
 
ostream & operator<<(ostream & os, const Rational &r1)
{
	os << r1.num << '/' << r1.den;
	return os;
}
 
void insertR(vector<Rational> & R, Rational r1)
{
	int i;
	for (i = 0; i < R.size();) {
		if (r1 < R[i]) {
			R.insert(R.begin() + i, r1);
			return;
		}
		else if (r1 > R[i]) {
			i++;
		}
		else if (r1 == R[i]) {
			return;
		}
	}
	if (i == R.size()) {
		R.push_back(r1);
	}
}
 
int main()
{
	vector<Rational> RList;
	int N;
	int i, j;
	cin >> N;
	RList.push_back(Rational(0, 1));
	RList.push_back(Rational(1, 1));
	for (i = 2; i <= N; i++) {
		for (j = 1; j < i; j++) {
			insertR(RList, Rational(j, i));
		}
	}
 
	for (i = 0; i < RList.size(); i++)
		cout << RList[i]<<endl;
    return 0;
}