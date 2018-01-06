/* *题目：
 *  661
 *  Image Smoother
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int w = M[0].size();
        int h = M.size();
        
        vector<vector<int>> res;
        
        for(int i = 0; i < h; ++i){
            vector<int> tmp;
            for(int j = 0; j < w; ++j){
                int sum = M[i][j];
                int cnt = 1;
                
                if(i-1 >= 0 && j-1 >= 0){
                    cnt += 3;
                    sum += M[i-1][j-1];
                    sum += M[i-1][j];
                    sum += M[i][j-1];
                }else if(i-1 >= 0){
                    cnt += 1;
                    sum += M[i-1][j];
                }else if(j-1 >= 0){
                    cnt += 1;
                    sum += M[i][j-1];
                }
                
                if(i+1 < h && j+1 < w){
                    cnt += 3;
                    sum += M[i+1][j+1];
                    sum += M[i+1][j];
                    sum += M[i][j+1];
                }else if(i+1 < h){
                    cnt += 1;
                    sum += M[i+1][j];
                }else if(j+1 < w){
                    cnt += 1;
                    sum += M[i][j+1];
                }
                
                if(i+1 < h && j-1 >= 0){
                    cnt += 1;
                    sum += M[i+1][j-1];
                }
                
                if(i-1 >= 0 && j+1 < w){
                    cnt += 1;
                    sum += M[i-1][j+1];
                }
                
                
                tmp.push_back(sum/cnt);
            }
            
            res.push_back(tmp);
        }
        
        return res;
    }
};