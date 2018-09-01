/* *题目：
 *  746
 *  Min Cost Climbing Stairs
 * *思路：
 *  Once you pay the cost, you can either climb one or two steps. 
 You need to find minimum cost to reach the top of the floor, 
 and you can either start from the step with index 0, or the step with index 1
 */

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = (int)cost.size();
        vector<int> dp(n);
        
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; ++i)
            dp[i] = cost[i] + min(dp[i-2], dp[i-1]);

        return min(dp[n-2], dp[n-1]);
    }
};

class Solution {
public:
    int minCostClimbingStairs(vector<int>& costs) {
        int a = 0, b = 0;
        for (int cost : costs) {
            int c = min(a, b) + cost;
            a = b;
            b = c;
        }
        return min(a, b);
    }
};