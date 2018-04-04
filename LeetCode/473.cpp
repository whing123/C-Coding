/* *题目：
 *  473
 *  Matchsticks to Square
 */

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int size = nums.size();
        if(size < 4){
            return false;
        }
        
        int sum = 0;
        for(int i = 0; i < size; ++i){
            sum += nums[i];
        }
        if(sum % 4 != 0){
            return false;
        }
        
        vector<int> taken(size, 0);
        return dfs(nums, sum/4, 0, 0, 4, taken);
    }
    
    bool dfs(vector<int>& nums, int target, int cursum, int start, int k, vector<int>& taken){
        if(k == 1){
            return true;
        }
        
        if(target == cursum){
            return dfs(nums, target, 0, 0, k-1, taken);
        }else if(cursum > target){
            return false;
        }
        
        for(int i = start; i < nums.size(); ++i){
            if(taken[i] == 0){
                taken[i] = 1;
                if(dfs(nums, target, cursum+nums[i], i+1, k, taken)){
                    return true;
                }
                taken[i] = 0;
            }
            
        }
        
        return false;
    } 
};