/* *题目：
 *  485
 *  Max Consecutive Ones
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int size = nums.size();
        
        int i = 0;
        int maxNum = 0;
        int cnt = 0;
        while(i < size){
            if(nums[i] == 1){
                while(i < size && nums[i] == 1){ //为该段连续的1计数
                    cnt++;
                    i++;
                }
                maxNum = cnt > maxNum ? cnt : maxNum;  //比之前的大，更新之
                if(i == size){
                    break;
                }
                cnt = 0;
                i++;
            }else{  //为0跳过
                i++;
            }
        }
        return maxNum;
    }
};
