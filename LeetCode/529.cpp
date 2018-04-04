/* *题目：
 *  529
 *  Minesweeper
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        
        //获取点击位置
        int row, col;
        row = click[0];
        col = click[1];
        
        //踩雷
        if(board[row][col] == 'M'){
            board[row][col] = 'X';
            return board;
        }
        
        //获取扫雷地图的2D尺寸
        int H = board.size();
        int W = board[0].size();
        
        //踩到E上
        RevealE(board,H,W,row,col);
        
        return board;
    }
    
    void RevealE(vector<vector<char>>& board, int H, int W, int row, int col){
         int num = getNumOfMines(board,H,W,row,col);  //找周围的地雷数
         if(num == 0){  //周围无地雷
             board[row][col] = 'B';
             
             //在其周围递归搜索
             for(int m = -1;m < 2;m++){
                if(row+m < 0 || row+m > H-1){
                    continue;
                }
                for(int n = -1;n < 2;n++){
                    if(m == 0 && n == 0 || col+n < 0 || col+n > W-1){
                        continue;
                    }
                    
                    if(board[row+m][col+n] == 'E'){
                        RevealE(board,H,W,row+m,col+n);
                    }
                }
            }
            
         }else{
             board[row][col] = '0' + num;  //显示周围地雷数
             return;
         }
    }
    
    int getNumOfMines(vector<vector<char>>& board, int H, int W, int row, int col){
        int res = 0;
        
        //八个方向
        for(int m = -1;m < 2;m++){
            if(row+m < 0 || row+m > H-1){  //行范围检查
                continue;
            }
            for(int n = -1;n < 2;n++){
                if(m == 0 && n == 0 || col+n < 0 || col+n > W-1){  //列范围检查
                    continue;
                }
                    
                if(board[row+m][col+n] == 'M'){
                    res++;
                }
            }
        }
        
        return res;
    }
};