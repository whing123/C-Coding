/* *题目：
 *  506
 *  Relative Ranks
 * *思路：
 *  
 * *技法：
 *  
 */

 struct more_than{
    bool operator()(pair<int,int> &a, pair<int,int> &b){
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int size = nums.size();
        vector<pair<int,int>> hash;
        for(int i = 0;i < size;i++){
            hash.push_back(pair<int,int>(nums[i],i)); //保存分数及位置
        }
        
        sort(hash.begin(),hash.end(),more_than()); //按分数排序
        
        vector<string> res(size,"");
        for(int i = 0;i < min(size,3);i++){ //前三名
            switch(i){
                case 0:
                    res[hash[i].second] = "Gold Medal";
                    break;
                case 1:
                    res[hash[i].second] = "Silver Medal";
                    break;
                case 2:
                    res[hash[i].second] = "Bronze Medal";
            }
        }
        for(int i = 3;i < size;i++){ //第三名后面位次
            res[hash[i].second] = to_string(i+1);
        }
        return res;
    }
};
