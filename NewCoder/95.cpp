/*
  95
  最大矩形面积
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> height(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}
	
	vector<int> lessFromLeft(n, 0), lessFromRight(n, 0);
	lessFromLeft[0] = -1;
	lessFromRight[n - 1] = n;
	for (int i = 1; i < n; i++) {
		int p = i - 1;

		while (p >= 0 && height[p] >= height[i]) {
			p = lessFromLeft[p];
		}
		lessFromLeft[i] = p;
	}

	for (int i = n - 2; i >= 0; i--) {
		int p = i + 1;

		while (p < n && height[p] >= height[i]) {
			p = lessFromRight[p];
		}
		lessFromRight[i] = p;
	}

	int maxArea = 0;
	for (int i = 0; i < n; i++) {
		maxArea = max(maxArea, height[i] * (lessFromRight[i] - lessFromLeft[i] - 1));
	}

	cout << maxArea << endl;

	return 0;
}