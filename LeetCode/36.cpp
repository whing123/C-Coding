/* *题目：
 *  36
 *  Valid Sudoku
 * *思路：
 
 */

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row_check[10] = {0};
        int col_check[10] = {0};
        int box_check[10] = {0};
        
        int i, j;
        
        for(i = 0;i < 9;i++)
        {
            for(j = 0;j < 9;j++)
            {
                if(!checkOut(col_check, board[j][i] - '0')) // each col
                    return false;
                if(!checkOut(row_check, board[i][j] - '0')) // each row
                    return false;
                if(!checkOut(box_check, board[i/3*3+j/3][i%3*3+j%3] - '0')) // each 3x3
                    return false;
            }
            memset(col_check, 0, sizeof(col_check));
            memset(row_check, 0, sizeof(row_check));
            memset(box_check, 0, sizeof(box_check));
        }
        return true;
    }
    
    // check repetition
    bool checkOut(int check[], int val)
    {
        if(val < 0)
            return true;
        if(check[val] == 1)
            return false;
        check[val] = 1;
        return true;
    }
};