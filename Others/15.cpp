
/*
n 糖果数量
w 背包体积
vec 每个糖果体积
求最多多少种装法，不超过w
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<int> nums, int w, long long cursum, int start, int& cnt) {
	if (cursum > 0 && cursum <= w) {
		cnt++;
	}
	else if (cursum > w) {
		return;
	}

	for (int i = start; i < nums.size(); ++i) {
		dfs(nums, w, cursum+nums[i], i + 1, cnt);
	}
}


int main() {
	
	int n, w;
	cin >> n >> w;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		vec[i] = tmp;
	}

	int res = 0;
	dfs(vec, w, 0, 0, res);

	cout << res+1<<endl;
	return 0;
}