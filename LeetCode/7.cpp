/* *题目：
 *  7
 *  Reverse Integer
 * *思路：

 */

class Solution {
public:
    int reverse(int x) {
        int reNum = 0;
        int i = 0;
        int d;
        
        d = x > 0 ? 1 : -1;
        x = x * d;
        while(x > 0){
            if(i != 0){
                if(reNum > 214748364)
                    return 0;
                 reNum *= 10;
            }
            reNum += (x % 10);
            x = x / 10;
            i++;
        }
        
        return reNum * d;
    }
};