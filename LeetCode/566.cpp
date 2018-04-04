/* *题目：
 *  566
 *  Reshape the Matrix 
 * *思路：
 *  
 * *技法：
 *  
 */

 
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int row = nums.size();
        int col = nums[0].size();
        
        if(r * c != row * col){
            return nums;
        }
        
        vector<vector<int>> res;
        
        int index;
        for(int i = 0; i < r; ++i){
            vector<int> tmp;
            for(int j = 0; j < c; ++j){
                index = i * c + j;
                tmp.push_back(nums[index / col][index % col]);
            }
            
            res.push_back(tmp);
        }
        
        return res;
    }
};
