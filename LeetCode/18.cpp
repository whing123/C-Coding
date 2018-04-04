/* *题目：
 *  18
 *  4Sum
 */

// DFS超时
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> seq;
        
        sort(nums.begin(), nums.end());
        dfs(nums, target, res, seq, 0, 0);
        return res;
    }
    
    void dfs(vector<int>& nums, int target, vector<vector<int>>& res, vector<int>& cur, int cursum, int start){
        if(cursum == target && cur.size() == 4){
            res.push_back(cur);
            return;
        }else if(cur.size() > 4){
            return;
        }
        
        unordered_set<int> hash;
        for(int i = start; i < nums.size(); ++i){
            if(hash.find(nums[i]) == hash.end()){
                cur.push_back(nums[i]);
                dfs(nums, target, res, cur, cursum+nums[i], i+1);
                cur.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
};

// 3Sum思想
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        if(nums.size() < 4){
            return res;
        }
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-3; ++i){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int target_3 = target - nums[i];
            
            for(int  j = i+1; j < nums.size()-2; ++j){
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                
                int target_2 = target_3 - nums[j];
                
                int left = j+1, right = nums.size()-1;
                while(left < right){
                    int cursum = nums[left] + nums[right];
                    if(cursum == target_2){
                        vector<int> tmp(4);
                        tmp[0] = nums[i];
                        tmp[1] = nums[j];
                        tmp[2] = nums[left];
                        tmp[3] = nums[right];
                        res.push_back(tmp);
                        
                        left++;
                        right--;
                        
                        while(left < right && nums[left] == nums[left-1]) left++;
                        while(left < right && nums[right] == nums[right+1]) right--;
                    }else if(cursum < target_2){
                        left++;
                    }else{
                        right--;
                    }
                }
                
                //while(j + 1 < nums.size() && nums[j + 1] == nums[j]) ++j;
            }
            
            //while (i + 1 < nums.size() && nums[i + 1] == nums[i]) ++i;
        }
        
        return res;
    }
        
};

/*
这里使用递归的思路：

1. k-sum问题可以转化为(k-1)-sum问题：对于数组中每个数A[i]，在A[i+1:n-1]中寻找target-A[i]的(k-1)-sum问题。
2. 直到k=2时，用2sum的双指针扫描来完成。

去重复解的技巧和3Sum问题一模一样。
*/

// DFS思想 + 2Sum
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int>> allSol;
        vector<int> sol;
        sort(num.begin(),num.end());
        kSum(num, 0, num.size()-1, target, 4, sol, allSol);
        return allSol;
    }
    
    void kSum(vector<int> &num, int start, int end, int target, int k, vector<int> &sol, vector<vector<int>> &allSol) {
        if(k<=0) return;
        if(k==1) {
            for(int i=start; i<=end; i++) {
                if(num[i]==target) {
                    sol.push_back(target);
                    allSol.push_back(sol);
                    sol.pop_back();
                    return;
                }
            }
        } 
        
        if(k==2) {
            twoSum(num, start, end, target, sol, allSol);
            return;
        }
    
        for(int i=start; i<=end-k+1; i++) {
            if(i>start && num[i]==num[i-1]) continue;

            sol.push_back(num[i]);
            kSum(num, i+1, end, target-num[i], k-1, sol, allSol);
            sol.pop_back();
        }
    }
    
    void twoSum(vector<int> &num, int start, int end, int target, vector<int> &sol, vector<vector<int>> &allSol) {
        while(start<end) {
            int sum = num[start]+num[end];
            if(sum==target) {
                sol.push_back(num[start]);
                sol.push_back(num[end]);
                allSol.push_back(sol);
                sol.pop_back();
                sol.pop_back();

                start++;
                end--;
                while(num[start]==num[start-1]) start++;
                while(num[end]==num[end+1]) end--;
            }
            else if(sum<target)
                start++;
            else
                end--;
        }
    }
};