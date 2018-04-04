/* *题目：
 *  720
 *  Longest Word in Dictionary
 * *思路：
 *  
 */

 struct Greater{
	bool operator()(const string &a, const string &b) {
		if (a.length() > b.length()) { // 按长度
			return true;
		}
		else if (a.length() == b.length() && a < b) { // 再按字典序
			return true;
		}
	
		return false;
	}
};


class Solution {
public:
	string longestWord(vector<string>& words) {
		map<string, int, Greater> mp;

		for (int i = 0; i < words.size(); ++i) {
			mp.insert(make_pair(words[i], 0));
		}

		map<string, int>::iterator it, it1;
		for (it = mp.begin(); it != mp.end(); ++it) {
			int size = it->first.size();
            
			bool flag = false; // 是否有中途退出
			for (int i = 1; i < size; ++i) { // 检测是否存在所有子串
				string tmp = it->first.substr(0, i); 
				if ((it1 = mp.find(tmp)) != mp.end()) {
					it1->second = 1;
				}
				else {
					flag = true;
					break;
				}
			}

			if (!flag) { // 无中途退出时，find it
				return it->first;
			}
		}

		return "";

	}
};