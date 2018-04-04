/* *题目：
 *  557
 *  Reverse Words in a String III 
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string reverseWords(string s) {
        int size = s.size();
        
        for(int i = 0; i < size;){
            while(s[i] == ' '){
                i++;
            }
            int start = i;
            while(i < size && s[i] != ' '){
                i++;
            }
            
            inverse(s, start, i);
        }
        
        return s;
    }
    
    void inverse(string &s, int start, int end){
        int half = (end - start) / 2;
        for(int i = 0; i < half; ++i){
            char tmp = s[start + i];
            s[start + i] = s[end - 1 - i];
            s[end - 1 - i] = tmp;
        }
    }
};