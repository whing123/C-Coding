/* *题目：
 *  415
 *  Add Strings
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry, sum;
        string sumTwo;
        int size1 = num1.size(), size2 = num2.size();
        int minSize = size1 > size2 ? size2 : size1;
        int i = 1;
        carry = 0;
        while(i <= minSize){
            sum = (num1[size1-i] - '0') + (num2[size2-i] - '0') + carry;
            carry = sum / 10;
            sum %= 10;
            sumTwo.insert(sumTwo.begin(),sum + '0');
            i++;
        }
        if(minSize == size1){
            while(i <= size2){
                sum = (num2[size2-i] - '0') + carry;
                carry = sum / 10;
                sum %= 10;
                sumTwo.insert(sumTwo.begin(),sum + '0');
                i++;
            }
        }else{
            while(i <= size1){
                sum = (num1[size1-i] - '0') + carry;
                carry = sum / 10;
                sum %= 10;
                sumTwo.insert(sumTwo.begin(),sum + '0');
                i++;
            } 
        }
        if(carry == 1){
            sumTwo.insert(sumTwo.begin(),carry + '0');
        }
        return sumTwo;
    }
};