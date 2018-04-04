/* *题目：
 *  541
 *  Reverse String II
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        int size = s.size();
        
        for(int i = 0;i < size;i += 2*k){
            int left = size-i; //当前剩余元素数
            if(left < k){  //不足k
                reverse(s,i,left);
                break;
            }else if(k <= left && left < 2*k){  //不足2k
                reverse(s,i,k);
                break;
            }
            reverse(s,i,k);  //正常
        }
        
        return s;
    }
    
    //反转s,起始位置start,反转元素数k
    void reverse(string &s, int start, int k){
        int end = start + k - 1;
        
        for(int i = 0;i < k/2;i++){
            char tmp = s[start+i];
            s[start+i] = s[end-i];
            s[end-i] = tmp;
        }
    }
};