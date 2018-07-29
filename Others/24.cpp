/*
原点出发，每次+1-1*2，到达x的最少步数
*/

#include <iostream>
using namespace std;

int f(int n) {

	for(int i = 0 ; i <= n;)
	if (n < 4) {
		return n;
	}

	if (n % 2 == 1) {
		return min(f(n - 1), f(n + 1)) + 1;
	}

	return f(n / 2) + 1;
}

int main() {
	int n;
	cin >> n;
	n = n < 0 ? -n : n;

	cout << f(n) << endl;

	return 0;
}