/* *题目：
 *  414
 *  Third Maximum Number
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return nums[0] > nums[1] ? nums[0] : nums[1];
        }
        
        int i;
        int max2, max3, maxV, minV;
        maxV = nums[0];
        minV = nums[0];
        for(i = 1;i < n;i++){
           if(nums[i] > maxV){
               maxV = nums[i];
           } 
           if(nums[i] < minV){
               minV = nums[i];
           }
        }
        max2 = minV;
        for(i = 0;i < n;i++){
            if(nums[i] < maxV && nums[i] > max2){
                max2 = nums[i];
            }
        }
        
        max3 = minV;
        for(i = 0;i < n;i++){
            if(nums[i] < max2 && nums[i] > max3){
                max3 = nums[i];
            }
        }
        
        if(max2 == maxV || max2 == max3){
            return maxV;
        }
        return max3;
    }
};