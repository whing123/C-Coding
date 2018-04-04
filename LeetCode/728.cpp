/* *题目：
 *  728
 *  Self Dividing Numbers
 * *思路：
 *  
 */


class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        
        for(int i = left; i <= right; ++i){  // 遍历
            if(selfDividing(i)){
                res.push_back(i);
            }
        }
        
        return res;
    }
    
    bool selfDividing(int num){
        int tmp = num;
        int res;
        while(tmp > 9){
            res = tmp % 10;  // 取出末位
            if(res == 0){  // 不能为0
                return false;
            } 
            else if(num % res != 0){ // 不能被整除
                return false;          
            }
            
            tmp /= 10;
        }
        
        if(num % tmp != 0){ // 最高位
            return false;
        }
        
        return true;
    }
};