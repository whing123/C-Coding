/* *题目：
 *  542
 *  01 Matrix
 */

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int h = matrix.size(), w = matrix[0].size();
        vector<vector<int>> dp(h, vector<int>(w, INT_MAX));
        
        for(int times = 0; times <= 1; times++) // two passes, first forward then backward
            
            for(int i = times?h-1:0; times?i>=0:i<h; times?i--:i++) 
                for(int j = times?w-1:0; times?j>=0:j<w; times?j--:j++)
                        if(matrix[i][j] == 0)
                            dp[i][j] = 0;
                        else {
                            if(i && dp[i-1][j] != INT_MAX && dp[i][j]>dp[i-1][j]+1) // look up
                                dp[i][j] = dp[i-1][j]+1;
                            if(j && dp[i][j-1] != INT_MAX && dp[i][j]>dp[i][j-1]+1) // look left
                                dp[i][j] = dp[i][j-1]+1;
                            if(i < h-1 && dp[i+1][j] != INT_MAX && dp[i][j]>dp[i+1][j]+1) // look down
                                dp[i][j] = dp[i+1][j]+1;
                            if(j < w-1 && dp[i][j+1] != INT_MAX && dp[i][j]>dp[i][j+1]+1) // look right
                                dp[i][j] = dp[i][j+1]+1;
                        }
        return dp;
    }
};


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int h = matrix.size(), w = matrix[0].size();
        vector<vector<int>> dis(h, vector<int>(w, INT_MAX));
        

        int range = h * w;
    
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (matrix[i][j] == 0) {
                    dis[i][j] = 0;
                } else {
                    int upCell = (i > 0) ? dis[i - 1][j] : range;
                    int leftCell = (j > 0) ? dis[i][j - 1] : range;
                    dis[i][j] = min(upCell, leftCell) + 1;
                }
            }
        }

        for (int i = h - 1; i >= 0; i--) {
            for (int j = w - 1; j >= 0; j--) {
                if (matrix[i][j] == 0) {
                    dis[i][j] = 0;
                } else {
                    int downCell = (i < h - 1) ? dis[i + 1][j] : range;
                    int rightCell = (j < w - 1) ? dis[i][j + 1] : range;
                    dis[i][j] = min(min(downCell, rightCell) + 1, dis[i][j]);
                }
            }
        }

        return dis;
    }
};