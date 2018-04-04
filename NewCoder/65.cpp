/* *题目：
 *  矩形覆盖
 * *思路：
 *  
 */

/*
1. 如果选择竖向填充，规模缩小为number-1填充
2. 如果选择横向填充，则第二排只能横向填充，规模缩小为number-2填充
递归：f(n) = f(n-1) + f(n-2)
*/

class Solution {
public:
    int rectCover(int number) {
        if(number < 1){
            return 0;
        }
        if(number <= 2){
            return number;
        }
        
        return rectCover(number-1) + rectCover(number-2);
    }
};

class Solution {
public:
    int rectCover(int number) {
        if(number <= 2) return number;
        int a=1, b=2, cnt = 2;
        while(cnt < number)
        {
            b += a;
            a = b - a;
            cnt ++;
        }
        return b;
    }
};