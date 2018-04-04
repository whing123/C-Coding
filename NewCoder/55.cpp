/* *题目：
 *  power实现，求数值的整数次方
 * *思路：
 *  
 */

 /*
n为偶数时，a^n = a^n/2 * a^n/2
n为奇数时，a^n = a^(n-1)/2 * a^(n-1)/2 * a
 */

class Solution {
public:
    double Power(double base, int exponent) {
        int n = abs(exponent);
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return base;
        }
        
        double res = Power(base, n >> 1);
        res *= res;
        if(n & 0x1 == 1){ // 要比乘除法/求余运算高效
            res *= base;
        }
        
        if(exponent < 0){ // 负数幂
            res = 1 / res;
        }
        
        return res;
    }
};