/*
 97
 滑动窗口最大值
*/

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if (size < 1 || num.size() < size) {
            return res;
        }
        
        deque<int> qmax;
        for (int i = 0; i < num.size(); ++i) {
            while (!qmax.empty() && num[qmax.back()] <= num[i]) {
                qmax.pop_back();
            }
            
            qmax.push_back(i);
            
            if (qmax.front() == i - size) {
                qmax.pop_front();
            }
            
            if (i >= size - 1) {
                res.push_back(num[qmax.front()]);
            }
        }
        
        return res;
    }
};