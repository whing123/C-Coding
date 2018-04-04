/* *题目：
 *  461
 *  Hamming Distance
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int hammingDistance(int x, int y) {
        int reuslt = x ^ y;
        int cnt = 0;
        
        for(int i = 0; i < 32; i++){
            if((reuslt>>i) & 0x01){
                cnt++;
            }
        }
        return cnt;
    }
};