/* *题目：
 *  413
 *  Arithmetic Slices
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int size = A.size();
        int *dp = new int [size];
        dp[0] = 0;
        dp[1] = 0;
        
        //dp[i]表示以A[i]结尾的等差序列的个数，当A[i]与A[i-1]构成等差序列时
        //dp[i]=dp[i-1]+1,+1表示A[i-2],A[i-1],A[i]构成等差序列，否则dp[i]为0
        //最后对dp数组求和，即为所有的等差序列数目之和
        
        for(int i = 2;i < size;++i){
            if((A[i-2]+A[i]) == 2 * A[i-1]){
               dp[i] = dp[i-1] + 1;
            }
            else{
                dp[i] = 0;
            }
        }
        
        int res = 0;
        for(int i = 2;i < size;++i){
            res += dp[i];
        }
        
        delete [] dp;
        
        return res;
    }
};