/* *题目：
 *  827
 *  Making A Large Island
 */

// better
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        
        int size = 0;
        
        // after changing 0 to 1, max size
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 0) {                
                    vector<vector<bool>> visited(R, vector<bool>(C, false));
                    int cnt = 1;
                    visited[i][j] = true;
                    dfs(grid, visited, R, C, i, j, cnt);
                    if (cnt > size) {
                        size = cnt;
                    }
                }
            }
        }
        
        if (size == 0) {
            size = R * C;
        }
        
        return size;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int R, int C, int r, int c, int& cnt) {
        if (r-1 >= 0 && grid[r-1][c] == 1 && visited[r-1][c] == false) {
            visited[r-1][c] = true;
            dfs(grid, visited, R, C, r-1, c, ++cnt);
        }
        if (r+1 < R && grid[r+1][c] == 1 && visited[r+1][c] == false) {
            visited[r+1][c] = true;
            dfs(grid, visited, R, C, r+1, c, ++cnt);
        }
        if (c-1 >= 0 && grid[r][c-1] == 1 && visited[r][c-1] == false) {
            visited[r][c-1] = true;
            dfs(grid, visited,R, C, r, c-1, ++cnt);
        }
        if (c+1 < C && grid[r][c+1] == 1 && visited[r][c+1] == false) {
            visited[r][c+1] = true;
            dfs(grid, visited, R, C, r, c+1, ++cnt);
        }
    } 
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int R = grid.size();
        int C = grid[0].size();
        
        int size = 0;
        {
            // original max size
            vector<vector<bool>> visited(R, vector<bool>(C, false));
            for (int i = 0; i < R; ++i) {
                for (int j = 0; j < C; ++j) {
                    if (grid[i][j] == 1 && visited[i][j] == false) {
                        int cnt = 1;
                        visited[i][j] = true;
                        dfs(grid, visited, R, C, i, j, cnt);
                        if (cnt > size) {
                            size = cnt;
                        }
                    }
                }
            }
        }   
        
        // after changing 0 to 1, max size
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (grid[i][j] == 0) {                
                    vector<vector<bool>> visited(R, vector<bool>(C, false));
                    int cnt = 1;
                    visited[i][j] = true;
                    dfs(grid, visited, R, C, i, j, cnt);
                    if (cnt > size) {
                        size = cnt;
                    }
                }
            }
        }
        
        return size;
    }
    
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int R, int C, int r, int c, int& cnt) {
        if (r-1 >= 0 && grid[r-1][c] == 1 && visited[r-1][c] == false) {
            visited[r-1][c] = true;
            dfs(grid, visited, R, C, r-1, c, ++cnt);
        }
        if (r+1 < R && grid[r+1][c] == 1 && visited[r+1][c] == false) {
            visited[r+1][c] = true;
            dfs(grid, visited, R, C, r+1, c, ++cnt);
        }
        if (c-1 >= 0 && grid[r][c-1] == 1 && visited[r][c-1] == false) {
            visited[r][c-1] = true;
            dfs(grid, visited,R, C, r, c-1, ++cnt);
        }
        if (c+1 < C && grid[r][c+1] == 1 && visited[r][c+1] == false) {
            visited[r][c+1] = true;
            dfs(grid, visited, R, C, r, c+1, ++cnt);
        }
    } 
};