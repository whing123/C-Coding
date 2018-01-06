/* *题目：
 *  628
 *  Maximum Product of Three Numbers
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        if(nums.size() == 3){
            return nums[0] * nums[1] * nums[2];
        }
        
        vector<int> pos, neg;
        
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] < 0){
                neg.push_back(nums[i]);
            }else{
                pos.push_back(nums[i]);
            }
        }
        
        sort(pos.begin(), pos.end(), myfunction);
        sort(neg.begin(), neg.end());
        
        if(pos.size() == 0){
            return neg[neg.size()-1] * neg[neg.size()-2] * neg[neg.size()-3];
        }else if(pos.size() == 1){
            return neg[0] * neg[1] * pos[0];
        }else if(neg.size() < 2){
            return pos[0] * pos[1] * pos[2];
        }else{
            int a = neg[0] * neg[1] * pos[0];
            int b = (pos.size() > 2)? pos[0] * pos[1] * pos[2] : -1;
            return a > b ? a : b;
        }
        
        return 0;
    }
    
    static bool myfunction (int i,int j) { return (i > j); }
};