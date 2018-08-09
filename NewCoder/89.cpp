/*
 89
 更新会话列表
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		// reverse input
		vector<int> arr(n,0);
		for (int j = 0; j < n; j++) {
			cin >> arr[n-1-j];
		}

		// ignore repetition
		map<int, int> mp;
		vector<int> newArr;
		for (int j = 0; j < n; j++) {
			if (mp.find(arr[j]) == mp.end()) {
				newArr.push_back(arr[j]);
				mp[arr[j]]++;
			}
		}

		// output
		for (int j = 0; j < newArr.size()-1; j++) {
			cout << newArr[j] << ' ';
		}
		cout << newArr.back() << endl;	
	}

	return 0;
}