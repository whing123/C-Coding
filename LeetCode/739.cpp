/* *题目：
 *  739
 *  Daily Temperatures
 * *思路：
 *  
 */

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
     
        for(int i = 0; i < temperatures.size()-1; ++i){
            if(i > 0 && temperatures[i] == temperatures[i-1]){ // if T[i] = T[i-1], days[i] = days[i-1] - 1, but still >= 0
                res[i] = max(0, res[i-1]-1);
                continue;
            }
            
            // find from i+1
            for(int j = i+1; j < temperatures.size(); ++j){
                if(temperatures[j] > temperatures[i]){
                    res[i] = j-i;
                    break;
                }
            }
        }
        
        return res;
    }
};


// for each day from end to start, record the next day of temperature t for all t in [30, 100]
// for each day from n-1 to 0; for all temperature higher than temp[i], find the earliest
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int n = temps.size();
        vector<int> waits(n, 0);
        vector<int> next(101, INT_MAX); // next day with with certain temperature.
        for (int i = n - 1; i >= 0; i--) {
            int earliest = INT_MAX;
            for (int t = temps[i] + 1; t <= 100; t++) {
                earliest = min(earliest, next[t]);
            }
            if (earliest != INT_MAX) waits[i] = earliest - i;
            next[temps[i]] = i;
        }
        return waits;
    }
};