/* *题目：
 *  207
 *  Course Schedule
 */

// better
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
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
        
        int cnt = 0;
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            cnt++;
            
            for (int i = 0; i < data[u].size(); i++) {
                if (--indegree[data[u][i]] == 0) {
                    Q.push(data[u][i]);
                }
            }
        }
        
        return cnt == numCourses;
    }
};


class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<bool> visited(numCourses, false);
        vector<set<int>> data(numCourses, set<int>());
        
        // keep 所有点的入度
        for (int i = 0; i < prerequisites.size(); i++) {
            data[prerequisites[i].first].insert(prerequisites[i].second);
        }
        
        func(data, visited, numCourses);
        
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                return false;
            }
        }
        
        return true;
    }
    
    void func(vector<set<int>>& data, vector<bool>& visited, int& numCourses) {
        for (int i = 0; i < numCourses;) {
            if (!visited[i] && data[i].size() == 0) {
                visited[i] = true;
                
                // delete 入度 in its neighbors
                for (int j = 0; j < data.size(); j++) {
                    if (!visited[j] && data[j].find(i) != data[j].end()) {
                        data[j].erase(i);
                    }
                }
                
                i = 0;
            } else {
                i++;
            }
        }
    }
};