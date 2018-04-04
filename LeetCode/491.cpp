/* *题目：
 *  491
 *  Increasing Subsequences
 * *思路：
 *  
 */


class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seq;
        dfs(res, nums, seq, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>&res, vector<int> &nums, vector<int>& cur, int start){
        if(cur.size() > 1) res.push_back(cur);
        unordered_set<int> hash;
        for(int i = start; i < nums.size(); ++i){
            if((cur.empty() || nums[i] >= cur.back()) && hash.find(nums[i]) == hash.end()){
                cur.push_back(nums[i]);
                dfs(res, nums, cur, i+1);
                cur.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
};