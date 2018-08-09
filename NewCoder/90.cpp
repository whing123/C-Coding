/*
 90
 字符迷阵中寻找特定的单词
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int h = 0; h < N; h++) {
		int m, n;
		cin >> m >> n;
		vector<vector<char>> arr(m, vector<char>(n));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		string word;
		cin >> word;

		int sum = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				// right
				if (arr[i][j] == word[0]) {
					int k = 0;
					while (j+k < n && k < word.length() && arr[i][j+k] == word[k]) {
						k++;
					}

					if (k == word.length()) {
						sum++;
					}
				}

				// down
				if (arr[i][j] == word[0]) {
					int k = 0;
					while (i+k < m && k < word.length() && arr[i+k][j] == word[k]) {
						k++;
					}

					if (k == word.length()) {
						sum++;
					}
				}

				// down-right
				if (arr[i][j] == word[0]) {
					int k = 0;
					while (i+k < m && j+k < n && k < word.length() && arr[i+k][j+k] == word[k]) {
						k++;
					}

					if (k == word.length()) {
						sum++;
					}
				}
			}
		}

		cout << sum << endl;
	}

	return 0;
}