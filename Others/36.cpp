/*
存在出现次数超过t的数的长度为k的区间的个数
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main() {
	
	int n, k, t;
	cin >> n >> k >> t;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	int res = 0;
	map<int, int> mp;
	map<int, int>::iterator it;
	for (int i = 0; i < k; i++) { // first
		mp[arr[i]]++;
	}
	for (int i = 0; i < k; i++) { // first check
		if (mp[arr[i]] >= t) {
			res++;
			break;
		}
	}

	for (int i = 0; i < n - k; i++) {
		mp[arr[i + k]]++;
		mp[arr[i]]--;

		if (mp[arr[i]] == 0) {
			mp.erase(arr[i]);
		}

		for(it = mp.begin(); it != mp.end(); it++)
		{
			if (it->second >= t)
			{
				res++;
				break;
			}
		}
	}
	
	cout << res << endl;

	return 0;
}
