/* *题目：
 *  213
 *  House Robber II
 * *思路：
 *  
 */

class Solution {
public:
    int robOriginal(vector<int>& nums) {
        int a = 0, b = 0, res = 0;
        
        for(int i = 0; i < nums.size(); ++i){
            res = max(b + nums[i], a);
            b = a; // 前一个的前一个
            a = res; // 前一个
        }
        
        return res;
    }

    int robOriginal1(vector<int>& nums) {
        int prevNo = 0;
        int prevYes = 0;
        for (int n : nums) {
            int temp = prevNo;
            prevNo = max(prevNo, prevYes); // 当前不偷时，选个大的
            prevYes = n + temp; // 当前要偷，不偷前一个的值加上当前的
        }
        return max(prevNo, prevYes);
    }
    
    /* Since you cannot rob both the first and last house, just create two separate vectors, 
     * one excluding the first house, and another excluding the last house. 
     * The best solution generated from these two vectors using the original House Robber DP algorithm is the optimal one
     */

    /*
    Since every house is either robbed or not robbed and at least half of the houses are not robbed, 
    the solution is simply the larger of two cases with consecutive houses, i.e. house i not robbed, break the circle, solve it, or house i + 1 not robbed. 
    Hence, the following solution. I chose i = n and i + 1 = 0 for simpler coding. But, you can choose whichever two consecutive ones.
    */

    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums.size() == 1) return nums[0];
        
        vector<int> numsA(nums.begin() + 1, nums.end());
        vector<int> numsB(nums.begin(), nums.end()-1);
        
        return max(robOriginal(numsA), robOriginal(numsB));
    }
};