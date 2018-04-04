/* *题目：
 *  172
 *  Factorial Trailing Zeroes
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 5)
		return 0;
		
	    int sum_5 = 0;

        while (n / 5 != 0) {
        	n /= 5;
        	sum_5 += n;
        }
    	return sum_5;
    }
};