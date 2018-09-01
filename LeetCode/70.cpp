/* *题目：
 *  70
 *  Climbing Stairs
 * *思路：

 */

class Solution {
public:
    int climbStairs(int n) {
        vector<int> result(n+1);

        result[0] = 1;
        result[1] = 1;

        for(int i = 2; i <= n; i++){
            result[i] = result[i-2] + result[i-1];
        }
        return result[n];
    }
};