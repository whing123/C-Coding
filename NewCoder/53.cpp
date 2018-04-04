/* *题目：
 *  二维数组中的查找
 * *思路：
 *  
 */

/*
从右上角开始查找，该行左边的都比它小，该列下边都比它大
如果等于目标数，找到
如果大于目标数，去掉当前列
如果小于目标数，去掉当前行
*/

class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int row = array.size();
        int col = array[0].size();
        
        if(row > 0 && col > 0){
            int row_i = 0;
            int col_j = col-1;
            while(row_i < row && col_j >= 0){
                if(array[row_i][col_j] == target){ // 找到
                    return true;
                }else if(array[row_i][col_j] > target){ // 大于目标数，去掉当前列
                    --col_j;
                }else{ // 小于目标数，去掉当前行
                    ++row_i;
                }
            }
        }
        
        return false;
    }
};