/* *题目：
 *  1
 *  Two Sum
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp;
        int num_tmp;
        int i, j;
        int vector_size = nums.size();
        int vector_size_1 = nums.size() - 1;
        
        for(i = 0;i < vector_size_1;i++)
        {
            num_tmp = target - nums[i];
            for(j = i + 1;j < vector_size;j++)
            {
                if(num_tmp == nums[j])
                {
                    tmp.push_back(i);
                    tmp.push_back(j);
                    return tmp;
                }
            }
        }
        return tmp;
    }
};


// map
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res(2);
        map<int,int> mp;
        map<int,int>::iterator it;
        for(int i = 0; i < nums.size(); ++i){
            if((it = mp.find(target-nums[i])) != mp.end()){
                res[0] = i;
                res[1] = it->second;
                break;
            }
            
            mp[nums[i]] = i;
        }
        
        return res;
    }
};