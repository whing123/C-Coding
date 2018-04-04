/* *题目：
 *  344
 *  Reverse String
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string reverseString(string s) {
        int size = s.size();
        int size_2 = size / 2;
        char tmp;
        for(int i = 0;i < size_2;i++){
            tmp = s[i];
            s[i] = s[size-1-i];
            s[size-1-i] = tmp;
        }
        return s;
    }
};