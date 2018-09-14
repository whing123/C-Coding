/* *题目：
 *  459
 *  Repeated Substring Pattern
 * *思路：
 
 Basic idea:
* First char of input string is first char of repeated substring
* Last char of input string is last char of repeated substring
* Let S1 = S + S (where S in input string)
* Remove first and last char of S1. Let this be S2
* If S exists in S2 then return true else false
* Let i be index in S2 where S starts then repeated substring length i + 1 and repeated substring S[0: i+1]
 */

// better
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string str = (s + s).substr(1, s.length() * 2 - 2);
        return str.find(s) != -1;
    }
};

class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int lenStr = str.size();
        if(lenStr == 0){
            return true;   
        }
    
        string subStr;
        int lenSubStr = 1;
        int i;
        
        while(lenSubStr <= lenStr / 2) {
            subStr = str.substr(0, lenSubStr);
            i = 2;
            while(/*subStr.compare()*/lenSubStr * i <= lenStr && subStr == str.substr(lenSubStr * (i-1), lenSubStr)) { //compare #1 and #2
                i++;
            }
            i--;

            if(lenSubStr * i == lenStr) {
                return true;
            }else {
                lenSubStr++;
            }
        }
        return false;
    }
};