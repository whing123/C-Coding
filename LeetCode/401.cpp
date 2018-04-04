/* *题目：
 *  401
 *  Binary Watch
 * *思路：
 *  
 * *技法：
 *  
 */

static const int hourSize = 4;
static const int minuteSize = 6;
static constexpr int hours[4] = { 1,2,4,8 };
static constexpr int minutes[6] = { 1,2,4,8,16,32 };

class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> times, hour, minute;
		for (int i = 0; i <= min(num, 3); i++) {
		    if(num - i > 5)
		        continue;
			hour = hourStr(i);
			minute = minuteStr(num-i);
			for (int j = 0; j < hour.size(); j++) {
				for (int k = 0; k < minute.size(); k++) {
					times.push_back(hour[j] + minute[k]);
				}
			}
		}
		return times;
	}
	
	vector<string> hourStr(int n) {
		vector<string> hourV;
		getHour(0, n, hourV);
		return hourV;
	}
	
	void getHour(int start, int n, vector<string> &hour) {
		static int sum = 0;
		if (n == 0) {
			if (sum < 12) {
				string tmpStr = to_string(sum) + ":";
				//tmpStr.push_back(':');
				hour.push_back(tmpStr);
			}
			return;
		}
		for (int i = start; i < hourSize - n + 1; i++) {
			sum += hours[i];
			getHour(i + 1, n - 1, hour);
			sum -= hours[i];
		}
	}
	
	vector<string> minuteStr(int n) {
		vector<string> minuteV;
		getMinute(0, n, minuteV);
		return minuteV;
	}

	void getMinute(int start, int n, vector<string> &minute) {
		static int sum = 0;
		if (n == 0) {
			if (sum < 60) {
				if (sum < 10) {
					string tmpStr = "0" + to_string(sum);
					//tmpStr.insert(0, "0");
					minute.push_back(tmpStr);
				}
				else {
					minute.push_back(to_string(sum));
				}
			}
			return;
		}
		for (int i = start; i < minuteSize - n + 1; i++) {
			sum += minutes[i];
			getMinute(i + 1, n - 1, minute);
			sum -= minutes[i];
		}
	}

	int min(int n, int m) {
		return n > m ? m : n;
	}
};