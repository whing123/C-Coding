/* *题目：
 *  494
 *  Target Sum
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int res = 0;  //次数统计
        int pos = -1; //初始位置
        int sum = 0;  //初始和
        
        findSum(nums, pos, sum, S, res);
        
        return res;
    }
    
    void findSum(vector<int>& nums, int pos, int curSum, int S, int &cnt){
        if((pos+1) == nums.size()){  //已经达到最后一个，比较结果
            if(curSum == S){  //找到了
                cnt++;
            }
            return;
        }
        
        //接着加上下一个位置的正负数
        findSum(nums, pos+1, curSum + nums[pos+1], S, cnt); 
        findSum(nums, pos+1, curSum - nums[pos+1], S, cnt);
    }
};