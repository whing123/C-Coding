/* *题目：
 *  63
 *  Unique Paths II
 */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> vec(m, vector<int>(n, 0));
        
        bool isD = false; // 是否遇到过障碍
        for(int i = 0; i < n; i++){
            if(obstacleGrid[0][i] == 1){
                isD = true;
            }
            if(!isD){
                vec[0][i] = 1;
            }
        }
        isD = false;
        for(int i = 0; i < m; i++){
            if(obstacleGrid[i][0] == 1){
                isD = true;
            }
            if(!isD){
                vec[i][0] = 1;
            }
        }
        
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; ++j){
                if(obstacleGrid[i][j] == 1){ // 遇到障碍
                    vec[i][j] = 0;
                }else{
                    vec[i][j] = vec[i-1][j] + vec[i][j-1]; // 左 + 上
                }
                
            }
        }
        
        return vec[m-1][n-1];
    }
};