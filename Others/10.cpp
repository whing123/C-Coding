/* *题目：
 *  矩阵自上而下的路径和，相邻行不同列
 */

// 矩阵，行数，当前行，列数，上一行的列，目前和，最小和
void helper(vector<vector<int>>& costs, int n, int curr, int k, int last, int &cost, int &minc)
{
    if(n == curr)
    {
        if(minc > cost)
            minc = cost;
        return;
    }
    
    for(int i = 0; i < k; i++)
    {
        if(i == last) continue;
        cost += costs[curr][i];
        helper(costs, n, curr+1, k, i, cost, minc);
        cost -= costs[curr][i];
    }
}


int minCost(vector<vector<int>>& costs)
{
    int cost = 0;
    int n = costs.size();
    int k = costs[0].size();
    int minc = INT_MAX;
    helper(costs, n, 0, k, -1, cost, minc);
    return minc;
}