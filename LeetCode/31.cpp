/* *题目：
 *  31
 *  Next Permutation
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool changed = false;
        for (int i = nums.size()-2; i >= 0; i--) {
            int maxV = INT_MAX;
            int idx = 0;
            for (int j = nums.size()-1; j > i; j--) { // 找nums[i]之后大于nums[i]且最小的和nums[i]交换，再对i之后的排序
                if (nums[j] > nums[i]) { 
                    if (nums[j] < maxV) {
                        maxV = nums[j];
                        idx = j;
                    }
                }
            }

            if (maxV < INT_MAX) {
                int tmp = nums[idx];
                nums[idx] = nums[i];
                nums[i] = tmp;

                sort(nums.begin()+i+1, nums.end());
                changed = true;
                break;
            }
        }

        if (!changed) { // 不存在 则整体排序
            sort(nums.begin(), nums.end());
        }
    }
};