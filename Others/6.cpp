#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct xiong {
	int zhan; // 战斗力
	int ji_e; // 饥饿值
	int num; // 输入编号
	xiong(int s, int e, int n) { zhan = s; ji_e = e; num = n; }
	xiong() {}
};

bool cmp(int a, int b) {
	return a > b;
}

bool cmp2(const xiong& a, const xiong& b) {
	return a.zhan > b.zhan;
}

bool cmp3(const xiong& a, const xiong& b) {
	return a.num < b.num;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int tmp;
	vector<int> tang;
	for (int i = 0; i < m; ++i) {
		cin >> tmp;
		tang.push_back(tmp);
	}

	sort(tang.begin(), tang.end(),cmp); // 糖从大到小
	
	int tmp2;
	vector<xiong> beer;
	for (int i = 0; i < n; ++i) {
		cin >> tmp >> tmp2;
		xiong x(tmp,tmp2,i);
		beer.push_back(x);
	}

	sort(beer.begin(), beer.end(), cmp2); // 熊按战斗力排

	for (int i = 0; i < beer.size(); i++) {
		for (int j = 0; j < tang.size(); j++) {
			if (beer[i].ji_e >= tang[j]) { // 还可以吃，若为0应退出
				beer[i].ji_e -= tang[j];
				tang[j] = 1000; // 标记为已吃掉
			}
		}
	}

	sort(beer.begin(), beer.end(), cmp3);
	for (int i = 0; i < beer.size(); i++){ //按输入顺序输出
		cout << beer[i].ji_e << endl;
	}

    return 0;
}