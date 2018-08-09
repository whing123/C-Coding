/* *题目：
 *  55
 *  Jump Game
 */

// 超时
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size = nums.size();
        if(size < 2){
            return true;
        }
        
        return helper(nums, 0);
    }
    
    bool helper(vector<int>& nums, int pos){
        if(pos + nums[pos] >= nums.size()-1){
            return true;
        }
        
        for(int i = 1; i <= nums[pos]; i++){
            if(helper(nums, pos+i)){
                return true;
            }
        }
        
        return false;
    }
};

// best
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxV = 0;
        for(int i = 0; i <= maxV && i < nums.size(); i++){
            maxV = max(maxV, i+nums[i]);
            if(maxV >= nums.size()-1){
                return true;
            }
        }
        
        return false;
    }
};