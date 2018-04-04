/* *题目：
 *  26
 *  Remove Duplicates from Sorted Array
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i = 0;i < nums.size();)
        {
            while(i+1 < nums.size() && nums[i] == nums[i+1])
            {
                nums.erase(nums.begin()+i);
            }
            i++;
        }
        return nums.size();
    }
};