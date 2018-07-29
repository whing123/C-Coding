/*
形成的硬币钱数
3
2 5 10 币值
2 3 2  数目
2 4 5 7 10 12 14 15 17 19 20 22 24 25 27 29 30 32 34 35 37 39
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(vector<int>& v, set<int>& res, int cursum, int start) {
	res.insert(cursum);
	for (int i = start; i < v.size(); i++) {
		if (i > start && v[i] == v[i - 1]) continue;
		dfs(v, res, cursum + v[i], i + 1);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> coin(n);
	vector<int> num(n);

	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
		sum += num[i];
	}
	vector<int> v(sum);
	int index = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < num[i]; j++) {
			v[index++] = coin[i];
		}
	}
	
	set<int> res;
	dfs(v, res, 0, 0);
	int i = 0;
	set<int>::iterator it = res.begin();
	it++; // 去掉0
	for (; it != res.end(); it++, i++) {
		cout << *it;
		if (i < res.size() - 1) {
			cout << ' ';
		}
		else {
			cout << endl;
		}
	}
	
	return 0;
}