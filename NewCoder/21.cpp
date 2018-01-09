/* *题目：
 *  幸运数
 * *思路：
 *  
 */

#include <iostream>
using namespace std;
 
// base 2...10, sum of each digit
int getSum(int num, int base){
    int res = 0;
    while(num > 0){
        res += num % base;
        num /= base;
    }
    return res;
}
 
int main(){
    int n;
    while(cin >> n){
        int res = 0;
        for(int i = 1; i <= n; ++i){
            res += getSum(i,2) == getSum(i,10) ? 1 : 0;
        }
        cout << res << endl;
    }
    return 0;
}