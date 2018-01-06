/* *题目：
 *  396
 *  Rotate Function
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
        int maxV, sum = 0, tmp = 0;
        int i, j;
        for(i = 0;i < n;i++){
           sum += A[i];
           tmp += i * A[i];
        }
        
        j = n-1;
        maxV = tmp;
        for(i = 1;i < n;i++,j--){
            tmp += sum - n * A[j];
            if(tmp > maxV){
                maxV = tmp;
            }
        }
        return maxV;
    }
};