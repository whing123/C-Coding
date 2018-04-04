/* *题目：
 *  1+2+3+...+n
 * *思路：
 *  
 */

class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        ans && (ans += Sum_Solution(n - 1));
        return ans;
    }
};