/*
矩形之和
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	vector<vector<string>> V(M, vector<string>(N));
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			string s;
			cin >> s;
			V[i][j] = s;
		}
	}

	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		bool isInf_g, isInf_l;
		isInf_g = isInf_l = false;
		int sum = 0;
		for (int j = a; j <= c; j++) {
			for (int k = b; k <= d; k++) {
				if (V[j][k] == "+inf") {
					isInf_g = true;
				}else if (V[j][k] == "-inf") {
					isInf_l = true;
				}else {
					sum += stoi(V[j][k]);
				}

				if (isInf_g && isInf_l) {
					break;
				}
			}
		}
		if (isInf_g && isInf_l) {
			cout << "NaN";
		}else if(isInf_g && !isInf_l){
			cout << "+inf";
		}else if (!isInf_g && isInf_l) {
			cout << "-inf";
		}else {
			cout << sum;
		}
		cout << endl;

	}

	return 0;
}