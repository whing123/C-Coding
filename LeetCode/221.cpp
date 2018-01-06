/* *题目：
 *  665
 *  Non-decreasing Array
 * *思路：
 *  
 */

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size();
        
        int cnt = 0;
        for(int i = 0; i < size-1; ++i){
            if(nums[i] > nums[i+1]){
                if(cnt > 0){ // 已经有过一次的话
                    return false;
                }
                cnt++;
                
                int flag = 0;
                if(i > 0){ // nums[i]去掉？
                    if(nums[i-1] > nums[i+1]){
                        flag++;
                    }
                }
                if(i+1 < size-1){ // nums[i+1]去掉？
                    if(nums[i] > nums[i+2]){
                        flag++;
                    }
                }
                if(flag == 2){ // 都不能去掉的话
                    return false;
                }
            }
        }
        
        return true;
    }
};

class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        bool modified = false;
        for (int i = 1, prev = a[0]; i < a.size(); i++) {
            if (a[i] < prev && modified++) return false;
            if (a[i] < prev && i - 2 >= 0 && a[i - 2] > a[i]) continue;
            prev = a[i];
        }
        return true;
    }
};