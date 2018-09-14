/* *题目：
 *  698
 *  Partition to K Equal Sum Subsets 
 */

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k == 1){
            return true;
        }
        if(k > nums.size()){
            return false;
        }
        
        // 是否被k整除
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }
        int subsum = sum / k;
        if(subsum * k < sum){
            return false;
        }
        
        // record if visited
        vector<int> taken(nums.size(), 0);
        
        return canPartition(nums, k, subsum, 0, 0, 0, taken);
    }
    
    bool canPartition(vector<int>& nums, int k, int target, int cursum, int curnum, int start, vector<int>& taken){
        if(k == 1){
            return true;
        }
        
        if(cursum == target && curnum > 0) // when target == 0, need curnum > 0
            return canPartition(nums, k-1, target, 0, 0, 0, taken);

        for(int i = start; i < nums.size(); ++i){
            if(taken[i] == 0){
                taken[i] = 1;
                if(canPartition(nums, k, target, cursum+nums[i], curnum+1, i+1, taken))
                   return true;
                taken[i] = 0;
            }
        }
        
        return false;
    }
};

// if 0 < nums[i] < 10000

class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k == 1){
            return true;
        }
        if(k > nums.size()){
            return false;
        }
        
        // 是否被k整除
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i){
            sum += nums[i];
        }
        int subsum = sum / k;
        if(subsum * k < sum){
            return false;
        }
        
        // record if visited
        vector<int> taken(nums.size(), 0);
        
        return canPartition(nums, k, subsum, 0, 0, taken);
    }
    
    bool canPartition(vector<int>& nums, int k, int target, int cursum, int start, vector<int>& taken){
        if(k == 1){
            return true;
        }
        
        if(cursum > target) // 0 < nums[i] < 10000
            return false;
        else if(cursum == target)
            return canPartition(nums, k-1, target, 0, 0, taken);

        for(int i = start; i < nums.size(); ++i){
            if(taken[i] == 0){
                taken[i] = 1;
                if(canPartition(nums, k, target, cursum+nums[i], i+1, taken))
                   return true;
                taken[i] = 0;
            }
        }
        
        return false;
    }
};