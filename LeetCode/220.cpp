/* *题目：
 *  479
 *  Largest Palindrome Product
 * *思路：
 *  
 */

// java
 public class Solution {
    public int largestPalindrome(int n) {
        if (n == 1) return 9;
        int max = (int)Math.pow(10, n) - 1; // 2 : 99
        for (int v = max-1; v > max / 10; v--) { // n-digit : max / 10
            long u = Long.valueOf(v + new StringBuilder().append(v).reverse().toString());
            for (long x = max; x*x >= u; x--)
                if (u%x == 0)
                    return (int)(u % 1337);
        }
        return 0;
    }
}

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) return 9;
        int _max = pow(10,n) - 1; // 2 : 99
        for (int v = _max - 1; v > _max / 10; v--) { // n-digit : max / 10
            string str = to_string(v);
            reverse(str.begin(), str.end()); // reverse
            
            string tmp = to_string(v) + str; // palindrome
            long u = stol(tmp); // string to long 
            for (long x = _max; x*x >= u; x--)
                if (u % x == 0)
                    return u % 1337;
        }
        
        return 0;
    }
};