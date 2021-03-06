/* *题目：
 *  26
 *  Remove Duplicates from Sorted Array
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
        
        int i = 1;
        while (i < nums.size()) {
            if (nums[i] > lastV) {
                nums[nextIdx++] = nums[i];
                lastV = nums[i];
            }
            
            i++;
        }
        
        return nextIdx;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size();) {
            while (i+1 < nums.size() && nums[i] == nums[i+1]) {
                nums.erase(nums.begin()+i);
            }
            i++;
        }
        return nums.size();
    }
};