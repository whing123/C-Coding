/* *题目：
 *  242
 *  Valid Anagram
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        int sSize = s.size();
        int tSize = t.size();
        if(sSize != tSize){
            return false;
        }
        vector<int> res(26,0);
        for(int i = 0;i < sSize;i++){
            res[s[i]-'a']++;
        }
        for(int i = 0;i < tSize;i++){
            res[t[i]-'a']--;
        }
        for(int i = 0;i < 26;i++){
            if(res[i] != 0)
                return false;
        }
        return true;
    }
}

class Solution {
public:
    bool isAnagram(string s, string t) {
        
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};