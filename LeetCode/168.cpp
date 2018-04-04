/* *题目：
 *  168
 *  Excel Sheet Column Title
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string convertToTitle(int n) {
        string tmp;
        while(n > 26){
            tmp.insert(tmp.begin(),'A' + ((n % 26 == 0) ? 25 : (n % 26 - 1)));
            if(n % 26 == 0)
                n--;
            n /= 26;
        }
        tmp.insert(tmp.begin(),'A' + n - 1);
        return tmp;
    }
};