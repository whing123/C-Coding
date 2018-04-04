/* *题目：
 *  377
 *  Combination Sum IV
 */


class Solution {
public:
    // 递归超时
    int combinationSum4_recursive(vector<int>& nums, int target) {
        if(target == 0){
            return 1;
        }
        
        int res = 0;
        for(int i = 0; i < nums.size(); ++i){
            if(target >= nums[i])
                res += combinationSum4(nums, target-nums[i]); // comb[target] = sum(comb[target - nums[i]]), where 0 <= i < nums.length, and target >= nums[i]
        }
        
        return res;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1);
        dp[0] = 1;    
        
        for(int i = 1; i < dp.size(); ++i){
            for(int j = 0; j < nums.size(); ++j){
                if(i >= nums[j]){
                    dp[i] += dp[i- nums[j]]; // check if there is already a result before calculation
                }
            }
        }
        
        return dp[target];
    }
};

// DFS超时
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int res = 0;
        
        sort(nums.begin(), nums.end());
        dfs(nums, target, res, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, int target, int& res, int cursum){
        if(cursum == target){
            res++;
            return;
        }else if(cursum > target){
            return;
        }
        
        for(int i = 0; i < nums.size(); ++i){
            dfs(nums, target, res, cursum+nums[i]);
        }
    }
};