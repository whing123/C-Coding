/* *题目：
 *  袋鼠过河
 * *思路：
 *  
 */

#include <iostream>
 
using namespace std;
 
/**
思路：贪心算法。在袋鼠能跳的区间中寻找能跳的最远的柱子，该距离等于此柱子下标减去起跳柱子下标+此柱子能跳的步数，用一变量指向此柱，
若最远距离值为0，则不能上岸；否则跳到此柱。
*/
 
int main(){
    int n;
    int *arr;
    while(cin >> n){
        arr = new int[n];
        for(int i = 0; i < n; ++i){
            cin >> arr[i];
        }
         
        bool flag = false;
        int cnt = 1;
        for(int i = 0; i < n;){
            int maxL = 0;
            int pos;
            for(int j = 1; j <= arr[i]; ++j){
                if(i+j >= n){ // 结束
                    flag = true;
                    break;
                }
                if(arr[i+j] != 0){ // 寻找下一点所能到达的最远距离
                    int tmp = arr[i+j] + i+j;
                    if(maxL < tmp){
                        maxL = tmp;
                        pos = i+j;
                    }
                }
            }
             
            if(flag){ // 结束
                cout << cnt << endl;
                break;
            }
            if(maxL == 0){ // 最远距离为0
                cout << -1 <<endl;
                break;
            }
             
            cnt++;
            i = pos;
        }
         
        delete [] arr;
    }
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int GetCount(vector<int>& num)
{
    int n = num.size();
    vector<int> dp(n + 1, 10000);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (num[j] == 0)
                continue;
            if (j + num[j] >= i)
                dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    if (dp[n] == 10000)
        return -1;
    else
        return dp[n];
}
  
int main()
{
    int N = 0;
    cin >> N;
    vector<int> num(N,0);
    for (int i = 0; i < N; i++)
        cin >> num[i];
    cout << GetCount(num) << endl;
    return 0;
}