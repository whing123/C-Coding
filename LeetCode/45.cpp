/* *题目：
 *  45
 *  Jump Game II
 */


/*
In Jump Game I, when you at position i, 
you care about what is the furthest position could be reached from i th position. 
but here in Jump Game II, 
instead you care about what would be the next furthest jump could be made when you could reach as far as ith position from last jump
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_max = 0, last_max = 0;
        int step = 0, i = 0;
        
        while (cur_max < nums.size() - 1) {
            while (i <= last_max) {
                cur_max = max(i+nums[i], cur_max);
                i++;
            } 
            if (cur_max == last_max) {
                return -1;
            }
            
            last_max = cur_max;
            step++;
        }
        
        return step;
    }
};