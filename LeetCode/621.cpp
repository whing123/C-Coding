/* *题目：
 *  621
 *  Task Scheduler
 */

/*
A, A, A, B, B, B, C, C, C     n = 3
A -> B -> C -> idle ->  A -> B -> C -> idle -> A -> B -> C
|------------------|   |-------------------|  |-----------|
        n + 1                  n + 1          numMaxElements
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        int maxC = 0;
        for(int i = 0; i < tasks.size(); i++){
            mp[tasks[i]]++;
            maxC = max(maxC, mp[tasks[i]]);
        }
        
        // num of eles with max Count
        int cnt = 0;
        for(auto var : mp){
            if(var.second == maxC) {
                cnt++;
            }
        }
        
        return max((n+1)*(maxC-1)+cnt, (int)tasks.size());
    }
};