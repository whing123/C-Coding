/* *题目：
 *  9
 *  Palindrome Number
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int re = 0;
        int tmp = x;

        re += x % 10;
        x = x / 10;
        while(x > 0)
        {
            re *= 10;
            re += x % 10;
            x = x / 10;
        }
        
        return re == tmp;
    }
};