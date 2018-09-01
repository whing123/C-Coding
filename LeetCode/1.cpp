/* *题目：
 *  1
 *  Two Sum
 */

/*
数列满足递增，设两个头尾两个指针i和j，
若ai + aj == sum，就是答案（相差越远乘积越小）
若ai + aj > sum，aj肯定不是答案之一（前面已得出 i 前面的数已是不可能），j -= 1
若ai + aj < sum，ai肯定不是答案之一（前面已得出 j 后面的数已是不可能），i += 1
O(n)
*/

// best
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int low = 0, high = array.size()-1;
        
        vector<int> res;
        while(low < high){
            if(array[low]+array[high] > sum){
                --high;
            }else if(array[low]+array[high] < sum){
                ++low;
            }else{
                res.push_back(array[low]);
                res.push_back(array[high]);
                return res;
            }
        }
        
        return res;
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

// worst
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
