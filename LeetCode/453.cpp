/* *题目：
 *  453
 *  Minimum Moves to Equal Array Elements
 
 */

// a move is incrementing n - 1 elements by 1
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minValue, numMove = 0;
        int size = nums.size();

        // find min
        minValue = nums[0];
        for(int i = 1; i < size; i++){
            if(minValue > nums[i]){
                minValue = nums[i];
            }
        }
        for(int i = 0; i < size; i++){
            numMove += nums[i] - minValue;
        }
        return numMove;
    }
};