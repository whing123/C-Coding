/* *题目：
 *  533
 *  Lonely Pixel II
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    //包含N个'B'的列，这个N个B所在的行要完全一样，而且也包含N个'B'
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        vector<vector<int>> row, col;
        
        //对每一行记录B所在的列
        for(int i = 0;i < picture.size();i++){
            vector<int> cnt;
            for(int j = 0; j < picture[i].size();j++){
                if(picture[i][j]=='B'){
                    cnt.push_back(j);
                }
            }
            row.push_back(cnt);
        }
        
        //对每一列记录B所在的行
        for(int i = 0;i < picture[0].size();i++){
            vector<int> cnt;
            for(int j = 0; j < picture.size();j++){
                if(picture[j][i]=='B'){
                   cnt.push_back(j);
                }
            }
            col.push_back(cnt);
        }
        
        int res = 0;
        for(int j = 0;j < picture[0].size();j++){
            if(col[j].size() == N){  //对于只含有N个B的列
                 vector<char> tmp = picture[col[j][0]]; //第一个B所在的行
                 int i;
                 for(i = 0;i < col[j].size();i++){
                     if(row[col[j][i]].size() != N || picture[col[j][i]] != tmp){ //如果该行B的个数不是N 或者 与第一行不一样，就不满足rule
                         break;
                     }
                 }   
                 if(i == col[j].size()){ //满足rule,则这个N个B都有效
                     res += N;
                 }
            }
        }
        
        return res;
    }
};