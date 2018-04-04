/* *题目：
 *  496
 *  Next Greater Element I
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> nums2;  //nums2的数，及其下标
        for(int i = 0; i < nums.size(); i++){
            nums2[nums[i]] = i;
        }
        
        vector<int> pos; //位置
        unordered_map<int, int>::iterator it;
        for(int i = 0; i < findNums.size(); i++){
            if((it = nums2.find(findNums[i])) != nums2.end()){  //在nums2中找对应的下标位置
                pos.push_back(it->second);
            }
        }
        
        vector<int> res;
        int j;
        for(int i = 0; i < findNums.size(); i++){
            for(j = pos[i] + 1; j < nums.size();j++){  //在右边查找
                if(nums[j] > findNums[i]){  //查找第一大
                    res.push_back(nums[j]);
                    break;
                }
            }
            if(j == nums.size()){  //若没找到
                res.push_back(-1);
            }
        }
        
        return res;
    }
};