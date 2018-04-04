/* *题目：
 *  599
 *  Minimum Index Sum of Two Lists
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> list_2;
        unordered_map<string, int>::iterator it;
        
        for(int i = 0; i < list2.size(); ++i){
            list_2[list2[i]] = i;
        }
        
        vector<string> new_list;
        vector<int> index_sum;
        int min_ = INT_MAX;
        for(int i = 0; i < list1.size(); ++i){
            if((it = list_2.find(list1[i])) != list_2.end()){
                int tmp = i + it->second;
                index_sum.push_back(tmp);
                new_list.push_back(list1[i]);
                if(tmp < min_){
                    min_ = tmp;
                }
            }
        }
        
        vector<string> res;
        for(int i = 0; i < new_list.size(); ++i){
            if(index_sum[i] == min_){
                res.push_back(new_list[i]);
            }
        }
        
        return res;
    }
};