/* *题目：
 *  344
 *  Reverse String
 * *思路：

 */

// better
class Solution {
public:
    string reverseString(string s) {
        int st = 0;
        int ed = s.size()-1;
        
        while(st < ed) {
            if (s[st] != s[ed]) {
                char tmp = s[st];
                s[st] = s[ed];
                s[ed] = tmp;
            }
            
            st++;
            ed--;
        }
        
        return s;
    }
};

// better
class Solution {
public:
    string reverseString(string s) {
        string ret;
        for(int i = s.size()-1; i >= 0; --i)
            ret += s[i];
        return ret;
        
        return s;
    }
};

class Solution {
public:
    string reverseString(string s) {
        int size = s.size();
        int size_2 = size / 2;
        char tmp;
        for(int i = 0; i < size_2; i++) {
            tmp = s[i];
            s[i] = s[size-1-i];
            s[size-1-i] = tmp;
        }

        return s;
    }
};