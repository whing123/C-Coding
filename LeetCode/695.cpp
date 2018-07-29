/* *题目：
 *  695
 *  Max Area of Island
 */

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int h = grid.size();
        int w = grid[0].size();
        
        int maxArea = 0;
        int tmp;
        for(int i = 0; i < h; ++i){
            for(int j = 0; j < w; ++j){
                
                if(grid[i][j] == 1){
                    tmp = 0;
                    
                    maxIsland(grid, h, w, i, j, tmp);
                    
                    if(maxArea < tmp){
                        maxArea = tmp;
                    }
                }
            }
        }
        
        return maxArea;
    }
    
    void maxIsland(vector<vector<int>>& grid, int h, int w, int a, int b, int& area){
        area++;
        grid[a][b] = 0; // visited
        
        // up down left right
        if(a-1 >= 0 && grid[a-1][b] == 1)
            maxIsland(grid, h, w, a-1, b, area);
        if(a+1 < h && grid[a+1][b] == 1)
            maxIsland(grid, h, w, a+1, b, area);
        if(b-1 >= 0 && grid[a][b-1] == 1)
            maxIsland(grid, h, w, a, b-1, area);
        if(b+1 < w && grid[a][b+1] == 1)
            maxIsland(grid, h, w, a, b+1, area);
        
    }
};