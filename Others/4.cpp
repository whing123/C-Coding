#include <iostream>
#include <vector>

using namespace std;

int change(int left, int right) {
	if (left == right) {
		return 0;
	}
	
	return 1;
	
	// return left == right ? 0 : 1;
}

vector<int> cellComplete(int *states, int days) {
	int prev;
	for (int i = 0; i < days; ++i) {
		prev = 0;
		for (int j = 0; j < 7; ++j) {
			int tmp = states[j];
			states[j] = change(prev, states[j + 1]);
			prev = tmp;
		}
		states[7] = change(prev, 0);
	}

	vector<int> res;
	for (int i = 0; i < 8; ++i) {
		res.push_back(states[i]);
	}
	
	return res;
}

void disp(const vector<int> & v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
}

int main()
{
	int states[] = { 1,1,1,0,1,1,1,1 };//{1,0,0,0,0,1,0,0};
	vector<int> tmp = cellComplete(states, 2);
	disp(tmp);
	return 0;
}