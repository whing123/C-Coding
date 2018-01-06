/* *题目：
 *  找位置
 * *思路：
 *  对给定的一个字符串，找出有重复的字符，并给出其位置，如：abcaaAB12ab12
 */

#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
 
typedef vector<int> vt;
typedef vector<char> vc;
 
int main() {
    string tmp;
    while (cin >> tmp) {
        unordered_map<char, vt> tab;
        unordered_map<char, vt>::iterator it;
        vc order;
        for (int i = 0; i < tmp.size(); ++i) {
            if ((it = tab.find(tmp[i])) != tab.end()) {
                it->second.push_back(i);
            }
            else {  // 首次插入
                vt p;
                p.push_back(i);
                tab.insert(pair<char, vt>(tmp[i], p));
                order.push_back(tmp[i]);  // 记录顺序
            }
        }
 
        for (int i = 0; i < order.size(); ++i) {
            it = tab.find(order[i]);
            if ( it->second.size() > 1) {  // 出现不止一次
                for (int j =0; j < it->second.size(); ++j) {
                    cout << it->first << ':' << it->second[j];
                    if (j < it->second.size() - 1) {
                        cout << ',';
                    }
                }
                cout << endl;
            }
        }
 
    }
 
    return 0;
}