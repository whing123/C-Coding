/* *题目：
 *  442
 *  Find All Duplicates in an Array
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        /*
        int size = nums.size()-1;
        vector<int> res;
        //排序
        sort(nums.begin(),nums.end());
        for(int i = 0;i < size;i++){
            if(nums[i] == nums[i+1]){
                res.push_back(nums[i]);
                i++;
            }
        }
        return res;
        */
        
        //map统计次数
        int size = nums.size();
        vector<int> res;
        unordered_map<int,int> tab;
        for(int i = 0;i < size;i++){
            tab[nums[i]]++;
        }
        
        unordered_map<int,int>::iterator it;
        for(it = tab.begin();it != tab.end();it++){
            if(it->second == 2){
                res.push_back(it->first);
            }
        }
        return res;
    }
};