/* *题目：
 *  125
 *  Valid Palindrome
 */

class Solution {
public:
    bool isPalindrome(string s) {
        int size = s.size();
        if(size == 0){
            return true;
        }
        vector<char> str;
        int i = 0;
        while(i < size){
            if(('A' <= s[i] && s[i] <= 'Z') || ('a' <= s[i] && s[i] <= 'z') || ('0' <= s[i] && s[i] <= '9')){
                if('A' <= s[i] && s[i] <= 'Z'){
                    str.push_back(s[i] + 32);
                }else{
                    str.push_back(s[i]);
                }
            }
            i++;
        }
        
        size = str.size();
        int tmp1 = size / 2;
        int tmp2 = size - 1;
        for(i = 0;i < tmp1;i++){
            if(str[i] != str[tmp2 - i]){
                return false;
            }
        }
        return true;
    }
};