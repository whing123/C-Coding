/* *题目：
 *  198
 *  House Robber
 * *思路：
 *  
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        if(size == 1)
            return nums[0];
        vector<int> maxV(size,0);
        maxV[0] = nums[0];
        maxV[1] = max(nums[0],nums[1]);
        for(int i = 2;i < size;i++)
            maxV[i] = max(maxV[i-2]+nums[i],maxV[i-1]);
        return maxV[size-1];
    }
    
    int max(int a, int b){
        return a > b ? a : b;
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int prevNo = 0;
        int prevYes = 0;
        for (int n : nums) {
            int temp = prevNo;
            prevNo = max(prevNo, prevYes); // 当前不偷时，选个大的
            prevYes = n + temp; // 当前要偷，不偷前一个的值加上当前的
        }
        return max(prevNo, prevYes);
    }
    
};

/*
For every house k, there are two options: either to rob it (include this house: i) or not rob it (exclude this house: e).

Include this house:
i = num[k] + e (money of this house + money robbed excluding the previous house)

Exclude this house:
e = max(i, e) (max of money robbed including the previous house or money robbed excluding the previous house)
(note that i and e of the previous step, that's why we use tmp here to store the previous i when calculating e, to make O(1) space)

Here is the code:
*/

// java
public class Solution {
    public int rob(int[] num) {
        int i = 0;
        int e = 0;
        for (int k = 0; k<num.length; k++) {
            int tmp = i;
            i = num[k] + e;
            e = Math.max(tmp, e);
        }
        return Math.max(i,e);
    }
}