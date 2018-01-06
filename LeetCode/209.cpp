/* *题目：
 *  686
 *  Repeated String Match
 * *思路：
 *  
 */

class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string tmp;
        
        int cnt = B.length() / A.length(); // 先在长度上满足要求
        
        for(int i = 0; i < cnt; ++i){
            tmp += A;
        }
        
        if(tmp.find(B) != -1){ // 初次试水
            return cnt;
        }
        
        tmp += A;
        if(tmp.find(B) != -1){ // 再次试水
            return cnt+1;
        }
        
        tmp += A;
        if(tmp.find(B) != -1){ // 接着试水
            return cnt+2;
        }
        
        return -1;
    }
};