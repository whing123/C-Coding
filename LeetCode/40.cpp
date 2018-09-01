/* *题目：
 *  40
 *  Combination Sum II
 */

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> seq;
        
        sort(candidates.begin(), candidates.end()); // 有重复时必不可少
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
        
        unordered_set<int> hash;
        for(int i = start; i < nums.size(); ++i){
            if(hash.find(nums[i]) == hash.end()){
                cur.push_back(nums[i]);
                dfs(nums, target, res, cur, cursum+nums[i], i+1);
                cur.pop_back();

                hash.insert(nums[i]);
            }
        }
    }
};

// continue 去重，更简单
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if(i > start && nums[i] == nums[i-1]) continue;
            
            cur.push_back(nums[i]);
            dfs(nums, target, res, cur, cursum+nums[i], i+1);
            cur.pop_back();
        }
    }
};