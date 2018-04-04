/* *题目：
 *  389
 *  Find the Difference
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    char findTheDifference(string s, string t) {
        int size = t.size();
        int size_1 = size - 1;
        char res = 0;
        for(int i = 0;i < size_1;i++){
            res ^= s[i];
        }
        for(int j = 0;j < size;j++){
             res ^= t[j];
        }
        return res;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int size = t.size();
        int size_1 = size - 1;
        char res = 0;
        for(int i = 0;i < size_1;i++){
            res -= s[i];
        }
        for(int j = 0;j < size;j++){
             res += t[j];
        }
        return res;
    }
};

class Solution {
public:
    char findTheDifference(string s, string t) {
        int size = t.size();
        int size_1 = size - 1;
        vector<int> label(size,0);
        for(int i = 0;i < size_1;i++){
            for(int j = 0;j < size;j++){
                if(label[j] == 0 && s[i] == t[j]){
                    label[j] = 1;
                    break;
                }
            }
        }
        int j;
        for(j = 0;j < size;j++){
            if(label[j] == 0){
                break;
            }
        }
        return t[j];
    }
};