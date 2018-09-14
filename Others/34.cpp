/*
每一列中选一个 组成的字典序最小 且不和输入的重复
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

void dfs(vector<string>& strs, int N, int L, set<string>& hashSet, string& res, string s, int start) {
	if (s.length() == L) {
		if (hashSet.find(s) == hashSet.end()) {
			if (s < res) {
				res = s;
			}
		}
		return;
	}
    
    if (s > res) {
        return;
    }

	for (int j = start; j < L; j++) {
		for (int i = 0; i < N; i++) {
			dfs(strs, N, L, hashSet, res, s + strs[i][j], j + 1);
		}
	}
}

int main() {
	int N, L;
	cin >> N >> L;

	set<string> hashSet;
	vector<string> strs;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		strs.push_back(tmp);
		hashSet.insert(tmp);
	}

	string res(L, 'Z');
	string tmp = res;
	
	string s;
	dfs(strs, N, L, hashSet, res, s, 0);

	if (res == tmp) {
		cout << "-" << endl;
	}
	else {
		cout << res << endl;
	}

	return 0;
}