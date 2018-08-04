/* *题目：
 *  79
 *  Word Search
 */

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty()){
            return false;
        }
        int height = board.size();
        if(height == 0){
            return false;
        }
        int width = board[0].size();
        if(width == 0){
            return false;
        }
        if(word.length() > height * width){
            return false;
        }
        
        for(int i = 0; i < height; i++){
            for(int j = 0; j < width; j++){
                if(dfs(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int len){
        if(board[row][col] == word[len]){
            if(++len == word.length()){
                return true;
            }
            
            // mark
            char tmp = board[row][col];
            board[row][col] = '.';
            
            bool res = 
                row && dfs(board, word, row-1, col, len) || // up
                col && dfs(board, word, row, col-1, len) || // left
                row+1 < board.size() && dfs(board, word, row+1, col, len) || // down
                col+1 < board[0].size() && dfs(board, word, row, col+1, len); // right
            
            board[row][col] = tmp;
            return res;
        }
        
        return false;
    }
};