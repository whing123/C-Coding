/* *题目：
 *  把数组排成最小的数
 */

class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), cmp);
        string res;
        for(int i = 0; i < numbers.size(); ++i){
            res += to_string(numbers[i]);
        }
        
        return res;
    }
    
    static bool cmp(const int& a, const int& b){
        string stra = to_string(a);
        string strb = to_string(b);
        return stra + strb < strb + stra;
    }
};