/* *题目：
 *  697
 *  Degree of an Array
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int size = nums.size();
        
        // count
        map<int,int> count;
        for(int i = 0; i < size; ++i){
            count[nums[i]]++;
        }
        
        // find max count
        int maxCnt = 0;
        map<int,int>::iterator it;
        for(it = count.begin(); it!=count.end(); it++){
            if(it->second > maxCnt){
                maxCnt = it->second;
            }
        }
        
        // find who has max count
        vector<int> who;
        for(it = count.begin(); it!=count.end(); it++){
            if(it->second == maxCnt){
                who.push_back(it->first);
            }
        }
        
        // find min length
        int minLen = size;
        int a, b;
        for(int i = 0; i < who.size(); ++i){
            findFirstAndLast(nums, who[i], a, b);
            int tmp = b-a+1;
            if(tmp < minLen){
                minLen = tmp;
            }
        }
        
        return minLen;
    }
    
    // find first and last index
    void findFirstAndLast(vector<int>& nums, int num, int& fir, int& last){
        bool flag = true;
        
        for(int i = 0; i < nums.size(); ++i){
            if(num == nums[i]){
                if(flag){ // first in
                    flag = false;
                    fir = i;
                    last = i;
                }else{
                    last = i;
                }
            }
        }
    }
};