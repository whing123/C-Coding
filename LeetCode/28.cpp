/* *题目：
 *  283
 *  Move Zeroes
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0, j = size;i < j;){
            if(nums[i] == 0){
                j--;
                for(int k = i;k < j;k++){
                    nums[k] = nums[k+1];
                }
                nums[j] = 0;
            }else{
                i++;
            }
        }
    }
};