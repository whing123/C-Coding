/* *题目：
 *  486
 *  Predict the Winner
 */

class Solution {
public:
    // dp[i][j] saves how much more scores that the first-in-action player will get from i to j than the second player
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 0; i < n; ++i){
            dp[i][i] = nums[i];
        }
        
        for(int len = 1; len < n; ++len){
            for(int i = 0; i < n-len; ++i){
                int j = i+len;
                dp[i][j] = max(nums[i]-dp[i+1][j], nums[j]-dp[i][j-1]); // if A picks nums[i], B first-in-action [i+1, j]
            }
        }
        
        return dp[0][n-1] >= 0; // player1 get more score points than player2
    }

};