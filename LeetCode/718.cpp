/* *题目：
 *  718
 *  Maximum Length of Repeated Subarray
 */

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        int res = 0;
        for (int i = 1; i <= A.size(); i++) {
            for (int j = 1; j <= B.size(); j++) {

                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;

                    res = max(res, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        
        return res;
    }
};