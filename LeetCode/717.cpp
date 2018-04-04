/* *题目：
 *  717
 *  1-bit and 2-bit Characters
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int size = bits.size();
        
        char curflag;
        for(int i = 0; i < size;){
            if(bits[i] == 0){
                curflag = 1; // one-bit
                ++i;
            }else{
                curflag = 2; // two-bit
                i += 2;
            }
        }
        
        return curflag == 1 ? true : false;
    }
};