/* *题目：
 *  斐波那契数列
 * *思路：
 *  
 */

class Solution {
public:
    int Fibonacci(int n) {
        int a = 0, b = 1;
        while(n--){
            b += a;
            a = b - a;
        }
        return a;
    }
};

class Solution {
public:
    int Fibonacci(int n) {
        if(n <= 1){
            return n;
        } 
        
        vector<int> record(n+1);
        record[0] = 0;
        record[1] = 1;
        for(int i = 2;i <= n; i++){
            record[i] = record[i-1] + record[i-2];
        }
        return record[n];
    }
};