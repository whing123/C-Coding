/* *题目：
 *  531
 *  Lonely Pixel I
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int size = picture.size();
        map<int,int> rows,cols;
        
        vector<pair<int,int>> pos;
        for(int i = 0;i < size;i++){
            for(int j = 0;j < picture[i].size();j++){
                if(picture[i][j] == 'B'){  //统计行序和列序
                    rows[i]++;
                    cols[j]++;
                    pos.push_back(pair<int,int>(i,j));  //保存坐标
                }
            }
        }
        
        int res = 0;
        for(int i = 0;i < pos.size();i++){
            if(rows[pos[i].first] == 1 && cols[pos[i].second] == 1){  //该行该列都只出现一次
                res++;
            }
        }
        
        return res;
    }
};