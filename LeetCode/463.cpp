/* *题目：
 *  463
 *  Island Perimeter
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[i].size();j++){
                if(grid[i][j] == 1){
                    cnt += 4;
                
                    if(i == 0 && j == 0){ //left top
                        if(i+1 < grid.size() && grid[i+1][j] == 1){
                            cnt--;
                        }
                        if(j+1 < grid[i].size() && grid[i][j+1] == 1){
                            cnt--;
                        }
                    }else if(i == 0 && j == grid[i].size()-1){ //right top
                        if(i+1 < grid.size() && grid[i+1][j] == 1){
                            cnt--;
                        }
                        if(j-1 >= 0 && grid[i][j-1] == 1){
                            cnt--;
                        }
                    }else if(i == grid.size()-1 && j == 0){ //left bottom
                        if(i-1 >= 0 && grid[i-1][j] == 1){
                            cnt--;
                        }
                        if(j+1 < grid[i].size() && grid[i][j+1] == 1){
                            cnt--;
                        }
                    }else if(i == grid.size()-1 && j == grid[i].size()-1){ //right bottom
                        if(i-1 >= 0 && grid[i-1][j] == 1){
                            cnt--;
                        }
                        if(j-1 >= 0 && grid[i][j-1] == 1){
                            cnt--;
                        }
                    }
                    else if(i == 0){ //top
                        if(i+1 < grid.size() && grid[i+1][j] == 1){
                            cnt--;
                        }
                        if(j+1 < grid[i].size() && grid[i][j+1] == 1){
                            cnt--;
                        }
                        if(j-1 >= 0 && grid[i][j-1] == 1){
                            cnt--;
                        }
                    }else if(j == 0){ //left
                        if(j+1 < grid[i].size() && grid[i][j+1] == 1){
                            cnt--;
                        }
                        if(i+1 < grid.size() && grid[i+1][j] == 1){
                            cnt--;
                        }
                        if(i-1 >= 0 && grid[i-1][j] == 1){
                            cnt--;
                        }
                    }else if(i == grid.size()-1){ //down
                        if(i-1 >= 0 && grid[i-1][j] == 1){
                            cnt--;
                        }
                        if(j-1 >= 0 && grid[i][j-1] == 1){
                            cnt--;
                        }
                        if(j+1 < grid[i].size() && grid[i][j+1] == 1){
                            cnt--;
                        }
                    }else if(j == grid[i].size()-1){ //right
                        if(j-1 >= 0 && grid[i][j-1] == 1){
                            cnt--;
                        }
                        if(i+1 < grid.size() && grid[i+1][j] == 1){
                            cnt--;
                        }
                        if(i-1 >= 0 && grid[i-1][j] == 1){
                            cnt--;
                        }
                    }else{
                        if(grid[i][j-1] == 1){
                            cnt--;
                        }
                        if(grid[i+1][j] == 1){
                            cnt--;
                        }
                        if(grid[i-1][j] == 1){
                            cnt--;
                        }
                        if(grid[i][j+1] == 1){
                            cnt--;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
