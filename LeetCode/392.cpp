/* *题目：
 *  392
 *  Is Subsequence
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sizeS = s.size();
        int sizeT = t.size();
        if(sizeS == 0){
            return true;
        }
        
        int cnt = 0;
        for(int i = 0;i < sizeT;i++){
            if(t[i] == s[cnt]){
                cnt++;
                if(cnt == sizeS){  //子串的所有字符都能按顺序检测到，则退出
                    return true;
                }
            }
        }
        
        return false;
    }
};