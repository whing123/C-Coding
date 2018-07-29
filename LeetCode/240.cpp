/* *题目：
 *  240
 *  Search a 2D Matrix II
 * *思路：
 *  
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0){
            return false;
        }
        return searchHelper(matrix, target, 0, matrix[0].size()-1);
    }
    
    bool searchHelper(vector<vector<int>>& matrix, int target, int row, int col){
        if(row >= matrix.size() || col < 0){
            return false;
        }
        
        if(matrix[row][col] == target){
            return true;
        }else if(matrix[row][col] > target){ // cut col, move left
            col--;
        }else{  // cut row, move down
            row++;
        }
        
        return searchHelper(matrix, target, row, col);
    }
};