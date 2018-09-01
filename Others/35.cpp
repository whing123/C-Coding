/*
聚力与攻击
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	int hp, normal, buffer;

	cin >> hp >> normal >> buffer;

	vector<int> dp(hp + 1, 0);

	for (int i = 1; i <= hp; i++) {
		if (i - normal >= 0 && i - buffer >= 0)
			dp[i] = min(dp[i - normal] + 1, dp[i - buffer] + 2);
		else if (i - normal >= 0)
			dp[i] = dp[i - normal] + 1;
		else if (i - buffer >= 0)
			dp[i] = dp[i - buffer] + 2;
		else
			dp[i] = 1;
	}
	cout << dp[hp] << endl;

	return 0;
}