/* *题目：
 *  数据流中的中位数
 * *思路：
 *  
 */

class Solution {
public:
    void Insert(int num) {
        data.push_back(num);
        std::sort(data.begin(), data.end());
    }
 
    double GetMedian() {
        unsigned int size = data.size();
        if (size & 1) { // 奇数
            return data[size >> 1];
        } else { // 偶数
            int left = data[(size >> 1) - 1];
            int right = data[size >> 1];
            return (static_cast<double>(left) + right) / 2;
        }
    }
private:
    vector<int> data;
};