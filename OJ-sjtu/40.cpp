/* *题目：
 *  1013
 *  无限背包
 * *思路：
 *  
 * *技法：
 *  
 */

#include <iostream>
#include <vector>
using namespace std;
 
int main()
{
	int V, N;
	vector<int> volume, value;
	int vol, val;
	cin >> V >> N;
	for (int i = 0;i < N;i++) {
		cin >> vol >> val;
		volume.push_back(vol);
		value.push_back(val);
	}
 
	int sumVolume = 0, restVolume = 0, sumValue = 0;
	int maxVol, maxVal;
	int i;
	double maxRate = 0, tmpRate;
	while (sumVolume < V) {
		restVolume = V - sumVolume;
		maxRate = 0;
		for (i = 0; i < N; i++) {
			if (volume[i] <= restVolume) {
				tmpRate = (double)value[i] / volume[i];
				if (tmpRate > maxRate) {
					maxRate = tmpRate;
					maxVol = volume[i];
					maxVal = value[i];
				}
			}
		}
		if (!(maxRate > 0)) {
			break;
		}
		
		for (;sumVolume <= V;) {
			sumVolume += maxVol;
			sumValue += maxVal;
		}
		if (sumVolume > V) {
			sumVolume -= maxVol;
			sumValue -= maxVal;
		}
	}
	cout << sumValue;
	return 0;
}