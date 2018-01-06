/* *题目：
 *  53
 *  Maximum Subarray
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int realMax, maxV;
        realMax = maxV = sum;
        
        // sum为当前小序列和，maxV为当前小序列的最大值，realMax为当前所有搜索过的序列其最大值
        int i = 0;
        while(i < nums.size()){
            while(i+1 < nums.size() && sum >= 0){ // 和非负时，继续向后加
                if(sum+nums[i+1] > maxV){  
                    maxV = sum+nums[i+1];  // 更新当前最大
                }
                sum += nums[i+1];
                i++;
            }
            
            if(maxV > realMax){  //当前序列结束后，更新历史最大值
                realMax = maxV;
            }
            
            if(i+1 < nums.size()){ //下个序列起始设置
                maxV = sum = nums[i+1]; 
            }
            i++;
        }
        
        return realMax;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i-1] > 0){ // 如果前一个大于0，有增益，则加到i上
                nums[i] += nums[i-1];
            }
            
            if(nums[i] > sum){ // update max
                sum = nums[i];
            }
        }
        
        return sum;
    }
};