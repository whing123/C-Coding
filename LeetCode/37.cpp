/* *题目：
 *  122
 *  Best Time to Buy and Sell Stock II
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        if(size == 0){  //为空时
            return 0;
        }
        
        int maxPro = 0;
        int curMin;  //当前最小
        int i = 0;
        
        curMin = prices[0];
        while(i < size){
            if(i+1 < size && prices[i] <= prices[i+1]){
                while(i+1 < size && prices[i] <= prices[i+1]){  //处于上升期时，在最高点处卖掉
                    i++;
                }
                if(i+1 == size){
                    maxPro += prices[i] - curMin;
                    break;
                }else{
                    maxPro += prices[i] - curMin;
                    curMin = prices[i+1];
                    i++;
                }
            }else if(i+1 < size && prices[i] > prices[i+1]){  //处于下降期时，最低点为当前最小
                while(i+1 < size && prices[i] > prices[i+1]){
                    i++;
                }
                if(i+1 == size){
                    break;
                }else{
                    curMin = prices[i];
                }
            }else{   //当走到最后一个点时
                i++;
            }
        }
        return maxPro;
    }
};