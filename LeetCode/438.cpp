/* *题目：
 *  438
 *  Find All Anagrams in a String
 */

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int lenP = p.length();
        int lenS = s.length();
        
        vector<int> result;
        vector<int> hashP(26,0);
        vector<int> hashTest(26,0);
        
        for(int i = 0;i < lenP;i++){
            hashP[p[i]-'a']++;
        }
    
        int i = 0;
        while(i < lenS){
           // move 1 step
           hashTest[s[i]-'a']++;
           if(i >= lenP){
               hashTest[s[i-lenP]-'a']--;
           }
           
           if(hashTest == hashP){
               result.push_back(i-lenP+1);
           }
           i++;
        }
        return result;
    }
};