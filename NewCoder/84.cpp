/* *题目：
 *  左旋转字符串
 */

// 左旋与右旋互补 

class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if(len == 0) return str;
        
        str += str;
        n %= len;
        return str.substr(n, len);
    }
};

// 原理：YX = (X^T Y^T)^T
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.length();
        if(len == 0) return str;
         
        n %= len;
        for(int i = 0, j = n-1; i < j; ++i, --j) swap(str[i], str[j]); // 0 -- n-1
        for(int i = n, j = len-1; i < j; ++i, --j) swap(str[i], str[j]); // n -- len
        for(int i = 0, j = len-1; i < j; ++i, --j) swap(str[i], str[j]); // 0 -- len
         
        return str;
    }
};