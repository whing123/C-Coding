/*
  47
  Permutations II
*/
/*
对数组先进行排序，如果有重复数字，则跳过。需要注意的是，因为排序，如果采用引用传递，则会破坏排序，所以使用值传递。
具体地，不交换回来是为了去重，解释如下英文。使用值传递则是为了恢复到上一步交换状态。
如果是不重复的全排列，引用传递和交换回来，则是为了恢复到最原始的无交换状态，以进行下一次交换
*/

/*
Solution for Permutations II is similar to Permutations I, the only difference is that we CAN'T swap back after each permutation, 
because we want to pick a new different number for position i in each loop.
For example, suppose array nums = [1, 1, 2, 2, 3], first we swap nums[0] = 1 with the first different number nums[2] = 2, after first swap, nums = [2, 1, 1, 2, 3], 
then if we swap back 1 with 2, nums = [1, 1, 2, 2, 3].
Now, we want to pick nums[4] = 3 as a new number for position 0, but nums[3] = 2 would be considered the new different number because we swaped the number '1' back to position 0, 
so we will swap nums[0] with nums[3], nums = [2, 1, 2, 1, 3], so the same number '2' appears twice at position 0, which caused the repeated outcomes.
*/

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        permutation(res, nums, 0);
        
        return res;
    }
    
    void permutation(vector<vector<int>>& res, vector<int> nums, int st){
        if(st == nums.size()){
            res.push_back(nums);
        }else{
            for(int i = st; i < nums.size(); i++){
                if(i > st && nums[i] == nums[st]) continue;
                swap(nums[i], nums[st]);
                permutation(res, nums, st+1); // 第st个选定后，排st+1开始的序列 
            }
        }
    }
};