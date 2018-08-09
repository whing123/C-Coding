/* *题目：
 *  520
 *  Detect Capital 
 * *思路：
 
 */

class Solution {
public:
    bool detectCapitalUse(string word) {
        int size = word.size();
        bool firstCh = isCapital(word[0]);
        int sum = 0;
        for(int i = 1;i < size;i++){
            if(isCapital(word[i])){  //首字母外其他数字的检测，大写为1，小写为0
                sum++;
            }
        }
        
        if(firstCh && (sum == size - 1 || sum == 0)){  //首字母大写时，要么全大写，要么只有首字母大写
            return true;
        }else if(!firstCh && sum == 0){  //全小写 
            return true;
        }
        
        return false;
    }
    
    bool isCapital(char ch){
        if('A' <= ch && ch <= 'Z'){
            return true;
        }
        return false;
    }
};