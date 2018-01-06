/* *题目：
 *  349
 *  Intersection of Two Arrays
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums_tmp, nums1_tmp, nums2_tmp;
        int size_1 = nums1.size(), size_2 = nums2.size();
        //unique
        for(int i = 0;i < size_1;i++){
            if(!isExisted(nums1_tmp,nums1[i])){
                nums1_tmp.push_back(nums1[i]);
            }
        }
        //unique
        for(int i = 0;i < size_2;i++){
            if(!isExisted(nums2_tmp,nums2[i])){
                nums2_tmp.push_back(nums2[i]);
            }
        }
        
        size_1 = nums1_tmp.size();
        size_2 = nums2_tmp.size();
        for(int i = 0;i < size_2;i++){
            for(int j = 0;j < size_1;j++){
                if(nums2_tmp[i] == nums1_tmp[j]){
                    nums_tmp.push_back(nums2_tmp[i]);
                }
            }
        }
        
        return nums_tmp;
    }
    
    bool isExisted(vector<int>& nums, int n){
        int size = nums.size();
        for(int i = 0;i < size;i++){
            if(n == nums[i]){
                return true;
            }
        }
        return false;
    }
    
};