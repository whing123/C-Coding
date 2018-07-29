/*
一组数找最小的k个数
建堆
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, K;
	cin >> n >> K;
	vector<int> vec;
	for (int i = 0; i < K; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}

	make_heap(vec.begin(), vec.end());
	for (int i = 0; i < n - K; i++) {
		int tmp;
		cin >> tmp;
		if (tmp < vec[0]) {
			vec[0] = tmp;
			make_heap(vec.begin(), vec.end());
		}
	}

	sort(vec.begin(), vec.end());
	int i = 0;
	for (int m : vec) {
		cout << m;
		if (i++ < vec.size()-1) {
			cout << ',';
		}
		else {
			cout << endl;
		}
	}

	return 0;
}