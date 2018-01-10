/* *题目：
 *  拼凑面额
 * *思路：
 *  
 */

#include <iostream>
#include <vector>
 
using namespace std;
 
int main(){
    int coins[6] = {1,5,10,20,50,100};
    int N;
    while(cin >> N){
        vector<long> dp(N+1, 0);
        dp[0] = 1;
         
        for(int i = 0; i < 6; ++i){
            for(int j = 1; j <= N; ++j){
                if(j >= coins[i]){
                    dp[j] += dp[j-coins[i]];
                }
            }
        }
         
        cout << dp[N] << endl;
    }
    return 0;
}

/*动态规划
    需要拼凑的面额是n，
    维护dp[i],表示取到i时的组合数目，dp[0]=1，
    面额数组a[6]={1,5,10,20,50,100}，
    dp[j]=dp[j]+dp[j-a[i]],约数条件j>a[i]。
    因为面额数目任意，
    所以需要分别处理只有面额1时，组合钱数为1~n的各自组合数dp[1]~dp[n],
    然后有面额1,5时，组合钱数为1~n的各自组合数dp[1]~dp[n],
    依此内推
*/

/*
1.dp概念：简单来说就是将原来的问题分解成多个子问题，
  然后将子问题一个一个的解决，最终问题的规模变小了；
2.本题可以使用dp的思想来做，合成一个面值为n的组合数，
  可以看成合成n-1,n-5,n-10,n-20,n-50,n-100五个面值的组合数之和，
  然后将问题细分化，最终可以求出结果
*/