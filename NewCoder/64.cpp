/* *题目：
 *  跳台阶
 * *思路：
 *  
 */

class Solution {
public:
    int jumpFloor(int number) {
        vector<int> stairs(number+1);
        stairs[0] = 1;
        stairs[1] = 1;
         
        for(int i = 2; i <= number; ++i){
            stairs[i] = stairs[i-1] + stairs[i-2];
        }
         
        return stairs[number];
    }
};

/*
对于第n个台阶来说，只能从n-1或者n-2的台阶跳上来，所以
F(n) = F(n-1) + F(n-2)
斐波拉契数序列，初始条件
n=1:只能一种方法
n=2:两种
递归一下就好了
*/
class Solution {
public:
    int jumpFloor(int number) {
        if(number <= 0)
            return 0;
        else if(number == 1)
            return 1;
        else if(number == 2)
            return 2;
        else
            return jumpFloor(number-1) + jumpFloor(number-2);
    }
};

class Solution {
public:
    int jumpFloor(int number) {
        int a = 0, b = 1;
        while(number--){
            b += a;
            a = b - a;
        }
        
        return b;
    }
};