/* *题目：
 *  33
 *  Search in Rotated Sorted Array
 *  
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            if(nums[left] <= nums[mid]){ // 右边的少
                if(nums[left] <= target && target < nums[mid]){ // 在左一段
                    right = mid-1;  
                } else {
                    left = mid+1;
                }    
            }else{ // 右边的多
                if(nums[mid] < target && target <= nums[right]) { // 在右一段
                    left = mid+1;
                } else {
                    right = mid-1;
                }    
            }
        }
        
        return -1;
    }
};