/* *题目：
 *  189
 *  Rotate Array
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp = nums;
        int n  =nums.size();
        for(int i = 0;i < n;i++){
            nums[(i+k)%n] = tmp[i];
        }
    }
};