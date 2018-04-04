/* *题目：
 *  594
 *  Longest Harmonious Subsequence
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findLHS(vector<int>& nums) {
        int size = nums.size();
        if(size == 0){
            return 0;
        }
        
        map<int,int> tab;
        map<int,int>::iterator it, it1;
        
        for(int i = 0; i < size; ++i){
            tab[nums[i]]++;
        }
        
        int len = 0;
        for(it = tab.begin(); it != tab.end(); ++it){
            it1 = it;
            it1++;
            if(it1 != tab.end() && abs(it->first - it1->first) == 1){
                int tmp = it->second + it1->second;
                if(len < tmp){
                    len = tmp;
                }
            }
        }
        
        
        return len;
    }
};

class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        
        sort(nums.begin(),nums.end());
        
        int len = 0;
        int len1, len2;
        len1 = 1;
        len2 = 0;
        
        int start = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] == start){
                len1++;
            }else if(nums[i] == start + 1){
                len2++;
            }else{                    //出现第三大时，处理
                if(len2 > 0){         //有第二大时，结算
                    int tmp = len1 + len2;
                    if(len < tmp){
                        len = tmp;
                    }
                    start++;          //第一大换到第二大
                    len1 = len2;
                    len2 = 0;
                    i--;
                }else{                //没有第二大，则直接跳到当前
                    start = nums[i];
                    len1 = 1;
                    len2 = 0;
                }
            }
        }
        
        if(len2 > 0){                 //最后一波
            if(len < len1+len2){
                len = len1 + len2;
            }
        }
        
        return len;
    }
};