/* *题目：
 *  
 * *思路：
 *  先去掉RED字符串，嵌套的是否去掉，找出数字串，注意去掉前导0，在最长的里面找最大的。要记录数字串，不用map也可以，用vector，字符串自身保存其长度
 * *技法：
 *  
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

// 比较两个数字字符串的大小
int bigger(string a, string b) {
	if (a.length() > b.length()) {
		return 1;
	}
	else if (a.length() < b.length()) {
		return -1;
	}
	else {
		return a.compare(b);
	}
}

int main()
{
	const string red = "RED";

	string str;
	cin >> str;
	
	//	remove "RED"
	size_t it = 0;
	while ((it = str.find(red)) != string::npos) { // or find(red, it)，不要每次从0开始搜
		str = str.substr(0, it) + str.substr(it + 3);
	}

	map<string, int> tab;
	int maxL = 0;
	string maxS;

	int start;
	for (int i = 0; i < str.length(); ++i) {

		// 找出数字串
		if (!('0' <= str[i] && str[i] <= '9')) {
			continue;
		}

		start = i; // start
		while (i < str.length() && '0' <= str[i] && str[i] <= '9') {
			i++;
		}

		string tmp = str.substr(start, i - start);

		// remove leading 0s
		while (tmp.length() > 0 && tmp[0] == '0') {
			tmp = tmp.substr(1);
		}

		if (tmp != "") {
			tab[tmp] = tmp.length(); // store in map, string --- len
			if (tmp.length() > maxL) {  // find max length and its string
				maxL = tmp.length();
				maxS = tmp;
			}
		}
		
		i--; // do not forget, i is the first not a digit, and also for(... ;i++), so i--
	}

	// if not find
	if (tab.size() == 0) {
		cout << -1 << endl;
	}

	map<string, int>::iterator its;
	for (its = tab.begin(); its != tab.end(); its++) {
		if (its->second == maxL) { // when len is max, find max string
			if (bigger(maxS, its->first) < 0) { // bigger
				maxS = its->first;
			}
		}
	}

	cout << maxS << endl;

	return 0;
}
