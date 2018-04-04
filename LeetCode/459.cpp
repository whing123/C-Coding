/* *题目：
 *  459
 *  Repeated Substring Pattern
 * *思路：
 *  
 * *技法：
 *  
 */

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
        
        while(lenSubStr <= lenStr/2){
            subStr = str.substr(0,lenSubStr);
            i = 2;
            while(/*subStr.compare()*/lenSubStr * i <= lenStr && subStr == str.substr(lenSubStr * (i-1),lenSubStr)){ //compare #1 and #2
                i++;
            }
            i--;
            if(lenSubStr * i == lenStr){
                return true;
            }else{
                lenSubStr++;
            }
        }
        return false;
    }
};