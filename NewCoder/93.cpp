/*
  93
  16进制转10进制
*/

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	string hexstr;
	while (cin >> hexstr) {
		hexstr = hexstr.substr(2);
		reverse(hexstr.begin(), hexstr.end());

		int decVal = 0;
		for (int i = 0; i < hexstr.length(); i++) {
			int tmp = 0;
			if ('A' <= hexstr[i] && hexstr[i] <= 'F') {
				tmp = hexstr[i] - 'A' + 10;
			}else if ('a' <= hexstr[i] && hexstr[i] <= 'f') {
				tmp = hexstr[i] - 'a' + 10;
			}else {
				tmp += hexstr[i] - '0';
			}
	
			decVal += tmp * (int)pow(16, i);
		}
		cout << decVal << endl;
	}

	return 0;
}