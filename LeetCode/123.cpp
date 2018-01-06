/* *题目：
 *  14
 *  Longest Common Prefix
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result;
        if(strs.size() == 0){
            return result;
        }
        int i, j = 0;
        while(j < strs[0].size()){
            char tmp = strs[0][j];
            for(i = 1;i < strs.size();i++){  // 第一个字符串的每一个字符与后续字符串相同位置字符进行比较
                if(j >= strs[i].size() || tmp != strs[i][j]){
                    break;
                }
            }
            if(i != strs.size()){ // 出现不一样或者已达到某一字符串的长度，退出
                break;
            }
            result.push_back(tmp);
            j++;
        }
        return result;
    }
};