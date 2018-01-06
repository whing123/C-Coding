/* *题目：
 *  451
 *  Sort Characters By Frequency
 * *思路：
 *  
 * *技法：
 *  
 */

struct lessThan{
    bool operator()(pair<char,int> a, pair<char,int> b){
        return a.second > b.second;
    }  
};

class Solution {
public:
    string frequencySort(string s) {
        string res;
        int size = s.size();
        
        map<char,int> table;   //收集字母统计次数
        for(int i = 0;i < size;i++){
            table[s[i]]++;
        }
        
        vector<pair<char,int>> sortTable;   //字母与其频次组成一个整体装入 vector
        map<char,int>::iterator it;
        for(it = table.begin();it != table.end();it++){
            sortTable.push_back(pair<char,int>(it->first,it->second));
        }
        
        sort(sortTable.begin(),sortTable.end(),lessThan());  //按次数降序排序
        
        size = sortTable.size();
        for(int i = 0;i < size;i++){
            while(sortTable[i].second--){   //组成新的字符串
                res.push_back(sortTable[i].first);
            }
        }
        
        return res;
    }
};