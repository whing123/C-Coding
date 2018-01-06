/* *题目：
 *  400
 *  Nth Digit
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findNthDigit(int n) {
        int d = 1, base = 1;
        while(n > (long long)9 * base * d)
        {
            n -= 9 * base * d;
            d++;
            base *= 10;
        }
    
        n--;
        int num = n / d + base;
        
        for(int i = 1;i < d - n % d;i++)
            num /= 10;
        return num % 10;
    }
};