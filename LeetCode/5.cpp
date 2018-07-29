/*
  5 
  Longest Palindromic Substring
  最长回文子串
*/

/*
dp(i, j) represents whether s(i ... j) can form a palindromic substring, 
dp(i, j) is true when s(i) equals to s(j) and s(i+1 ... j-1) is a palindromic substring. 
When we found a palindrome, check if it's the longest one. Time complexity O(n^2).
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        string res;
        
        for(int i = len-1; i >= 0; i--){
            for(int j = i; j < len; j++){
                dp[i][j] = s[i] == s[j] && (i+1 < len && j-1 >= 0 && dp[i+1][j-1] || j-i < 3); // check, *x* is also ok
                if(dp[i][j] && j-i+1 > res.length()){ // update
                    res = s.substr(i, j-i+1);
                }
            }
        }
        
        return res;
    }
};