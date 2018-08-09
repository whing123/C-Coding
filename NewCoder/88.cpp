/*
  88 
  钟表调时间
  修改最少的数字情况下，字典序最小的真实存在的时间
  xx:xx:xx
  01 34 67
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;
		
		if (tmp[0] > '2') {
			tmp[0] = '0';
		}

		if (tmp[0] == '2' && tmp[1] > '3') {
			tmp[0] = '0';
		}

		if (tmp[3] > '5') {
			tmp[3] = '0';
		}

		if (tmp[6] > '5') {
			tmp[6] = '0';
		}

		cout << tmp << endl;
	}
    
	return 0;
}