/* *题目：
 *  434
 *  Number of Segments in a String
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int countSegments(string s) {
        int size = s.size();
        int i = 0;
        int cnt = 0;
        while(i < size){  //单词即，跳过空格后，遇到连续非空格序列，跳过，再遇到空格或到边界，计数
            while(i < size && s[i] == ' '){
                i++;
            }
            if(i == size){
                break;
            }
            while(i < size && s[i] != ' '){
                i++;
            }
            cnt++;
        }
        return cnt;
    }
};