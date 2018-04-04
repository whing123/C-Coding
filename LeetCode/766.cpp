/* *题目：
 *  766
 *  Toeplitz Matrix
 */


class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int h = matrix.size();
        int w = matrix[0].size();
        
        // 第一行
        for(int col = w-2; col >= 0; --col){
            int i = 0;
            int j = col;
            while(++i < h && ++j < w){
                if(matrix[i][j] != matrix[0][col]){
                    return false;
                }
            }
        }
        
        // 第一列
        for(int row = 1; row < h-1; ++row){
            int i = row;
            int j = 0;
            while(++i < h && ++j < w){
                if(matrix[i][j] != matrix[row][0]){
                    return false;
                }
            }
        }
        
        return true;
    }
};

// 巧妙解法
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] != matrix[i - 1][j - 1])
                    return false;
        return true;
    }
};