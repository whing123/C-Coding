/* *题目：
 *  118
 *  Pascal's Triangle
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> nums;
        int j;
        nums.resize(numRows);
        for(int i = 0;i < numRows;i++)
        {
            nums[i].resize(i+1);
            nums[i][0] = 1;
            for(j =  1;j <= i/2;j++)
            {
                nums[i][j] = nums[i-1][j-1] + nums[i-1][j];
            }
            
            for(j =  0;j <= i/2;j++){
                nums[i][i-j] = nums[i][j];
            }
        }
        return nums;
    }
};