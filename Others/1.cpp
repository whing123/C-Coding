/* *题目：
 *  线段重合问题，最少需要多少次将线段全部清除，选一个点会将涵盖该点的所有线段清除
 *  输入第一行线段数，下面两行：起点行，终点行
 * *思路：
 *  将所有线段的点排序后放在坐标轴上构成许多小线段，在这些小线段中找出涵盖数最多的，然后把涵盖线段去除，再重复上述，直到没有线段
 * *技法：
 *  
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line {
	int start;
	int end;
	line(int s, int e) { start = s; end = e; }
	line(){}
};

// a是否涵盖在b中
bool isIn(const line&a, const line&b) {
	return b.start <= a.start && a.end<=b.end;
}

int main() {
	int N;
	cin >> N;
	int s, e;
	vector<int> starts;
	vector<int> ends;
	
 	for (int i = 0; i < N; ++i) {
		cin >> s;
		starts.push_back(s);
	}
	for (int i = 0; i < N; ++i) {
		cin >> e;
		ends.push_back(e);
	}

	vector<line> lines;
	for (int i = 0; i < N; ++i) {
		int st = min(starts[i], ends[i]);
		int ed = max(starts[i], ends[i]);
		line tmp(st, ed);
		lines.push_back(tmp);
	}

	int res = 0;
	while (!lines.empty()) {
		vector<int> all;
		for (int i = 0; i < lines.size(); i++) {
			all.push_back(lines[i].start);
			all.push_back(lines[i].end);
		}

		sort(all.begin(), all.end());

		int maxC = 0;
		line maxL;  // 存储涵盖数最多的小线段
		for (int i = 1; i < all.size(); i++) {
			line tmp(all[i - 1], all[i]);
			int count = 0;
			for (int j = 0; j < lines.size(); j++) {
				if (isIn(tmp, lines[j])) {
					count++;
				}
			}

			if (count > maxC) {
				maxC = count;
				maxL = tmp;
			}
		}

		vector<line> newLines; // 存储不包含此小线段的线段，作为下一次的线段集
		for (int j = 0; j < lines.size(); j++) {
			if (!isIn(maxL, lines[j])) {
				newLines.push_back(lines[j]);
			}
		}

		lines = newLines;
		res++;
	}


	cout << res << endl;

	return 0;
}