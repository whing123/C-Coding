/* *题目：
 *  买苹果
 * *思路：
 *  
 */

#include <iostream>
 
using namespace std;
 
int getN(int n){
    if(n%2 != 0 || n < 6 || n == 10){ // 排除奇数，小于6的，和10
        return -1;
    }else if(n % 8 == 0){ // 能直接被8除尽最好
        return n / 8;
    }else{
        return 1 + n/8;  // 除不尽，此时被8除的余数为2,4,6 为6则正好，为2或4则从前面2或1个8中拿出2个苹果，补余数为6
    }
}
 
int main(){
    int n;
    while(cin >> n){
        cout << getN(n) << endl;
    }
    return 0;
}

// dp
#include <cmath>
#include <limits.h>
 
//动态规划
/**
 f(6) = f(8) = 1
 f(i) = min(f(i-6) + 1, f(i-8) + 1);
*/
int getN(int n){
    int *dp = new int [n+1];
    for(int i = 0; i <= n; ++i){
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
     
    for(int i = 0; i <= n; ++i){
        if(dp[i] != INT_MAX){
            if(i+6 <= n){
                dp[i+6] = min(dp[i]+1, dp[i+6]);
            }
            if(i+8 <= n){
                dp[i+8] = min(dp[i]+1, dp[i+8]);
            }
        }
    }
     
    int res = dp[n] == INT_MAX ? -1 : dp[n];
    delete [] dp;
    return res;
}