/* *题目：
 *  477
 *  Total Hamming Distance
 */

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int cnt = 0;
        int size = nums.size();
        if(size == 0){
            return cnt;
        }
        
        vector<int> cal(32,0);
        for(int i = 0;i < size;i++){
            for(int j = 0;j < 32;j++){
                if((nums[i]>>j) & 0x01){
                    cal[j]++;  // 统计每个数每个位上的1的个数
                }
            }
        }
        
        for(int j = 0;j < 32;j++){
            cnt += cal[j] * (size - cal[j]); // 1 的个数乘以 0 的个数
        }
        return cnt;
    }

};