/* *题目：
 *  646
 *  Maximum Length of Pair Chain
 */

class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() == 0){
            return 0;
        }
        
        sort(pairs.begin(), pairs.end(), [](vector<int> a, vector<int> b)->bool{return a[0] < b[0];});
        
        vector<int> dp(pairs.size(), 1);
        for(int i = 0; i < pairs.size(); ++i){
            for(int j = 0; j < i; ++j){
                dp[i] = max(dp[i], (pairs[i][0] > pairs[j][1]) ? dp[j]+1 : dp[j]);
            }
        }
        
        return dp[dp.size()-1];
    }
};