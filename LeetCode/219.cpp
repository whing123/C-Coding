/* *题目：
 *  219
 *  Contains Duplicate II
 * *思路：

 */

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int,int> Map;
        unordered_map<int,int>::iterator it;
        for(int i = 0;i < size;i++){
            if((it = Map.find(nums[i])) == Map.end()){
                Map[nums[i]] = i; 
            }else{
                if(i - it->second <= k){
                    return true;
                }else{
                    it->second = i;
                }
            }
        }
        return false;
    }
};