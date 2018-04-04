/* *题目：
 *  90
 *  Subsets II
 */

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> seq;
        res.push_back(seq);
        if(nums.size() == 0){
            return res;
        }
        
        sort(nums.begin(), nums.end()); // 有重复时必不可少
        dfs(res, nums, seq, 0);
        return res;
    }
    
    void dfs(vector<vector<int>>& res, vector<int>& nums, vector<int>& cur, int start){
        if(cur.size() > 0){
            res.push_back(cur);
        }
        
        unordered_set<int> hash;
        for(int i = start; i < nums.size(); ++i){
            if(hash.find(nums[i]) == hash.end()){
                cur.push_back(nums[i]);
                dfs(res, nums, cur, i+1);
                cur.pop_back();
                
                hash.insert(nums[i]);
            }
        }
    }
};