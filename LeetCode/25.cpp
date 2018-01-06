/* *题目：
 *  371
 *  Sum of Two Integers
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int getSum(int a, int b) {
        if(!b)
            return a;
        return getSum(a^b, (a&b)<<1);
    }
};

