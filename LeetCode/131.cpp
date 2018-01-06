/* *题目：
 *  28
 *  Implement strStr()
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        int size = haystack.size();
        int sizeN = needle.size();
        if(size == 0 && size == sizeN){
            return 0;
        }
        int i = 0;
        while(i+sizeN-1 < size){
            if(needle == haystack.substr(i,sizeN)){
                return i;
            }else{
                i++;
            }
        }
        return -1;
    }
};