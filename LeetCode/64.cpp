/* *题目：
 *  64
 *  Minimum Path Sum
 */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        int **dp = new int*[m];
        for(int i = 0; i < m;i++){
            dp[i] = new int[n];
        }
        
        //光栅顺序计算每个位置的最小值
        dp[0][0] = grid[0][0];
        int a1, a2;
        for(int i = 0; i <  m; ++i){
            for(int j = 0; j < n;j++){
                if(i == 0 && j == 0){
                    continue;
                }
                
                a1 = INT_MAX, a2 = INT_MAX;
                if(i-1 >= 0){  //上
                     a1 = dp[i-1][j];  
                }
                if(j-1 >= 0){  //左
                     a2 = dp[i][j-1];  
                }
                
                dp[i][j] = min(a1,a2) + grid[i][j];

            }
        }
        
        int res = dp[m-1][n-1];
        
        
        for(int i = 0; i < m;i++){
            delete [] dp[i];
        }
        delete [] dp;
        
        return res;
    }
};

// better
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(int i = 1; i < n; i++){ // row 0
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }
        for(int i = 1; i < m; i++){ // col 0
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        
        //光栅顺序计算每个位置的最小值
        for(int i = 1; i <  m; ++i){
            for(int j = 1; j < n; j++){
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        
        return dp[m-1][n-1];
    }
};