/* *题目：
 *  763
 *  Partition Labels
 */

class Solution {
public:
    vector<int> partitionLabels(string S) {
        int len = S.length();
        map<char, int> mp;
        for(int i = len-1; i >= 0; i--){ // find end pos of each letter
            if(mp.find(S[i]) == mp.end()){
                mp[S[i]] = i;
            }
        }
        
        vector<int> res;
        for(int i = 0; i < len;){
            int end = mp[S[i]]; // cur end
            for(int j = i+1; j < end; j++){
                if(mp[S[j]] > end){ // update end if line overlaps
                    end = mp[S[j]];
                }
            }
            res.push_back(end-i+1);
            i = end + 1; // next start
        }
        
        return res;
    }
};