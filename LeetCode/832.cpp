/*
  832
  Flipping an Image
  横向翻转，再01颠倒
*/

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        int row = A.size();
        int col = A[0].size();
        
        for(int i = 0; i < row; i++){
            reverse(A[i].begin(), A[i].end());
            for(int j = 0; j < col; j++){
                A[i][j] = (A[i][j] + 1) % 2;
            }
        }
        
        return A;
    }
};