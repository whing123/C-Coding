/* *题目：
 *  347
 *  Top K Frequent Elements
 * *思路：
 *  
 * *技法：
 *  
 */

struct less_{
    bool operator()(pair<int,int> &a, pair<int,int> &b) {
        return a.second > b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size =  nums.size();
        
        //统计次数
        unordered_map<int,int> tab;
        for(int i = 0;i < size;i++){
            tab[nums[i]]++;
        }
        
        //置入vector
        size = tab.size();
        unordered_map<int,int>::iterator it;
        vector<pair<int,int>> pairs;
        for(it = tab.begin();it != tab.end();it++){
            pairs.push_back(pair<int,int>(it->first,it->second));
        }
        
        //按次数排序
        sort(pairs.begin(),pairs.end(),less_());
        
        //找到前k个
        vector<int> res;
        for(int i = 0;i < k;i++){
            res.push_back(pairs[i].first);
        }
        
        return res;
    }
};