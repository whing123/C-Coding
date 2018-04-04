/* *题目：
 *  268
 *  Missing Number
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int sum = 0;
        int value;
        int maxNum = -1;
        int zero = 0;
        
        for(int i = 0;i < size;i++){
            if(nums[i] > maxNum){
                maxNum = nums[i];  //找最大的
            }
            if(nums[i] == 0){  //检查是否存在0
                zero = 1;
            }
            sum += nums[i];  //求和
        }
        value = maxNum * (maxNum + 1) / 2; //求本来不缺时所有数的和
        
        int res = value - sum;  //查找缺的那个
        if(res == 0 && zero == 1){  //如果都在（包括0）
            return maxNum + 1;  //输出最大值的下一个
        }
        
        return res;
    }
};