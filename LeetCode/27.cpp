/* *题目：
 *  27
 *  Remove Element
 * *思路：

 */

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(int i = 0;i < nums.size();)
        {
            if(val == nums[i])
            {
                nums.erase(nums.begin()+i);
                continue;
            }
            i++;
        }
        return nums.size();
    }
};

// better
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (val == nums[i]) {
                cnt++;
            } else {
                nums[i-cnt] = nums[i]; // move to empty pos
            }
            
        }
        return nums.size() - cnt;
    }
};