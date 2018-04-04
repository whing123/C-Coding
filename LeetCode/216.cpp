/* *题目：
 *  216
 *  Combination Sum III
 */

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> seq;

        vector<int> nums(9);
        for(int i = 0; i < 9; ++i){
            nums[i] = i+1;
        }
        dfs(nums, n, k, res, seq, 0, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, int target, int k, vector<vector<int>>& res, vector<int>& cur, int cursum, int start){
        if(cursum == target && cur.size() == k){
            res.push_back(cur);
            return;
        }else if(cursum > target || cur.size() > k){
            return;
        }
        
        for(int i = start; i < nums.size(); ++i){
            cur.push_back(nums[i]);
            dfs(nums, target, k, res, cur, cursum+nums[i], i+1);
            cur.pop_back();
        }
    }
};