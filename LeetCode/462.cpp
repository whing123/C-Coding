/* *题目：
 *  462
 *  Minimum Moves to Equal Array Elements II
 * *思路：
 *  
 
 */

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int size = nums.size();
        int moves = 0;
        int avg = (size-1)/2; //奇数个数最中间位置，偶数个位置中间位置有两个，这是第一个
        
        //到中值的距离最短,而不是平均值
        sort(nums.begin(),nums.end());
        avg = nums[avg];
        
        for(int i = 0;i < size;i++){
            moves += abs(nums[i]-avg);
        }
        
        return moves;
    }
};