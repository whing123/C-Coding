/* *题目：
 *  55
 *  Jump Game
 */

// best
/* 
Idea is to work backwards from the last index. 
Keep track of the smallest index that can "jump" to the last index. 
Check whether the current index can jump to this smallest index.
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int last = nums.size()-1;
        for(int i = nums.size()-2; i >= 0; i--) {
            if(i+nums[i] >= last) {
                last = i;
            }
        }
        
        return last <= 0;
    }
};

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

// better
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxV = 0;
        for(int i = 0; i <= maxV && i < nums.size(); i++){ // 在目前能到的范围内，寻找下一个最远处
            maxV = max(maxV, i+nums[i]);
            if(maxV >= nums.size()-1){
                return true;
            }
        }
        
        return false;
    }
};