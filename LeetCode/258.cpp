/* *题目：
 *  258
 *  Add Digits
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int addDigits(int num) {
        return 1 + (num - 1) % 9;
    }
};

class Solution {
public:
    int addDigits(int num) {
        while(num > 9){
            int tmp = num;
            num = 0;
            while(tmp != 0){
                num += tmp % 10;
                tmp /= 10;
            }
        }
        return num;
    }
};