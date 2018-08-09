/*
  30
  找最可能的朋友，共同朋友最多
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// intersection
int getMost(vector<int>& org, vector<int>& he) {
	map<int, int> mp;
	for (int i = 0; i < org.size(); i++) {
		mp[org[i]]++;
	}

	int cnt = 0;
	for (int i = 0; i < he.size(); i++) {
		if (mp.find(he[i]) != mp.end()) {
			cnt++;
		}
	}

	return cnt;
}

int main()
{
	int N;
	int n;

	cin >> N >> n; // num target
	vector<vector<int>> lists; // friend list
	for (int i  = 0; i < N; i++)
	{
		vector<int> tmp; // list
		int num;
		cin >> num;
		tmp.push_back(num);
		while (cin.get() != '\n') {
			cin >> num;
			tmp.push_back(num);
		}
		sort(tmp.begin(), tmp.end());
		lists.push_back(tmp);
	}

	// find its strangers
	vector<int> news;
	int j = 0;
	for (int i = 0; i < N; i++) {
		if (j < lists[n].size() && i == lists[n][j]) {
			j++;
		}
		else {
			if(i != n)
				news.push_back(i);
		}
	}

	// find most
	int max_n = 0;
	int user;
	for (int i = 0; i < news.size(); i++) {
		int tmp = getMost(lists[n], lists[news[i]]);
		if (tmp > max_n) {
			max_n = tmp;
			user = news[i];
		}
	}

	cout << user << endl;

	return 0;
}