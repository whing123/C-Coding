/* *题目：
 *  421
 *  Maximum XOR of Two Numbers in an Array
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int size = nums.size();
        int res = INT_MIN;
        int tmp;
        
        for(int i = 0;i < size;i++){
            for(int j = i; j < size;j++){ //ai,aj可以相同
                tmp = nums[i] ^ nums[j];
                if(tmp > res){
                    res = tmp;
                }
            }
        }
        
        return res;
    }
};