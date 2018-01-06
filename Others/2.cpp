/* *题目：
 *  数组找第二大
 * *思路：
 *  冒泡排序找到第二个即可
 * *技法：
 *  
 */

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int num;
	vector<int> list;
	for (int i = 0; i < n; i++) {
		cin >> num;
		list.push_back(num);
	}

	int cnt = 0;
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j + 1 < n - i; j++) {
			if (list[j+1] < list[j])
			{
				int temp = list[j+1];
				list[j+1] = list[j];
				list[j] = temp;
			}
		}

		cnt++;
		if (cnt == 2) {
			cout << list[n - 2]<<endl;
			break;
		}

	}
    return 0;
}