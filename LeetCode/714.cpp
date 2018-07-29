/* *题目：
 *  714
 *  Best Time to Buy and Sell Stock with Transaction Fee
 */

/*
Define dp array:
hold[i] : The maximum profit of holding stock until day i;
notHold[i] : The maximum profit of not hold stock until day i;

dp transition function:
For day i, we have two situations:

Hold stock:
(1) We do nothing on day i: hold[i - 1];
(2) We buy stock on day i: notHold[i - 1] - prices[i];

Not hold stock:
(1) We do nothing on day i: notHold[i - 1];
(2) We sell stock on day i: hold[i - 1] + prices[i] - fee;
*/

// O(n) space
// java
class Solution {
    public int maxProfit(int[] prices, int fee) {
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        
        int len = prices.length;
        int[] hold = new int[len];     //Till day i, the max profit is hold[i] if I hold the stock.
        int[] notHold = new int[len];  //Till day i, the max profit is notHold[i] if I do not hold the stock.
        
        hold[0] = -prices[0];
        notHold[0] = 0;
        
        for (int i = 1; i < prices.length; i++) {
            hold[i] = Math.max(hold[i - 1], notHold[i - 1] - prices[i]);
            notHold[i] = Math.max(notHold[i - 1], hold[i - 1] - fee + prices[i]);
        }
        
        return notHold[len - 1];
    }
}

/*
O(1) Space
From the dp transition function, we can see the i th state are only based on the i-1 th state. 
So we could optimize space to O(1) using two variables.
*/
// java
class Solution {
    public int maxProfit(int[] prices, int fee) {
        if (prices == null || prices.length <= 1) {
            return 0;
        }
        
        int len = prices.length;
        int hold = -prices[0];
        int notHold = 0;
        
        for (int i = 1; i < prices.length; i++) {
            hold = Math.max(hold, notHold - prices[i]);
            notHold = Math.max(notHold, hold + prices[i] - fee);
        }
        
        return notHold;
    }
}


// best
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int N = prices.size();
        if(N < 2)
            return 0;
        
        int hold = -prices[0];
        int nothold = 0;
        
        for(int i = 1; i < N; i++){
            hold = max(hold, nothold - prices[i]);
            nothold = max(nothold, hold + prices[i] - fee);
        }
        
        return nothold;
    }
};