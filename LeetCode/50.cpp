/* *题目：
 *  13
 *  Roman to Integer
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int romanToInt(string s) {
        int val = 0, tmp;
        int i = 0, j;
        int len = s.length();
        
        while(i < len)
        {
            j = 0;
            while(len - i - j)
            {
                if(tmp = match(s.substr(i,len-i-j)))
                {
                    val += tmp;
                    i += len-i-j;
                    break;
                }
                j++;
            }
        }
        return val;
    }
    
    int match(string str){
        static string s_roman[] = {  
             "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",  
             "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",  
             "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",  
             "M", "MM", "MMM"};
        static int i_roman[] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9,
            10, 20, 30, 40, 50, 60, 70, 80, 90,
            100, 200, 300, 400, 500, 600, 700, 800, 900,
            1000, 2000, 3000};
        
        int i;
        
        for(i = 0;i < 30;i++)
        {
            if(str == s_roman[i])
            {
                return i_roman[i];
            }    
        }
        
        return 0;
    }
};