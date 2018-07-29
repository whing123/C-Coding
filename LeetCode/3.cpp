/*
  3
  Longest Substring Without Repeating Characters
  最长不重复子串
*/
/*
abcdaefg
遇到第二个a时，更新最大值，然后修改新起始位置为其重复字符即第一个a的下一个
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        int max_len = 0;
        
        int i, j; // start, end
        for(i = 0; i < len;){
            map<char,int> mp; // check repeated
            for(j = i; j < len; j++){ // search
                if(mp.find(s[j]) != mp.end()){ // find repeat
                    max_len = max(max_len, j-i); // update max
                    for(int k = i; k < j; k++){ // jump to the new start
                        if(s[k] == s[j]){
                            i = k+1;
                            break;
                        }
                    }
                    break;
                }else{
                    mp[s[j]]++;
                }
            }
            
            if(j == len){ // find no repeat, break
                max_len = max(max_len, j-i);
                break;
            }
        }
        
        return max_len;
    }
};

// better
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        if(len == 0)
            return 0;
        int max_len = 1;
        
        int start = 0; // start
        for(int i = 1; i < len; i++){
            for(int j = start; j < i; j++){ // search the seq before the new adding value, the old seq is no repeat
                if(s[j] == s[i]){ // if repeat, can only find one
                    start = j+1;
                    break;
                }
            }
            
            max_len = max(max_len, i-start+1);     
        }
        
        return max_len;
    }
};