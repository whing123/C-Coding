/* *题目：
 *  220
 *  Contains Duplicate III
 * *思路：
 *  
 */

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> window; // set is ordered automatically
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k && i - k - 1 < nums.size()) // keep the set contains nums i j at most k
                window.erase(nums[i - k - 1]);
            
            // |x - nums[i]| <= t  ==> -t <= x - nums[i] <= t;
            auto it = window.lower_bound((long long)nums[i] - t); // x-nums[i] >= -t ==> x >= nums[i]-t
            
            // x - nums[i] <= t ==> |x - nums[i]| <= t  
            if (it != window.cend() && *it - nums[i] <= t)
                return true;

            window.insert(nums[i]);
        }
        return false;
    }
};

// 超时
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for(int i = 0; i < nums.size(); i++){
            for(int j = max(i-k, 0); j <= min(i+k, (int)nums.size()-1); j++){
                if(j == i){
                    continue;
                }else{
                    long long diff = llabs((long long)nums[i]-(long long)nums[j]);
                    if(diff <= t){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
};