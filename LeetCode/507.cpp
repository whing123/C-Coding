/* *题目：
 *  507
 *  Perfect Number
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 0 || num == 1){
            return false;
        }
        
        int sum = 1;
        int snum = sqrt(num);
        for(int i = 2;i <= snum;i++){
            if(num%i == 0){
                sum += i;
                sum += num/i;
            }
        }
        if(snum * snum == num){
            sum -= snum;
        }
        
        if(sum == num)
            return true;
        return false;
    }
};