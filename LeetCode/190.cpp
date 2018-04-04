/* *题目：
 *  190
 *  Reverse Bits
 */

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for(int i  = 0;i < 32;i++){
            if((n >> i) & 0x00000001){
                result |= (0x00000001 << (31 - i));
            }
        }
        return result;
    }
};