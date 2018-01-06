/* *题目：
 *  最大差值
 * *思路：
 *  求满足0≤a≤b<n的A[b]-A[a]的最大值
 */

class LongestDistance {
public:
    int getDis(vector<int> A, int n) {
        
        int maxV = 0;
        for(int i = 0;i < A.size()-1;i++){
            int maxTmp = A[i];
            for(int j = i+1; j < A.size();j++){
                if(A[j] > maxTmp){
                    maxTmp = A[j];
                }
            }
            maxTmp = maxTmp - A[i];
            if(maxTmp > maxV){
                maxV = maxTmp;
            }
        }
         
        return maxV;
    }
};