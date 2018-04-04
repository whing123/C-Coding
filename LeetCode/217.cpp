/* *题目：
 *  217
 *  Contains Duplicate
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int size = nums.size();
        map<int,int> mapNum;
        for(int i = 0;i < size;i++){
            if(mapNum.find(nums[i])!=mapNum.end()){
                return true;
            }
            mapNum.insert(pair<int,int>(nums[i],i));
        }
        return false;
    }
};