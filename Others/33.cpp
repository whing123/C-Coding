/*
棋盘倒立
*/

#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main() {
	int m, n;
	cin >> m >> n;
	vector<string> data(m);
	for (int i = 0; i < m; i++) {
		cin >> data[i];
	}
	
	for (int j = 0; j < n; j++) {
		int x = -2, lay = x + 1;
		for (int i = m - 1; i >= 0; i--) {
			if (data[i][j] == 'x') {
				x = i;
				lay = x - 1;
			}
			else if (data[i][j] == 'o') {
				if (x < 0) {
					data[i][j] = '.';
				}
				else {
					data[i][j] = '.';
					data[lay][j] = 'o';
					lay--;
				}
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << data[i][j];
		}
		cout << endl;
	}
    
	return 0;
}