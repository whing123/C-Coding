/* *题目：
 *  238
 *  Product of Array Except Self
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> pre(size,1), post(size,1);
        
        //前向累乘
        pre[0] = nums[0];
        for(int i = 1;i < size;i++){
            pre[i] = pre[i-1] * nums[i];
        }
        
        //后向累乘
        post[size-1] = nums[size-1];
        for(int i = size-2;i >= 0;i--){
            post[i] = post[i+1] * nums[i];
        }
        
        vector<int> res(size,0);
        res[0] = post[1];
        res[size-1] = pre[size-2];
        for(int i = 1;i < size-1;i++){
            res[i] = pre[i-1] * post[i+1];  //前向累乘 * 后向累乘
        }
        return res;
    }
};