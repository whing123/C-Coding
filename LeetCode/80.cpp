/* *题目：
 *  191
 *  Number of 1 Bits
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int arr[8] = {1, 2, 4, 8, 16, 32, 64, 128};
        unsigned char tmp;
        //char tmp;
        int i = 0;
        int j;
        int cnt = 0;
        while(i < 4){
            tmp = n >> (i * 8);
            j = 1;
            while(tmp){
                if(tmp >= arr[8-j]){
                    cnt++;
                    tmp -= arr[8-j];
                }
                j++;
            }
            i++;
        }
        return cnt;
    }
};
