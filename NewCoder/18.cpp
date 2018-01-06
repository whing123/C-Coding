/* *题目：
 *  年终奖
 * *思路：
 *  
 */

 class Bonus {
public:
    int getMost(vector<vector<int> > board) {
        for(int i = 0; i < board.size(); ++i){
            for(int j = 0; j < board[0].size(); ++j){
                if(i == 0 && j > 0){ // first row
                    board[i][j] += board[i][j-1];
                }else if(j == 0 && i > 0){ // first col
                    board[i][j] += board[i-1][j];
                }else if(i > 0 && j > 0){
                    board[i][j] += max(board[i][j-1], board[i-1][j]); // from max of up and left
                }
            }
        }
         
        return  board[board.size()-1][board[0].size()-1];
    }
};