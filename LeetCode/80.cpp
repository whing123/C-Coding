/* *题目：
 *  80
 *  Remove Duplicates from Sorted Array II
 * *思路：
 
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        
        int lastV = nums[0];
        int nextIdx = 1;
        int cnt = 1;

        int i = 1;
        while (i < nums.size()) {
            if (nums[i] > lastV) {
                nums[nextIdx++] = nums[i];
                
                lastV = nums[i];
                cnt = 1;
            } else if (nums[i] == lastV) {
                cnt++;
                if (cnt < 3) {
                    nums[nextIdx++] = nums[i];
                }
            }
            
            i++;
        }
        
        return nextIdx;
    }
};