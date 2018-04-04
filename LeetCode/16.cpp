/* *题目：
 *  16
 *  3Sum Closest
 */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3){
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int closet = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < nums.size()-2; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i+1, right = nums.size()-1;
            while(left < right){
                int cursum = nums[i] + nums[left] + nums[right];
                // find
                if(cursum == target) return cursum;
                // update
                if(abs(cursum - target) < abs(closet-target)){
                    closet = cursum;
                }
                
                if(cursum < target){
                    left++;
                }else{
                    right--;
                }
                
                while(left < right && nums[left] == nums[left-1]) left++;
                while(left < right && nums[right] == nums[right+1]) right--;
            }
        }
        
        return closet;
    }
};