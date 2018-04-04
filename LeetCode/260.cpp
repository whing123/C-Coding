/* *题目：
 *  260
 *  Single Number III
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        /*
        //map统计
        unordered_map<int,int> tab;
        int size = nums.size();
        for(int i = 0;i < size;i++){
            tab[nums[i]]++;
        }
        
        vector<int> res;
        unordered_map<int,int>::iterator it;
        for(it = tab.begin();it != tab.end();it++){
            if(it->second == 1){
                res.push_back(it->first);
            }
        }
        return res;
        */
        
        //排序比较
        int size = nums.size();
        vector<int> res;
        
        sort(nums.begin(),nums.end());
        for(int i = 0;i < size;){
            if(i+1 < size && nums[i] == nums[i+1]){
                i += 2;
                continue;
            }else{
                res.push_back(nums[i++]);
            }
        }
        
        return res;
    }
};