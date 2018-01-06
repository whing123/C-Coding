/* *题目：
 *  374
 *  Guess Number Higher or Lower
 * *思路：
 *  
 * *技法：
 *  
 */

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        int num = (left + right) / 2;
        int ret;
        while((ret = guess(num)) !=  0){
            if(ret == -1){
                right = num - 1;
            }else{
                left = num + 1;
            }
            num = ((long)left + (long)right) / 2;
        }
        return num;
    }
};