/* *题目：
 *  101
 *  Arranging Coins
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int arrangeCoins(int n) {
        int i = pow(2,0.5)*pow(n,0.5)-1; // (2Y)^0.5
        while(1){
            if((pow(i,2)+i)/2 <= n && (pow(i,2)+3*i)/2 >= n){ // (n^2+n)/2 <= Y <= (n^2+3n)/2
                break;
            }
            i++;
        }
        return i;
    }
};

class Solution {
public:
    int arrangeCoins(int n) {
        // (i^2 + i)/2 <= n
        // i^2 + i <= 2n
        // i^2 + i + 1/4 <= 2n + 1/4
        // i + 0.5 <= sqrt(2n + 1/4)
        // i <= sqrt(2n + 1/4) - 0.5
        return (int)(pow(2 * (long)n + 0.25, 0.5) - 0.5);
    }
};