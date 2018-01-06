/* *题目：
 *  405
 *  Convert a Number to Hexadecimal
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string toHex(int num) {
        string res;
        if(num >= 0){
            return posIntToHex(num);
        }else{
            int i = 0;
            char tmp= 0;
            while(i < 8){
                tmp = num >> (4 * i);
                tmp &= 0x0f;
                res.insert(0,getHexCh(tmp));
                i++;
            }
        }
        return res;
    }
    
    string posIntToHex(int num){
        string res;
        while(num > 15){
            res.insert(0,getHexCh(num % 16));
            num /= 16;
        }
        res.insert(0,getHexCh(num));
        return res;
    }
    string getHexCh(int n){
        static string HexCh[16] = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
        return HexCh[n];
    }
    
};