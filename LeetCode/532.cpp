/* *题目：
 *  532
 *  K-diff Pairs in an Array 
 */

/*
另一种新思路：
去重后，对每一个数i判断，i+k是否在数组里，如果是则+1
*/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());  //排序
        int res = 0;
        
        if(k == 0){  //差值为0
            int i = 0;
            while(i < nums.size()){
                bool flag = false;
                while(i+1 < nums.size() && nums[i] == nums[i+1]){
                    i++;
                    if(!flag){  //对相同的只记录一次
                        flag = true;
                        res++;
                    }
                }
                i++;
            }
        }else{
            int i = 0;
            while(i < nums.size()){
                while(i+1 < nums.size() && nums[i] == nums[i+1]){
                    nums.erase(nums.begin()+i+1);  //擦除重复的
                }
                i++;
            }
            
            for(int j = 0;j < nums.size();j++){
                for(int m = j+1;m < nums.size();m++){
                    if(nums[m]-nums[j] == k){ //如果找到了
                        res++;
                        break;
                    }else if(nums[m]-nums[j] > k){ //找不到时，及时退出
                        break;
                    }
                }
            }
            
        }
        
        return res;
    }
};


class Solution {
public:
    /**
     * for every number in the array:
     *  - if there was a number previously k-diff with it, save the smaller to a set;
     *  - and save the value-index to a map;
     */
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) {
            return 0;
        }
        unordered_set<int> starters;
        unordered_map<int, int> indices;
        for (int i = 0; i < nums.size(); i++) {
            if (indices.count(nums[i] - k)) {
                starters.insert(nums[i] - k);
            }
            if (indices.count(nums[i] + k)) {
                starters.insert(nums[i]);
            }

            indices[nums[i]] += 1;
        }
        
        return starters.size();
    }
};

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> m;
        for (int n : nums) m[n]++;
        int cnt = 0;
        for (auto p : m) {
          if ((!k && p.second > 1)
            || (k && m.count(p.first + k))) ++cnt;
        }
        return cnt;
    }
};