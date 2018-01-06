/* *题目：
 *  367
 *  Valid Perfect Square
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1){
            return true;
        }
        long tmp = num / 2;
        while(tmp * tmp > num){ //注意此处溢出
            tmp /= 2;
        }
        for(int i = tmp; i < tmp * 2;i++){ //左边的平方小，右边的平方大，搜索
            if(i*i == num){
                return true;
            }else if(i*i < num && (i+1)*(i+1) > num){ //恰好出现在一小一大中
                break;
            }
        }
        
        return false;
    }
};