/* *题目：
 *  48
 *  Rotate Image
 * *思路：
 *  
 */


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        helper(matrix, 0, 0, matrix.size());
    }
    
    void helper(vector<vector<int>>& matrix, int row, int col,  int size){
        if(size <= 1){
            return;
        }
        
        int step = size - 1;
        for(int i = 0; i < step; i++){ // first row except last one
            int x = row, y = col + i; // start pos
            int start = matrix[x][y];
            int tmp;
            do{ // exchange in a circle
            	// determine next pos 
                if(x == row){
                    x += y - col;
                    y = col + step; // last col
                }else if(y == col + step){
                    y -= x - row;
                    x = row + step; // last row
                }else if(x == row + step){
                    x = row + (y - col);
                    y = col; // first col
                }else{ // y == col
                    y += (row + step) - x;
                    x = row; // first row
                }
                
                // exchange data
                tmp = matrix[x][y];
                matrix[x][y] = start;
                start = tmp;
            }while(!(x == row && y == col+i)); // back to start pos
        }
        
        helper(matrix, row+1, col+1, size-2); // recursive
    }
};