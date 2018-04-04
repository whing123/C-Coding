/* *题目：
 *  343
 *  Integer Break
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int integerBreak(int n) {
        int res = 1;
        switch(n){
            case 2:
                return 1;
            case 3:
                return 2;
            default:
                //将n往3拆分，用3作为因子，根据最后一个3与余数的乘积
                int i = n / 3 - 1;
                /*
                while(i-- > 0){
                    res *= 3;
                }*/
                res = pow(3,i);
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