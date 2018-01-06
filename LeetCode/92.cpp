/* *题目：
 *  345
 *  Reverse Vowels of a String
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string reverseVowels(string s) {
        int size = s.size();
        vector<int> index;
        for(int i = 0;i < size;i++){
            if(isVowel(s[i])){
                index.push_back(i);
            }
        }
        
        int size2 = index.size();
        int newSize2 = size2 / 2;
        char tmp;
        for(int i = 0;i < newSize2;i++){
            tmp = s[index[i]];
            s[index[i]] = s[index[size2 - 1 - i]];
            s[index[size2 - 1 - i]] = tmp;
        }
        return s;
    }
    
    bool isVowel(char ch){
        switch(ch){
            case 'a' :
            case 'A' :
            case 'e' :
            case 'E' :
            case 'i' :
            case 'I' :
            case 'o' :
            case 'O' :
            case 'u' :
            case 'U' :
                return true;
            default:
                return false;
        }
    }
};