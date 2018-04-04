/* *题目：
 *  200
 *  Number of Islands
 */

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if(n == 0){
            return 0;
        }
        int m = grid[0].size();
        
        int res = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                if(grid[i][j] == '1'){
                    grid[i][j] = '0';
                    search(grid, n, m, i, j);
                    res++;
                }
            }
        }
        
        return res;
    }
    
    void search(vector<vector<char>>& grid, int n, int m, int i, int j){
        if(i-1 >= 0 && grid[i-1][j] == '1'){ // 上
            grid[i-1][j] = grid[i][j];
            search(grid, n, m, i-1, j);
        }
        if(i+1 < n && grid[i+1][j] == '1'){ // 下
            grid[i+1][j] = grid[i][j];
            search(grid, n, m, i+1, j);
        }
        if(j-1 >= 0 && grid[i][j-1] == '1'){ // 左
            grid[i][j-1] = grid[i][j];
            search(grid, n, m, i, j-1);
        }
        if(j+1 < m && grid[i][j+1] == '1'){ // 右
            grid[i][j+1] = grid[i][j];
            search(grid, n, m, i, j+1);
        }
    }
};
