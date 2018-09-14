/* *题目：
 *  58
 *  Length of Last Word
 * *思路：
 */

class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.length();
        int i = size - 1;
        while (s[i] == ' ') { // 跳过最后的空格
            i--;
        }

        int cnt = 0;
        while (i >= 0) {
            if (s[i] != ' ') {
                cnt++;
            } else {
                break;
            }
            
            i--;
        }
        return cnt;
    }
};