/* *题目：
 *  537
 *  Complex Number Multiplication
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int a1, b1, a2, b2;
        getA_B(a,a1,b1);
        getA_B(b,a2,b2);
        
        int a3, b3;
        a3 = a1 * a2 - b1 * b2;
        b3 = a1 * b2 + a2 * b1;
        string res;
        res += to_string(a3) + "+" + to_string(b3) + "i";
        
        return res;
    }
    
    void getA_B(string t, int &a, int &b){
        int pos1 = t.find('+');
        int pos2 = t.find('i');
        a = stoi(t.substr(0,pos1));
        b = stoi(t.substr(pos1+1, pos2-pos1-1));
    }
};