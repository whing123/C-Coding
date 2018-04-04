/* *题目：
 *  152
 *  Maximum Product Subarray
 */

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // store the result that is the max we have found so far
        int r = nums[0];

        // imax/imin stores the max/min product of
        // subarray that ends with the current number nums[i]
        for (int i = 1, imax = r, imin = r; i < nums.size(); i++) {
            // multiplied by a negative makes big number smaller, small number bigger
            // so we redefine the extremums by swapping them
            if (nums[i] < 0)
                swap(imax, imin);

            // max/min product for the current number is either the current number itself
            // or the max/min by the previous number times the current one
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);

            // the newly computed max value is a candidate for our global result
            r = max(r, imax);
        }
        return r;

    }
};


/* java
f[i] means maximum product that can be achieved ending with i
g[i] means minimum product that can be achieved ending with i
*/
public class Solution {
  public int maxProduct(int[] A) {
    if (A == null || A.length == 0) {
        return 0;
    }
    int[] f = new int[A.length];
    int[] g = new int[A.length];
    f[0] = A[0];
    g[0] = A[0];
    int res = A[0];
    for (int i = 1; i < A.length; i++) {
        f[i] = Math.max(Math.max(f[i - 1] * A[i], g[i - 1] * A[i]), A[i]);
        g[i] = Math.min(Math.min(f[i - 1] * A[i], g[i - 1] * A[i]), A[i]);
        res = Math.max(res, f[i]);
    }
    return res;
  }
}
