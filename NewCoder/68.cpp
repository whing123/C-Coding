/* *题目：
 *  加法求和，不用加减乘除
 * *思路：
 *  
 */

class Solution {
public:
    int Add(int num1, int num2)
    {
        if(!num2)
            return num1;
        return Add(num1^num2, (num1&num2)<<1);
    }
};

class Solution {
public:
    int Add(int num1, int num2)
    {
        while (num2 != 0) {
            int temp = num1^num2;
            num2 = (num1&num2)<<1;
            num1 = temp;
        }
        return num1;
    }
};