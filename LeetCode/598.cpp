/* *题目：
 *  598
 *  Range Addition II
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0){
            return m * n;
        }
        
        int a, b;
        
        a = b = INT_MAX;
        
        for(int i = 0; i < ops.size(); ++i){
            if(ops[i][0] < a){
                a = ops[i][0];
            }
            if(ops[i][1] < b){
                b = ops[i][1];
            }
        }
        
        return a * b;
    }
};