/* *题目：
 *  357
 *  Count Numbers with Unique Digits
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0){
            return 1;
        }
        
        int cnt = 1;
        for(int i = 0;i < n-1;i++){
            cnt *= 9-i;
        }
        return countNumbersWithUniqueDigits(n-1) + 9 * cnt; //最高位有9种选择，接下来10个数字剩下9种，再下去8种...
    }
};