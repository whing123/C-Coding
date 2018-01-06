/* *题目：
 *  求第N个质数
 * *思路：
 *  
 */


#include <iostream>

using namespace std;

bool isPrime(int a) {
	if (a < 2) {
		return false;
	}
	else {
		for (int i = 2; i <= sqrt(a); ++i) {
			if (a % i == 0) {
				return false;
			}
		}
	}

	return true;
}

int main()
{
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 2;; ++i) {
		if (isPrime(i)) {
			cnt++;
			if (cnt == n) {
				cout << i<<endl;
				break;
			}
		}
	}
	return 0;
}