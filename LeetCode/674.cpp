/* *题目：
 *  674
 *  Longest Continuous Increasing Subsequence
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int size = nums.size();
        
        int maxLen = 0;
        int start = 0;
        int j;
        int tmp;
        for(int i = 0; i < size;){
            start = i; // a new beginning
            for(j = i+1; j < size; ++j){
                if(nums[j] <= nums[j-1]){ // suddenly decrease
                    tmp = j - start;
                    if(tmp > maxLen){ // if greater than before
                        maxLen = tmp;
                    }
                    
                    break;
                }
            }
            
            // last subsequence
            if(j == size){
                tmp = j - start;
                if(tmp > maxLen){
                    maxLen = tmp;
                }
                
                break;
            }
            
            i = j; //  next start
        }
        
        return maxLen;
    }
};