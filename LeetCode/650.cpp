
/* *题目：
 *  650
 *  2 Keys Keyboard
 * *思路：
 *  
 */

class Solution {
public:
    /**
     * It take 2 op to double, 3 ops to triple, ... // copy(double) paste [paste]...
     * if n % 2 == 0, then f(n) = f(n/2) + 2
     * if n % 3 == 0, then f(n) = f(n/3) + 3
     * 2 * 2 = 2 + 2, 2 * 3 > 2 + 3, 4 * 4 > 4 + 4, so it is always better to divide whenever possible.
     * now it became a problem for finding all possible factors;
     */
    int minSteps(int n) {
        if (n == 1) return 0;
        for (int i = 2; i < n; i++)
            if (n % i == 0) return i + minSteps(n / i);
        return n;
    }
};


// java
public int minSteps(int n) {
    int[] dp = new int[n+1];

    for (int i = 2; i <= n; i++) {
        dp[i] = i; // 没找到因子的话就是自己
        for (int j = i-1; j > 1; j--) {
            if (i % j == 0) {
                dp[i] = dp[j] + (i/j); // 找到因子后往下查找
                break;
            }
            
        }
    }
    return dp[n];
}