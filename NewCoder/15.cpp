/* *题目：
 *  滑雪
 * *思路：
 *  
 */

 #include <iostream>
 
using namespace std;
 
void dfs(int data[][102], int x, int y, int len, int &maxLen){
    int cur = data[x][y];
    // no more lower pos
    if(cur <= data[x-1][y] && cur <= data[x+1][y] && cur <= data[x][y-1] && cur <= data[x][y+1]){
        if(len > maxLen){
            maxLen = len;
        }
        return;
    }
     
    // four dir
    if(cur > data[x-1][y]){
        dfs(data, x-1, y, len+1, maxLen);
    }
    if(cur > data[x+1][y]){
        dfs(data, x+1, y, len+1, maxLen);
    }
    if(cur > data[x][y-1]){
        dfs(data, x, y-1, len+1, maxLen);
    }
    if(cur > data[x][y+1]){
        dfs(data, x, y+1, len+1, maxLen);
    }
}
 
int main(){
    int cells[102][102];
    int max_H = 10002;
    int maxLen;
     
    int m, n;
    while(cin >> m){
        cin >> n;
         
        for(int i = 0; i < 102; ++i){
            for(int j = 0; j < 102; ++j){
                if(i >= 1 && i <= m && j >= 1 && j <= n){
                    cin >> cells[i][j];
                }else{ // make walls
                    cells[i][j] = max_H;
                }
            }
        }
         
        maxLen = 0;
        // check every pos
        for(int i = 1; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                dfs(cells, i, j, 1, maxLen);
            }
        }
         
        cout << maxLen << endl;
    }
     
    return 0;
}