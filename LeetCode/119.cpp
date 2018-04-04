/* *题目：
 *  119
 *  Pascal's Triangle II
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex+1,0);
        row[0] = 1;
        row[rowIndex] = 1;
        if(rowIndex < 2){
            return row;
        }
        vector<int> preRow = getRow(rowIndex - 1);
        for(int i = 1;i < rowIndex;i++){
            row[i] = preRow[i-1] + preRow[i];
        }
        return row;
    }
};