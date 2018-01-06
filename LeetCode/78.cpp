/* *题目：
 *  35
 *  Search Insert Position
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        
        for(int i = 0;i < size;i++){
            if(target <= nums[i]){  // 按顺序由小到大搜索
                return i;
            }
        }
        return size;
    }
};