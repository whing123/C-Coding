/* *题目：
 *  数组单调和
 * *思路：
 *  
 */

// 计算所有元素的单调和
class MonoSum {
public:
    int calcMonoSum(vector<int> A, int n) {
        
        int sum = 0;
        for(int i = 1;i < A.size();i++){
            for(int j = 0;j < i;j++){
                if(A[j] <= A[i]){
                    sum += A[j];
                }
            }
        }
         
        return sum;
    }
};