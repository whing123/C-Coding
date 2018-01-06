/* *题目：
 *  523
 *  Continuous Subarray Sum
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
     
        for(int j = 1; j < n ;j++){
            int sum = nums[j];  //从j开始
            for(int i = j-1; i >= 0;--i){
                sum = sum + nums[i]; //向前累加
                if(k == 0 && sum == 0 || k != 0 && sum % k == 0){
                    return true;
                }
            }
        }
        
        return false;
    }
};