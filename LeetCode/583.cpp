/* *题目：
 *  583
 *  Delete Operation for Two Strings
 */

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        for (int i = 0; i <= word1.length(); i++) {
            for (int j = 0; j <= word2.length(); j++) {
            	// i == 0 || j == 0: dp(i, j) = 0;
                if (i == 0 || j == 0) {
                    dp[i][j] = 0;
                } else {
                	// word2[i] == word2[j]: dp(i, j) = dp(i - 1, j - 1) + 1;
                    if (word1[i-1] == word2[j-1]) {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                    }
                    // word1[i] != word2[j]: dp(i, j) = max(dp(i - 1, j), dp(i, j - 1))
                    else {
                        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                    }
                }
            }
        }
        
        return word1.length() + word2.length() - dp[word1.length()][word2.length()] * 2;
    }
};