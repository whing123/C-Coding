/* *题目：
 *  476
 *  Number Complement
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findComplement(int num) {
        vector<int> res;
        
        //存储每一个bit位
        int i;
        for(i = 0;i < 32;i++){
            if(num >> i & 0x00000001){
                res.push_back(1);
            }else{
                res.push_back(0);
            }
        }
        
        //略过前导0
        i = 31;
        while(res[i] == 0){
            i--;
        }
        
        int output = 0;
        for(int j = 0;j <= i;j++){
            if(res[j] == 0){  //反码为1的位置
                output += pow(2,j);
            }
        }
        
        return output;
    }
};