/* *题目：
 *  121
 *  Best Time to Buy and Sell Stock
 */

// best
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2){
            return 0;
        }
        int maxProfit = 0;
        int curMin = prices[0];
        int tmp;
        for(int i = 1;i < prices.size();i++){
            curMin = curMin > prices[i] ? prices[i] : curMin; // 目前为止最小的
            tmp = prices[i] - curMin;
            maxProfit =  maxProfit > tmp ? maxProfit : tmp; // update
        }
        return maxProfit;
    }
}

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), 0);
        
        int max_ = 0;
        for(int i = 1; i < prices.size(); ++i){
            for(int j = i-1; j >= 0; --j){
                if(prices[i] >= prices[j]){
                    dp[i] = dp[j] + (prices[i]-prices[j]);
                    break;
                }        
            }
            
            max_ = max(max_, dp[i]);
        }
        
        return max_;
    }
};