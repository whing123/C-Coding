/* *题目：
 *  整数中1出现的次数
 * *思路：
 *  
 */

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int num = 0;
        for(int i = 1; i <= n; ++i){
            num += NumberOf1(i);
        }
         
        return num;
    }
     
    int NumberOf1(int n){
        int res = 0;
        while(n){
            if(n % 10 == 1){
                ++res;
            }
            n /= 10;
        }
         
        return res;
    }
};

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ones = 0;
        for (long long m = 1; m <= n; m *= 10)
            ones += (n/m + 8) / 10 * m + (n/m % 10 == 1) * (n%m + 1);
         return ones;
    }
 
};
