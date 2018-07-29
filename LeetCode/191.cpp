/* *题目：
 *  191
 *  Number of 1 Bits
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
            tmp = n >> (i * 8); // 每隔8位检测1的个数
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

// better
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n)
        {
            n &= n - 1;
            ++ res;
        }
        return res;
    }
};