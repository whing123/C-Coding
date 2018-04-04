/* *题目：
 *  287
 *  Find the Duplicate Number
 * *思路：
 *  
 */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            int index = nums[i] % nums.size();
            if(nums[index] > nums.size()){
                return index;
            }else{
                nums[index] += nums.size();
            }
        }
        
        return 0;
    }
};

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size()-1;
        while(low < high){
            int mid = low + (high - low) / 2;
            int cnt = 0;
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] <= mid)
                    cnt++;
            }
            if(cnt <= mid)
                low = mid+1;
            else
                high = mid;
        }
        
        return low;
    }
};