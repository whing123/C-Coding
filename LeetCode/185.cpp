/* *题目：
 *  223
 *  Rectangle Area
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int areaA, areaB, areaCom;
        areaA = (D-B)*(C-A);
        areaB = (H-F)*(G-E);
        areaCom = lenCom(A,C,E,G)*lenCom(B,D,F,H);
        return areaA+areaB-areaCom;
        
    }
    
    int lenCom(int a, int b, int c, int d){
        if(b <= c || a >= d)
            return 0;
        int min_bd = b < d ? b : d;
        int max_ac = a > c ? a : c;
        return min_bd - max_ac;
    }
};