/* *题目：
 *  409
 *  Longest Palindrome
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
    struct pair{
        char ch;
        int count;
        pair(char c, int cnt = 0):ch(c), count(cnt){}
        ~pair(){}
    };
public:
    int longestPalindrome(string s) {
        int sizeOfStr = s.size();
        vector<pair> counter;
        for(int i = 0;i < sizeOfStr;i++){
            if(!exist(counter,s[i])){
                counter.push_back(pair(s[i],1));
            }
        }
        
        int sizeOfV = counter.size();
        int sum = 0;
        for(int i = 0;i < sizeOfV;i++){
            sum += counter[i].count / 2;
        }
        
        sum *= 2;
        if(sum <sizeOfStr){
            return sum + 1;
        }
        return sum;
    }
    
    bool exist(vector<pair> &c, char t){
        int size = c.size();
        for(int i = 0;i < size;i++){
            if(t == c[i].ch){
                c[i].count++;
                return true;
            }
        }
        return false;
    }
};