/* *题目：
 *  120
 *  Triangle
 */

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        if(row == 1){
            return triangle[0][0];
        }
        
        int *dp = new int[row]; //从第0行开始，每一行每个位置的最小值
        dp[0] = triangle[0][0];
        for(int i = 1;i < row;i++){
            for(int j = i;j >= 0;--j){ //从右到左更新
                if(j == i){
                    dp[j] = dp[j-1]+triangle[i][j];
                }else if(j == 0){
                    dp[j] = dp[j]+triangle[i][j];
                }else{
                    dp[j] = min(dp[j],dp[j-1]) + triangle[i][j];
                }
            }
        }
        
        int m = INT_MAX;
        for(int i = 0;i < row;i++){ //最后一行找最小值
            if(dp[i] < m){
                m = dp[i];
            }
        }
        
        delete [] dp;
        
        return m;
    }
};

// better
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        
        for(int i = row-2; i >= 0; i--){
            for(int j = 0; j < i+1; j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        
        return triangle[0][0];
    }
};