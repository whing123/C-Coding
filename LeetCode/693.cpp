/* *题目：
 *  693
 *  Binary Number with Alternating Bits
 */


class Solution {
public:
    bool hasAlternatingBits(int n) {
        list<int> tmp;
        
        tmp = Dec2Any(n, 2);
        
        list<int>::iterator it = tmp.begin();
        int prev = *it;
        it++;
        for(; it != tmp.end(); ++it){
            if(*it == prev){ // 相邻一致则退出
                return false;
            }
        
            prev = *it;
        }
        
        return true;
    }
    
    // 10进制转其他进制
    list<int> Dec2Any(int n, int base){
        list<int> val;
        
        int remainer = 0;
        while(n >= base){
            remainer = n % base;
            n /= base;
            
            val.push_front(remainer);
        }
        val.push_front(n);
        
        return val;
    }
};