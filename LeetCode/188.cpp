/* *题目：
 *  6
 *  ZigZag Conversion
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)
            return s;
        string *p = new string[numRows];
        int size = s.size();
        int i = 0;
        while(i < size){
            for(int j = 0;j < numRows && i < size;j++){
                p[j].push_back(s[i++]);
            }
            
            for(int j = numRows - 2;j > 0 && i < size;j--){
                p[j].push_back(s[i++]);
            }
        }
        
        string newS;
        
        for(int i = 0;i < numRows;i++){
            newS.append(p[i]);
        }
        delete [] p;
        
        return newS;
    }
};