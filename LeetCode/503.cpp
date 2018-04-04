/* *题目：
 *  503
 *  Next Greater Element II
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        
        for(int i = 0;i < nums.size();i++){
            int j;
            for(j = (i+1)%nums.size(); j != i;j = (j+1) % nums.size()){  //循环搜索
                if(nums[j] > nums[i]){
                    res.push_back(nums[j]);
                    break;
                }
            }
            if(j == i){  //没找到比它大的
                res.push_back(-1);
            }
            
        }
        
        return res;
    }
};