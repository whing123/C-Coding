/* *题目：
 *  500
 *  Keyboard Row
 * *思路：
 *  
 * *技法：
 *  
 */


int arr[26] = {1,2,2,1,0,1,1,1,0,1,1,1,2,2,0,0,0,0,1,0,0,2,0,2,0,2}; //提前放好的行数

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        int size = words.size();
        vector<string> res;
        
        for(int i = 0;i < size;i++){  //对于每个word
            int wsize = words[i].size();
            int index = getIndex(words[i][0]);
            int j;
            for(j = 1;j < wsize;j++){
                if(getIndex(words[i][j]) != index){ //和第一个不在同一行时
                    break;
                }
            }
            if(j == wsize){   //都来自于同一行
                res.push_back(words[i]);
            }
        }
        
        return res;
    }
    
    int getIndex(char tmp){
        if('a' <= tmp && tmp <= 'z'){
            tmp -= 32;
        }
        tmp -= 'A';
        return arr[tmp];
    }
};
