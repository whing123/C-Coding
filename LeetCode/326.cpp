/* *题目：
 *  326
 *  Power of Three
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool isPowerOfThree(int n) {
        while(n >= 3){
            if(n % 3 == 0){
                n /= 3;
            }else{
                return false;
            }
        }
        if(n == 1){
            return true;
        }
        return false;
    }
};