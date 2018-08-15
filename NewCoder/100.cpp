/*
 100
 手串颜色
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, c;
	cin >> n >> m >> c;

	vector<vector<int>> color_pos(c, vector<int>());
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		for (int j = 0; j < k; j++) {
			int pos;
			cin >> pos;
			color_pos[pos - 1].push_back(i);
		}
	}

	int res = 0;
	for (int i = 0; i < c; i++) {
		if (color_pos[i].size() == 1) {
			if (n == 1 && m == 1) {
				res++;
			}
			continue;
		}

		if (color_pos[i].size() > 1) {
			color_pos[i].push_back(color_pos[i][0] + n);
		}
		for (int j = 1; j < color_pos[i].size(); j++) {
			if (color_pos[i][j] - color_pos[i][j - 1] < m || color_pos[i][j - 1] + n - color_pos[i][j] < m) {
				res++;
				break;
			}
		}
	}

	cout << res << endl;

	return 0;
}