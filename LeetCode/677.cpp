/* *题目：
 *  677
 *  Map Sum Pairs
 * *思路：
 *  
 */

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        map<string, int>::iterator it;
        if((it = data.find(key)) != data.end()){ // override
            it->second = val;
        }else{
            data.insert(pair<string, int>(key, val));
        }
    }
    
    int sum(string prefix) {
        int sum = 0;
        map<string, int>::iterator it;
        for(it = data.begin(); it != data.end(); ++it){
            if(it->first.find(prefix) == 0){ // starts with prefix
                sum += it->second;
            }
        }
        
        return sum;
    }
    
public:
    map<string, int> data;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */