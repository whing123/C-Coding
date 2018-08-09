/*
  94
  走到第n步时投骰子的方法
*/

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<int>& vec, int n, int cur, int& sum) {
	if (cur == n) {
		sum++;
		return;
	}else if (cur > n) {
		return;
	}

	for	(int i = 0; i < vec.size(); i++) {
		dfs(vec, n, cur + vec[i], sum);
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> vec(6, 0);
	for (int i = 1; i <= 6; i++) {
		vec[i-1] = i;
	}

	int sum = 0;
	dfs(vec, n, 0, sum);
	cout << sum << endl;

	return 0;
}