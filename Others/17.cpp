/*
酒店房间

输入：
n 房型数量
n行 成人数量 小孩数量 一晚价格
1行 入住的 成人数量 小孩数量 夜晚数
输出：
每种房型选择的数量，外加最低总价钱
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
​
struct room {
    int adt;
    int chd;
    double pri;
    room(int a, int c, double p) : adt(a), chd(c), pri(p) {}
};
 
double minPrice = INT_MAX;
int adults;
int children;
 
void dfs(vector<room>& r, vector<int>& count, vector<int>& res, int a, int c, double p) {
    if (a >= adults && c >= children) {
         if (minPrice > p) {
             minPrice = p;
             copy(count.begin(), count.end(), res.begin());
         }
         return;
    }
 
    for (int i = 0; i < count.size(); i++) {
         count[i]++;
         a += r[i].adt; c += r[i].chd; p += r[i].pri;
         dfs(r, count, res, a, c, p);
         p -= r[i].pri; c -= r[i].chd; a -= r[i].adt;
         count[i]--;
    }
}
    
int main() {
        
	int n;   
	cin >> n;
        
	vector<room> r;
        
	for (int i = 0; i < n; i++) {
         int a, c; double p;
         cin >> a >> c >> p;
         r.push_back(room(a, c, p));
    }
 
    int nights;
    cin >> adults >> children >> nights;
 
    vector<int> count(r.size(), 0);
    vector<int> res(r.size(), 0);
    dfs(r, count, res, 0, 0, 0.0);
 
    for (auto i : res)
        cout << i << " ";
    cout << minPrice * nights << endl;
 
    return 0;
}