/* *题目：
 *  733
 *  Flood Fill
 * *思路：
 *  
 */

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // 二维数组为空
        if(image.size() == 0){ 
            return image;
        }
        
        int oldColor = image[sr][sc];
        // 颜色没有改变
        if(oldColor == newColor){
            return image;
        }
        
        image[sr][sc] = newColor; // starting pixel
        traverse(image, sr, sc, newColor, oldColor);  
        
        return image;
    }
    
    void traverse(vector<vector<int>>& image, int sr, int sc, int newColor, int oldColor){
        if(sr-1 >= 0){ // up
            if(image[sr-1][sc] == oldColor){
                image[sr-1][sc] = newColor;
                traverse(image, sr-1, sc, newColor, oldColor);
            }
        }
        if(sr+1 < image.size()){ // down
            if(image[sr+1][sc] == oldColor){
                image[sr+1][sc] = newColor;
                traverse(image, sr+1, sc, newColor, oldColor);
            }
        }
        if(sc-1 >= 0){ // left
            if(image[sr][sc-1] == oldColor){
                image[sr][sc-1] = newColor;
                traverse(image, sr, sc-1, newColor, oldColor);
            }
        }
        if(sc+1 < image[0].size()){ // right
            if(image[sr][sc+1] == oldColor){
                image[sr][sc+1] = newColor;
                traverse(image, sr, sc+1, newColor, oldColor);
            }
        }
    }
};