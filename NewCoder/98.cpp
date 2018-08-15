/*
 98
 顺时针打印矩阵
*/

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> res;
        print(matrix, 0, 0, matrix.size(), matrix[0].size(), res);
        return res;
    }
    
    void print(vector<vector<int> >& matrix, int row, int col, int h, int w, vector<int>& res) {
        if(w == 0 || h == 0){
            return;
        }
        if(h == 1){
            for(int i = 0; i < w; i++){
                res.push_back(matrix[row][col+i]);
            }
            return;
        }
        if(w == 1){
            for(int i = 0; i < h; i++){
                res.push_back(matrix[row+i][col]);
            }
            return;
        }
        
        // first row
        for(int i = 0; i < w; i++){
            res.push_back(matrix[row][col+i]);
        }
        // last col
        for(int i = 1; i < h; i++){
            res.push_back(matrix[row+i][col+w-1]);
        }
        // last row
        for(int i = w-2; i >= 0; i--){
            res.push_back(matrix[row+h-1][col+i]);
        }
        // first col
        for(int i = h-2; i > 0; i--){
            res.push_back(matrix[row+i][col]);
        }
        
        print(matrix, row+1, col+1, h-2, w-2, res);
    }
};