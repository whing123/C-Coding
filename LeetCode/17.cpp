/* *题目：
 *  292
 *  Nim Game
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool canWinNim(int n) {
        if(n % 4 == 0)
            return false;
        return true;
    }
};