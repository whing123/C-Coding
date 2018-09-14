/*
  417
  Pacific Atlantic Water Flow
  能达到P和A的点
*/

/*
The parameter o in dfs means which ocean it has been reached. 
Let the Pacific flow first and mark as 'P', 
then let Atlantic flow to get the intersection.
先让P泛滥，再让A泛滥，遇到P则符合要求
*/
class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        int row = matrix.size();
        if(row == 0){
            return res;
        }
        int col = matrix[0].size();
        
        
        vector<vector<char>> vis(row, vector<char>(col, '\0'));
        
        // start points for searching
        for(int i = 0; i < row; i++){
            dfs(matrix, vis, res, row, col, i, 0, 'P');
        }
        for(int j = 0; j < col; j++){
            dfs(matrix, vis, res, row, col, 0, j, 'P');
        }
        
        for(int i = 0; i < row; i++){
            dfs(matrix, vis, res, row, col, i, col-1, 'A');
        }
        for(int j = 0; j < col; j++){
            dfs(matrix, vis, res, row, col, row-1, j, 'A');
        }
        
        return res;
    }
    
    void dfs(vector<vector<int>>& mat, vector<vector<char>>& vis, vector<pair<int, int>>& res, int row, int col, int r, int c, char o){
        if(o == vis[r][c]){
            return;
        }
        
        if(o == 'A' && vis[r][c] == 'P'){ // if both P & A can reach, then add to the result list
            res.push_back(make_pair(r, c));
        }
        vis[r][c] = o;
        
        if(r-1 >= 0 && mat[r][c] <= mat[r-1][c])
            dfs(mat, vis, res, row, col, r-1, c, o);
        if(r+1 < row && mat[r][c] <= mat[r+1][c])
            dfs(mat, vis, res, row, col, r+1, c, o);
        if(c-1 >= 0 && mat[r][c] <= mat[r][c-1])
            dfs(mat, vis, res, row, col, r, c-1, o);
        if(c+1 < col && mat[r][c] <= mat[r][c+1])
            dfs(mat, vis, res, row, col, r, c+1, o);
    }
};