/* *题目：
 *  419
 *  Battleships in a Board
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int cnt = 0;
        for(int i = 0;i < board.size();i++){
            for(int j = 0;j < board[0].size();j++){
                //船的起始点很特殊，左边和上边是'.'
                if(board[i][j] == 'X' && (i == 0 || board[i-1][j] == '.') && (j == 0 || board[i][j-1] == '.')){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};