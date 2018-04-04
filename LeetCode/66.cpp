/* *题目：
 *  66
 *  Plus One
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int d = 1;
        for(int i = digits.size() - 1;i >= 0;)
        {
            digits[i] += d;
            if(digits[i] < 10)
            {    
                return digits;
            }
            
            digits[i] %= 10;
            i--;
        }
        
        digits.insert(digits.begin(),1);
        return digits;
    }
};