/*
 96
 最长公共连续子串
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string word1, word2;
	getline(cin, word1);
    getline(cin, word2);

	vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));
	int res = 0;
	for (int i = 1; i <= word1.length(); i++) {
		for (int j = 1; j <= word2.length(); j++) {

			if (word1[i - 1] == word2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;

				res = max(res, dp[i][j]);
			}
			else {
				dp[i][j] = 0;
			}
		}
	}

	cout << res << endl;

	return 0;
}