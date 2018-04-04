/* *题目：
 *  39
 *  Combination Sum
 */

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> seq;
        
        sort(candidates.begin(), candidates.end());
        dfs(candidates, target, res, seq, 0, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& cur, int cursum, int start){
        if(cursum == target){
            res.push_back(cur);
            return;
        }else if(cursum > target){
            return;
        }
        
        for(int i = start; i < nums.size(); ++i){
            cur.push_back(nums[i]);
            dfs(nums, target, res, cur, cursum+nums[i], i);
            cur.pop_back();
        }
    }
};