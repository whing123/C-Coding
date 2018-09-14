/* *题目：
 *  组成三角形
 */

#include<iostream>
#include<vector>

using namespace std;

// 判断三个点是否构成三角形 同一起点的向量(ax,ay) (bx,by) ax*by==ay*bx 则向量共线，不能组成三角形
bool exist(int x1, int y1, int x2, int y2, int x3, int y3)
{
    pair<int, int> v1 = pair<int, int>(x1 - x2, y1 - y2);
    pair<int, int> v2 = pair<int, int>(x3 - x2, y3 - y2);
    return v1.first*v2.second != v2.first*v1.second;
}

void dfs(vector<int>& x, vector<int>&y, int& res, vector<int> &xs, vector<int> &ys, int start){
    if(xs.size() == 3){ // 找到三个点后进行验证
        if(exist(xs[0],ys[0],xs[1],ys[1],xs[2],ys[2])){
            res++;
        }
        return;
    }
    for(int i = start; i < x.size(); i++) {
        xs.push_back(x[i]); // 加入新点
        ys.push_back(y[i]);
        dfs(x, y, res, xs, ys, i+1);
        xs.pop_back();
        ys.pop_back();
    }
}

int main(){
    int n;
    cin >> n;

    vector<int> xs(n, 0);
    vector<int> ys(n, 0);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        
        xs[i] = a;
        ys[i] = b;
    }
    
    int res = 0;
    vector<int> a, b;
    dfs(xs, ys, res, a, b, 0);
    cout<< res << endl;
    
    return 0;
}