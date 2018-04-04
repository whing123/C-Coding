/* *题目：
 *  20
 *  Valid Parentheses
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> Map;
        Map['('] = ')';
        Map['{'] = '}';
        Map['['] = ']';
        
        stack<char> match;
        int i = 0;
        while(i < s.size()){
            if(Map.find(s[i]) == Map.end()){  //遇到右侧括号时
                if(match.empty() || Map[match.top()] != s[i]){ //和栈顶不匹配时
                    return false;
                }
                match.pop();  //匹配时
            }else{    //遇到左侧括号时
                match.push(s[i]);
            }
            i++;
        }
        if(match.empty()){
            return true;
        }
        return false;
    }
};