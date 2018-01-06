#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct line {
	int start;
	int end;
	line(int s, int e) { start = s; end = e; }
	line() {}
};

// a是否涵盖在b中
bool isIn(const line&a, const line&b) {
	return b.start <= a.start && a.end <= b.end;
}

bool cmp(const line &a, const line & b) {
	return a.start < b.start;
}

int main() {
	int N, k;
	cin >> N >> k;

	int st, ed;
	vector<line> lines; // 输入的温度区间
	for (int i = 0; i < N; ++i) {
		cin >> st >> ed;
		line tmp(st, ed);
		lines.push_back(tmp);
	}

	sort(lines.begin(), lines.end(), cmp);

	vector<int> all; // 温度离散点
	for (int i = 0; i < lines.size(); i++) {
		all.push_back(lines[i].start);
		all.push_back(lines[i].end);
	}

	sort(all.begin(), all.end());

	bool flagl = false;
	line maxL;
	for (int i = 1; i < all.size(); i++) {
		line tmp(all[i - 1], all[i]); // 相邻离散点区间
		int count = 0;
		for (int j = 0; j < lines.size(); j++) {
			if (isIn(tmp, lines[j])) {
				count++;
			}

			if (tmp.end < lines[j].start) {
				break;
			}
		}

		if (count >= k) { // 重合数目首次达到要求
			maxL = tmp;
			st = maxL.start; //找最低
			flagl = true;
			break;
		}
	}

	bool flagr = false;
	line maxR; 
	for (int i = all.size() - 1; i > 0; --i) {
		line tmp(all[i - 1], all[i]);
		int count = 0;
		for (int j = lines.size()-1; j >= 0 ; --j) {
			if (isIn(tmp, lines[j])) {
				count++;
			}
		}

		if (count >= k) { // 重合数目首次达到要求
			maxR = tmp;
			ed = maxR.end; // 找最高
			flagr = true;
			break;
		}
	}

	if (flagl) { //若存在
		cout << st;
	}
	else {
		cout << "error";
	}

	cout << " ";

	if (flagr) { // 若存在
		cout << ed;
	}
	else {
		cout << "error";
	}

	cout << endl;

	return 0;
}