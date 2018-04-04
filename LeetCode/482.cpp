/* *题目：
 *  482
 *  License Key Formatting
 * *思路：
 *  
 */


class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        int size = S.length();
        
        string res;
        for(int i = size - 1; i >= 0;){
            int j = K;
            while(i >=0 && j > 0){ // get K chars
                if(S[i] != '-'){ // avoid '-'
                    if('a' <= S[i] && S[i] <= 'z'){ // change to A-Z
                        S[i] -= 32;
                    }
                    res.insert(0,1,S[i]);
                    --j;
                }
                --i;
            }
            while(i >=0 && S[i] == '-') // avoid leading '-'
                --i;
            
            if(i >= 0){ // if there left any
                res.insert(0,1,'-');
            }
        }
        
        return res;
    }
};