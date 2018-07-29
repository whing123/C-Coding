/* *题目：
 *  树的高度
 * *思路：
 *  现在有一棵合法的二叉树，树的节点都是用数字表示，现在给定这棵树上所有的父子关系，求这棵树的高度
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>
 
using namespace std;
 
void dfs(int root, map<int, vector<int>> &data, int &level, int &maxLen) {
    map<int, vector<int>>::iterator it;
    if ((it = data.find(root)) == data.end()) {
        if (level > maxLen) {
            maxLen = level;
        }
        --level;
        return;
    }
 
    vector<int> tmp = it->second;
    for (int i = 0; i < tmp.size(); ++i) { // 遍历其所有子节点
        dfs(tmp[i], data, ++level, maxLen);
    }
    --level;
}
 
int main() {
    int n;
    int a, b;
    map<int, vector<int>> data;
    map<int, vector<int>>::iterator it;
    set<int> nodes; // 右侧所有出现过的子节点
 
    cin >> n;
    int i = 1;
    while (i < n) {
        cin >> a >> b;
        if ((it = data.find(a)) == data.end()) {
            vector<int> tmp;
            tmp.push_back(b);
            data[a] = tmp;
        }
        else {
            if (it->second.size() < 2) { // 去掉超过二叉树的节点，要把多余的枝剪掉
                it->second.push_back(b);
            }
        }
 
        nodes.insert(b);
        ++i;
    }
 
    // find root
    int root;
    for (it = data.begin(); it != data.end(); ++it) {
        if (nodes.find(it->first) == nodes.end()) {
            root = it->first;
            break;
        }
    }
 
    int level = 1;
    int len = 0;
    dfs(root, data, level, len);
    cout << len << endl;
 
    return 0;
}


// better
#include <iostream>
#include <map>
#include <set>
#include <vector>
 
using namespace std;
 
void dfs(int root, map<int, vector<int>> &data, int level, int &maxLen) {
    map<int, vector<int>>::iterator it;
    if ((it = data.find(root)) == data.end()) { // 叶子
        if (level > maxLen) {
            maxLen = level;
        }
        return;
    }
 
    vector<int> tmp = it->second;
    for (int i = 0; i < tmp.size(); ++i) { // 遍历其所有子节点
        dfs(tmp[i], data, level+1, maxLen);
    }
}
 
int main() {
    int n;
    int a, b;
    map<int, vector<int>> data;
    map<int, vector<int>>::iterator it;
    set<int> nodes; // 右侧所有出现过的子节点
 
    cin >> n;
    int i = 1;
    while (i < n) {
        cin >> a >> b;
        if ((it = data.find(a)) == data.end()) {
            vector<int> tmp;
            tmp.push_back(b);
            data[a] = tmp;
        }
        else {
            if (it->second.size() < 2) { // 去掉超过二叉树的节点，要把多余的枝剪掉
                it->second.push_back(b);
            }
        }
 
        nodes.insert(b);
        ++i;
    }
 
    // find root
    int root;
    for (it = data.begin(); it != data.end(); ++it) {
        if (nodes.find(it->first) == nodes.end()) {
            root = it->first;
            break;
        }
    }
 
    int level = 1;
    int len = 0;
    dfs(root, data, level, len);
    cout << len << endl;
 
    return 0;
}