/* *题目：
 *  633
 *  Sum of Square Numbers
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        for(long a = 0; a*a <= c; ++a){
            double b = sqrt(c - a*a);
            if(b == (int)b)
                return true;
        }
        
        return false;
    }
};