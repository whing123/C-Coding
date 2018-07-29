/* *题目：
 *  189
 *  Rotate Array
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            nums[(i+k)%n] = tmp[i];
        }
    }
};

// java 
public void rotate(int[] nums, int k) {
    k %= nums.length;
    reverse(nums, 0, nums.length - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.length - 1);
}

public void reverse(int[] nums, int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}