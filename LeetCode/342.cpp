/* *题目：
 *  342
 *  Power of Four
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 1){
            return false;
        }
        while(num > 1){
            if(num % 4 == 0){
                num /= 4;
            }else{
                return false;
            }
        }
        return true;
    }
};