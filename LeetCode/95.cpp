/* *题目：
 *  643
 *  Maximum Average Subarray I
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum = 0;
        
        for(int i = 0; i < k; ++i){
            sum += nums[i];
        }
        
        int tmp = sum;
        for(int i = 0; i < nums.size() - k; ++i){
            tmp -= nums[i];
            tmp += nums[i+k];
            
            if(tmp > sum){
                sum = tmp;
            }
        }
        
        return ((double)sum) / k;
    }
};