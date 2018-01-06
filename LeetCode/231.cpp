/* *题目：
 *  547
 *  Friend Circles
 * *思路：
 *  
 */

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        vector<int> visited(M.size(), 0); // visited[i] means if ith person is visited in this algorithm
        
        int count = 0;
        for(int i = 0; i < M.size(); ++i){
            if(visited[i] == 0){ 
                dfs(M, visited, i);
                count++;
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<int>>& M, vector<int>& v, int i){
        for(int j = 0; j < M.size(); ++j){
            if(M[i][j] == 1 && v[j] == 0){ // We found an unvisited person in the current friend cycle 
                v[j] = 1;
                dfs(M, v, j); // Start DFS on this new found person
            }
        }
    }
};