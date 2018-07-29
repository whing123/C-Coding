/* *题目：
 *  560
 *  Subarray Sum Equals K
    prefix sum & map
 */

/*
Brief explaination:
To solve the problem, we want to know how to sum to a particular value and how many times did this value appear.
That is, how to find the value of sum[i, j], the sum from nums[i] to nums[j] , where [i, j] are indexes of the array.
And yet we know that sum[i, j] = sum[0, j] - sum[0, i - 1]. 
Therefore, we can iterate through the original array and accumulatively calculate the prefix sum current, 
in each iteration we check whether we have encountered the value current - k in the past iterations.
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1;
        
        int res = 0;
        int prefixSum = 0;
        for(int num : nums){
            prefixSum += num;
            res += prefixSumCount[prefixSum - k];
            prefixSumCount[prefixSum] += 1;
        }
        
        return res;
    }
};