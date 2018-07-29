/*
  46
  Permutations
  不重复序列的全排列
*/

/*
全排列可以看作先固定前i位，对第i+1位之后的序列再进行全排列
*/

// better
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        
        permutation(res, nums, 0);
        
        return res;
    }
    
    void permutation(vector<vector<int>>& res, vector<int>& nums, int st){
        if(st == nums.size()){
            res.push_back(nums);
        }else{
            for(int i = st; i < nums.size(); i++){
                swap(nums[i], nums[st]);
                permutation(res, nums, st+1); // 第st个选定后，排st+1开始的序列
                swap(nums[i], nums[st]);
            }
        }
    }
};