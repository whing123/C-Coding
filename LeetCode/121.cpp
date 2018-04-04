/* *题目：
 *  121
 *  Best Time to Buy and Sell Stock
 * *思路：
 *  
 * *技法：
 *  
 */

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
            curMin = curMin > prices[i] ? prices[i] : curMin;
            tmp = prices[i] - curMin;
            maxProfit =  maxProfit > tmp ? maxProfit : tmp;
        }
        return maxProfit;
    }
}