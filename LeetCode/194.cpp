/* *题目：
 *  690
 *  Employee Importance
 * *思路：
 *  
 * *技法：
 *  递归搜索，map使用
 */


/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int size = employees.size();
        int sum = 0;
        
        map<int, Employee*> map_; // id映射
        map<int, bool> map_visit; // 是否seach过
        for(int i = 0; i < size; ++i){
            map_[employees[i]->id] = employees[i];
            map_visit[employees[i]->id] = false;
        }
        
        search(map_, map_visit, id, sum);
        
        return sum;
    }
    
    void search(map<int, Employee*>& map_, map<int, bool>& map_visit, int id, int& sum){
        map<int, bool>::iterator it1 = map_visit.find(id);
        if(it1->second == true){
            return;
        }
        it1->second = true; // 当前已search
        
        map<int, Employee*>::iterator it = map_.find(id);
        sum += it->second->importance;
        
        // 对每个下属search
        int size = it->second->subordinates.size();
        for(int i = 0; i < size; ++i){
            search(map_, map_visit, it->second->subordinates[i], sum);
        }
    } 
};