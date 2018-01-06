/* *题目：
 *  171
 *  Excel Sheet Column Number
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int titleToNumber(string s) {
        int size = s.size();
        int sum = 0;
        for(int i = 0;i < size;i++){
            sum += (s[size - 1 - i] - 'A' + 1) * pow_26(i);
        }
        return sum;
    }
    
    int pow_26(int n){
        int pow = 1;
        for(int i = 0;i < n;i++){
            pow *= 26;
        }
        return pow;
    }
}