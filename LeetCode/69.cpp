/* *题目：
 *  69
 *  Sqrt(x)
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int mySqrt(int x) {
        if(x < 2){
            return x;
        }
        
        long i;
        long tmp, tmp2;
        int mid = x / 2;
        for(i = 0; i <= mid; i++){
            tmp = i * i;
            tmp2 = (i+1) * (i+1);
            if(tmp <= x && x < tmp2){
                break;
            }
            
        }
        return i;
    }
};