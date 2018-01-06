/* *题目：
 *  38
 *  Count and Say
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        else
            return trans(countAndSay(n-1));
    }
    
    string trans(string a){
        string re = "";
        int i, j;
        
        i = 0;
        while(i < a.length()){
            j = 0;
            while(i+1 < a.length() && a[i] == a[i+1]){
                j++;
                i++;
            }
            char c[100];
            string tmp = "";
            sprintf(c, "%d" ,j+1);
            tmp.assign(c);
            re += tmp;
            re.append(1, a[i]);
            i++;
        }
        return re;
    }
};