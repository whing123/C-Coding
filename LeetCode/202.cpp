/* *题目：
 *  202
 *  Happy Number
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int> cycle;
        while(1){
            if((n = sumOfSquare(n)) == 1){
                return true;
            }else{
                cycle[n]++;
                if(cycle[n] > 1){
                    break;
                }
            }
        }
        return false;
    }
    
    int sumOfSquare(int n){
        int sum = 0;
        while(n > 0){
            sum += pow(n % 10,2);
            n /= 10;
        }
        return sum;
    }
};