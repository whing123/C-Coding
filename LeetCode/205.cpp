/* *题目：
 *  205
 *  Isomorphic Strings
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> Map;
        
        // map from s to t
        for(int i = 0;i < s.size();i++){
            if(Map.find(s[i]) == Map.end()){
                Map[s[i]] = t[i];
            }else if(Map[s[i]] != t[i]){
                return false;
            }
        }
        
        Map.clear();
        
        // map from t to s
        for(int i = 0;i < s.size();i++){
            if(Map.find(t[i]) == Map.end()){
                Map[t[i]] = s[i];
            }else if(Map[t[i]] != s[i]){
                return false;
            }
        }
        
        return true;
    }
};