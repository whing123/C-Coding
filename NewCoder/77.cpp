/* *题目：
 *  数组中只出现一次的数字
 */

/*
思路就是使用异或，但是与在成对出现的数字中查找一个单独的数字不同的是需要利用异或结果的最低位为1的flag将数组中的数字分为两类，一类是与flag按位与为0，另一类为不为0，这样再分别异或一次就能够找出这两个数。很是巧妙。其中有一个语法上容易忽略的坑：==的优先级比&高，所以&时需要加括号。
*/

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        if(data.size() < 2){
            return;
        }
         
        int mxor = 0;
        int flag = 1;
        for(int i = 0; i < data.size(); ++i){
            mxor ^= data[i];
        }
         
        while((mxor & flag) == 0) flag <<= 1;
        *num1 = mxor;
        *num2 = mxor;
         
        for(int i = 0; i < data.size(); ++i){
            if((data[i] & flag) == 0) *num1 ^= data[i];
            else *num2 ^= data[i];
        }
    }
};