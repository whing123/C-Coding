/* *题目：
 *  210
 *  Course Schedule II
 */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        vector<vector<int>> data(numCourses); // out degree
        
        for (int i = 0; i < prerequisites.size(); i++) {
            data[prerequisites[i].second].push_back(prerequisites[i].first);
            indegree[prerequisites[i].first]++;
        }
        
        // keep v which indegree == 0
        queue<int> Q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                Q.push(i);
            }
        }
        
        vector<int> res;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            res.push_back(u);
            
            for (int i = 0; i < data[u].size(); i++) {
                if (--indegree[data[u][i]] == 0) {
                    Q.push(data[u][i]);
                }
            }
        }
        
        if (res.size() < numCourses) {
            return vector<int>();
        }
        
        return res;
    }
};