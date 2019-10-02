/* *题目：
 *  1
 *  Two Sum
    两数之和
 */

/*
若数列满足递增，设两个头尾两个指针i和j，
若ai + aj == sum，就是答案（相差越远乘积越小）
若ai + aj > sum，aj肯定不是答案之一（前面已得出 i 前面的数已是不可能），j -= 1
若ai + aj < sum，ai肯定不是答案之一（前面已得出 j 后面的数已是不可能），i += 1
O(n)
*/
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

// 基于map，一次遍历，假定乱序
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); ++i) {
            int other = target - nums[i];
            if (hash.find(other) != hash.end()) {
                return vector<int>{hash[other], i};
            }

            hash[nums[i]] = i;
        }  
        
        return vector<int>();
    }
};

