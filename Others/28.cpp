/*
ABCD四个小组比赛
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

typedef pair<string, vector<int>> PAIR;

bool cmp(PAIR& a, PAIR& b) {
	if (a.second[0] > b.second[0]) { // 积分
		return true;
	}else if (a.second[0] == b.second[0] && a.second[1] - a.second[2] > b.second[1] - b.second[2]) { // 进球-失球
		return true;
	}else if (a.second[0] == b.second[0] && a.second[1] - a.second[2] == b.second[1] - b.second[2] && a.second[1] > b.second[1]) { // 进球
		return true;
	}else if (a.second[0] == b.second[0] && a.second[1] - a.second[2] == b.second[1] - b.second[2] && a.second[1] == b.second[1] && a.first < b.first) { // 队名升序
		return true;
	}

	return false;
}

int main()
{
	int cnt = 0;
	while (cnt++ < 4) {
		map<string, vector<int>> mp;
		map<string, vector<int>>::iterator it;
		string s;
		for (int k = 0; k < 6; k++) {
			getline(cin, s);
			string a = s.substr(0, 3);
			string b = s.substr(8, 3);
			int numa = stoi(s.substr(4, 1)); // 得分
			int numb = stoi(s.substr(6, 1)); // 得分
			int jifena, jifenb;
			if (numa > numb) { // 积分判定
				jifena = 3;
				jifenb = 0;
			}else if (numa == numb) {
				jifena = jifenb = 1;
			}else {
				jifena = 0;
				jifenb = 3;
			}
			
			if ((it = mp.find(a)) == mp.end()) {
				vector<int> tmp(3);
				tmp[0] = jifena;
				tmp[1] = numa;
				tmp[2] = numb;

				mp[a] = tmp;
			}else {
				it->second[0] += jifena;
				it->second[1] += numa;
				it->second[2] += numb;
			}

			if ((it = mp.find(b)) == mp.end()) {
				vector<int> tmp(3);
				tmp[0] = jifenb;
				tmp[1] = numb;
				tmp[2] = numa;

				mp[b] = tmp;
			}else {
				it->second[0] += jifenb;
				it->second[1] += numb;
				it->second[2] += numa;
			}
		}

		vector<PAIR> vec(mp.begin(),mp.end()); // map 转 vector
		sort(vec.begin(), vec.end(), cmp);

		for (int i = 0; i < 4; i++) {
			cout << vec[i].first;
			if (i < 3) {
				cout << ' ';
			}else {
				cout << endl;
			}
		}

		if (cnt < 4) { // 每组后面的空行
			getline(cin, s);
		}
	}
	
	return 0;
}