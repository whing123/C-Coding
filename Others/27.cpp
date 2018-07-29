/*
素数有限域
*/

#include<iostream>
#include<set>

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

int main() {
	int n;
	cin >> n;
	set<int> s;
	int res = 0;
	for (int i = 2; i <= n; i++) {
		if (isPrime(i)) { // 素数
			for (int j = 1; ; j++) {
				int tmp = pow(i, j); // 及其K次方
				if (tmp <= n) {
					if (!s.count(tmp)) {
						s.insert(tmp);
						res++;
					}

				}else {
					break;
				}
			}
		}
	}

	cout << res << endl;

	return 0;
}