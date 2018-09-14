/* *题目：
 *  393
 *  UTF-8 Validation
 */

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        return check(data, data.size());
    }
    
    bool check(vector<int>& data, int N) {
        for (int i = 0; i < N;) {
            int start = i;
            
            if ((data[start] >> 7) == 0) {
                i++;
                continue;
            }

            if ((data[start] >> 5) == 6) {
                if (start + 1 < N) {
                    if (data[start + 1] >> 6 == 2) {
                        i += 2;
                        continue;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }

            }

            if ((data[start] >> 4) == 14) {
                if (start + 2 < N)
                {
                    if (data[start + 1] >> 6 == 2 && data[start + 2] >> 6 == 2) {
                        i += 3;
                        continue;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }

            }

            if ((data[start] >> 3) == 30) {
                if (start + 3 < N) {
                    if (data[start + 1] >> 6 == 2 && data[start + 2] >> 6 == 2 && data[start + 3] >> 6 == 2) {
                        i += 4;
                        continue;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }

            return false;
        }

        return true;
    }
};