/* *题目：
 *  翻转字符串单词顺序
 */

class Solution {
public:
    string ReverseSentence(string str) {
        reverse(str.begin(), str.end()); // reverse all

        int s = 0;
        int i = 0;
        while(i < str.length()){
            while(i < str.length() && str[i] == ' ') ++i; // jump over space
            // start pos
            s = i;
            while(i < str.length() && str[i] != ' ') ++i; // find the end of this word
            reverse(str.begin()+s, str.begin()+i); // reverse it
        }

        return str;
    }
    
};