/*
  96
  Unique Binary Search Trees
*/

// Catalan Number. The answer is C(2n, n)/(n+1)
class Solution {
public:
    int numTrees(int n) {
        long res = 1;
        for(int i = 2*n; i > n; i--){
            res = res * i / (2*n - i +1); // 先乘前面再除
        }
        
        return (int)(res / (n+1));
    }
};



/*
The problem is to get the number of unique structurally BST that stores 1...n.
We define the STATE as result[i] as the number of unique structurally BST that stores 1...i, then the END STATE as result[n].
STATE TRANSFER as below :
Each one among 1..i can be the root. 
If we take r as root (1 <= r <= i), then its left subtree is [0, r-1], and its right subtree is [r+1, i].
If we define another STATE dp[s][e] as the number of unique structurally BST that stores s...e,
the number of unique structurally BST that stores 1...i with r as root for 1 <= r <= i will be dp[1][r-1] * dp[r+1][i].
Since each one among 1..i can be the root, we try them one by one and get the sum. The the sum will be result[i].

result[i] = sum(dp[1][r-1] * dp[r+1][i]) 
          = sum(result[r-1]* result[i-r]) mainly depends on the number of nodes in left/right subtree
*/

// dp
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;
        
        for(int i = 1; i <= n; i++){ // from 1 to n sub problem
            for(int r = 1; r <= i; r++){ // r as the root of 1...i
                dp[i] += dp[r-1] * dp[i-r]; // adding left * right
            }
        }
        
        return dp[n];
    }
};