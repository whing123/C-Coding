/* *题目：
 *  28
 *  Implement strStr()
 * *思路：
    find函数
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = haystack.size();
        int sizeN = needle.size();
        if(sizeN == 0) {
            return 0;
        }
        
        int i = 0;
        while(i + sizeN - 1 < size) {
            if(needle == haystack.substr(i, sizeN)) {
                return i;
            }else{
                i++;
            }
        }
        return -1;
    }
};