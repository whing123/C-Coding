/* *题目：
 *  504
 *  Base 7
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        string sign = num < 0 ? "-" : "";  //符号
        num = abs(num);  //  转正
        while(num / 7){
            res = to_string(num % 7) + res;  //短除法，写入每次的余数
            num = num / 7;
        }
        res = to_string(num) + res;  //最后小于7的写入
        res = sign + res;  //符号写入
        return res;
    }
};