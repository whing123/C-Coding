#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// string 字符串分割
void SplitString(const string& s, vector<string>& v, const string& c)
{
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	while (string::npos != pos2)
	{
		v.push_back(s.substr(pos1, pos2 - pos1));

		pos1 = pos2 + c.size();
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		v.push_back(s.substr(pos1));
}

int main()
{
	int n;
	cin >> n; // 命令数
	string tmp;
	getline(cin, tmp); // 跳过换行符

	map<string, string> DB;
	map<string, string>::iterator it;
	map<string, map<string, string>> zhao; // 快照
	map<string, map<string, string>>::iterator it1;

	int i = 0;
	while (i < n) {
		string line;
		
		getline(cin, line);

		vector<string> strs;
		SplitString(line,strs," "); // 字符串分割

		if (strs[0] == "put") { // 存入
			DB[strs[1]] = strs[2];
		}
		else if (strs[0] == "mkss") { // 快照
			zhao[strs[1]] = DB;
		}
		else if (strs[0] == "del") { // 删除
			it = DB.find(strs[1]);
			if (it != DB.end()) {
				DB.erase(it);
			}
		}
		else if (strs[0] == "get") { // 获取
			if (strs.size() == 2) { // 不带快照参数
				it = DB.find(strs[1]);
				if (it != DB.end()) {
					cout << it->second << endl;
				}
				else {
					cout << "(NULL)"<<endl;
				}
			}else{ // 带快照参数
				it1 = zhao.find(strs[2]);
				if (it1 == zhao.end()) {
					cout << "(UNKNOWN_SSID)" << endl;
				}
				else {
					it = it1->second.find(strs[1]);
					if (it != it1->second.end()) {
						cout << it->second << endl;
					}
					else {
						cout << "(NULL)" << endl;
					}
				}
			}
		}
		

		i++;
	}
	
    return 0;
}