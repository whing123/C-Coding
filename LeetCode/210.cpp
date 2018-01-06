/* *题目：
 *  724
 *  Find Pivot Index
 * *思路：
 *  
 */

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        if(size == 0){ // 为空时
            return -1;
        }
        
        vector<int> sums(size, 0); // 保存累积和
        
        sums[0] = nums[0];
        for(int i = 1; i < size; ++i){
            sums[i] = sums[i-1] + nums[i];
        }
        
        int res = -1;
        for(int i = 1; i < size-1; ++i){ 
            if(sums[i-1] == sums[size-1] - sums[i]){ // 左是否等于右
                res = i;
                break;  // 立即退出
            }
        }
        
        // 首尾特殊情况
        if(sums[size-1]-nums[0] == 0){
            res = 0;
        }else if(sums[size-1-1] == 0){
            if(res == -1){ // 尚未找到时
                res = size - 1; // res原来为-1的话
            }
        }
        
        return res;
    }
};