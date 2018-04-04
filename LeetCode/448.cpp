/* *题目：
 *  448
 *  Find All Numbers Disappeared in an Array
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int size = nums.size();
        vector<int> result, tmp(size+1, 0);
        int j = 0;
        while(j < size){ //1到size 哪个出现哪个累加1
            tmp[nums[j++]]++;
        }
        j = 1;
        while(j <= size){
            if(tmp[j] == 0){ //没有出现的装入
                result.push_back(j);
            }
            j++;
        }
        return result;
    }
};