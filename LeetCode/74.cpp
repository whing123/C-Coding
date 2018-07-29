/* *题目：
 *  74
 *  Search a 2D Matrix
 * *思路：
 *  
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0){
            return false;
        }
        int column = matrix[0].size();
        if(column == 0){
            return false;
        }
        
        vector<int> lastColumn(row, 0);
        for(int i = 0; i < row; i++){
            lastColumn[i] = matrix[i][column-1]; // save last column
        }
        
        int possibleRow;
        if(binarySearch(lastColumn, target, possibleRow)){ // search last column
            return true;
        }
        if(possibleRow < row){
            return binarySearch(matrix[possibleRow], target, possibleRow); // search target row
        }
        
        return false;
    }
    
    bool binarySearch(vector<int>& arr, int target, int& possibleRow){
        int low = 0, high = arr.size()-1;
        int mid;
        while(low <= high){
            mid = low + (high-low) / 2;
            if(arr[mid] == target){
                return true;
            }else if(arr[mid] > target){
                high = mid-1;
            }else{
                low = mid+1;
            } 
        }
        possibleRow = low; // find possible interval
        
        return false;
    }
};