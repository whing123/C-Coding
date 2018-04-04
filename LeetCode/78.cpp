/* *题目：
 *  78
 *  Subsets
 */

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> seq;
        vector<vector<int>> res;
        res.push_back(seq);
        if(nums.size() == 0){
            return res;
        }
        
        dfs(nums, res, seq, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, vector<vector<int>>& res, vector<int>& seq, int start){
        if(seq.size() > 0){
            res.push_back(seq);
        }
        
        for(int i = start; i < nums.size(); ++i){
            seq.push_back(nums[i]);
            dfs(nums, res, seq, i+1);
            seq.pop_back();
        }
    }
};