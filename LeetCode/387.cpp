/* *题目：
 *  387
 *  First Unique Character in a String
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int firstUniqChar(string s) {
        int size = s.size();
        vector<int> tmp(size,0);
        for(int i = 0;i < size;i++){
            if(tmp[i] == 1)
                continue;
            for(int k = i + 1;k < size;k++){
                if(s[i] == s[k]){
                    tmp[k] = 1;
                    tmp[i] = 1;
                }
            }
            if(tmp[i] == 0){
                return i;
            }
        }
        return -1;
    }
};