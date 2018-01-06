/* *题目：
 *  88
 *  Merge Sorted Array
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int aIndex = m - 1;
        int bIndex = n - 1;
        int cnt = m + n - 1;
        
        while(aIndex >= 0 || bIndex >= 0){
            if(aIndex >= 0 && bIndex >= 0){
                nums1[cnt--] = nums1[aIndex] > nums2[bIndex] ? nums1[aIndex--] : nums2[bIndex--];
            }else if(bIndex >= 0){
                nums1[cnt--] = nums2[bIndex--];
            }else{
                break;
            }
        }
    }
};