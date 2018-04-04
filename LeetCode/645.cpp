/* *题目：
 *  645
 *  Set Mismatch
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        vector<int> res;
        int sum = 0;
        for(int i = 1; i < nums.size(); ++i){
            sum += nums[i];
            if(nums[i] == nums[i-1]){
                res.push_back(nums[i-1]);
            }
        }
        
        sum += nums[0];
        
        res.push_back(res[0] - (sum - (1 + nums.size()) * nums.size() / 2));
        
        return res;
            
    }
};