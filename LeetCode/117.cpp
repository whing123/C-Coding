/* *题目：
 *  67
 *  Add Binary
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int sizeA = a.size();
        int sizeB = b.size();
        int i, j;
        int carry;
        int tmp;
        
        i = sizeA - 1;
        j = sizeB - 1;
        carry = 0;
        while(i >= 0 || j >= 0){
            if(i >= 0 && j >= 0){
                tmp = carry + (a[i--]-'0') + (b[j--]-'0');
            }else if(i >= 0){
                tmp = carry + (a[i--]-'0');
            }else if(j >= 0){
                tmp = carry + (b[j--]-'0');
            }
            carry = tmp / 2;
            result.insert(result.begin(),'0' + tmp % 2);
        }
        if(carry){
            result.insert(result.begin(),'1');
        }
        return result;
    }
};