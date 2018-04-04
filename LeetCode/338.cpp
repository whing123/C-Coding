/* *题目：
 *  338
 *  Counting Bits
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1,0);
        int i = 1, prei;
        int j;
        int index = 0;
        while(i <= num){
            prei = i;
            if(prei == pow(2,index++)){ //每逢2的指数(记作prei)，包括1，
                                      //接下来包含2幂自身的prei个数的1的个数是之前prei个数其1的个数+1
                j = 0;
                while(i <= num && j < prei){
                    result[i++] = result[j++] + 1;
                }
            }
        }
        return result;
    }
};