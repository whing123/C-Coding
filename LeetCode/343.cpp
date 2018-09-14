/* *题目：
 *  343
 *  Integer Break
 * *思路：
 */

class Solution {
public:
    int integerBreak(int n) {
        int res = 1;
        switch(n) {
            case 2:
                return 1;
            case 3:
                return 2;
            default:
                //将n往3拆分，用3作为因子，根据最后一个3与余数的乘积
                int i = n / 3 - 1;
                res = pow(3, i);

                int yushu = n % 3;
                if(yushu == 2){  // 5 < 3 * 2， 拆开大
                    res *= 6;
                }else if(yushu == 1){ // 4 > 3 * 1，不拆大
                    res *= 4;
                }else{  //余数为0时，继续把最后一个3乘上
                    res *= 3;
                }
        }
        
        return res;
    }
};

// dp
class Solution {
public:
    // f(n) = max{ max(f(x) * f(y), x * f(y), f(x) * y, x*y) | x = 1,2,...,n-1}, x+y = n
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            int res = 0;
            for (int j = 1; j < i; j++) {
                int tmp = max(dp[j] * dp[i-j], max(dp[j] * (i-j), max(j * dp[i-j], j * (i-j))));
                if (tmp > res) {
                    res = tmp;
                }
            }
            dp[i] = res;
        }
        
        return dp[n];
    }
};