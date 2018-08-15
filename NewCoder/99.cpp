/*
 99
 用户喜好查询
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vals(n);
	for (int i = 0; i < n; i++) {
		cin >> vals[i];
	}

	int m;
	cin >> m;
	int l, r, k;
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> k;
		int res = 0;
		for (int j = l-1; j < r; j++) {
			if (vals[j] == k) {
				res++;
			}
		}

		cout << res << endl;
	}

	return 0;
}