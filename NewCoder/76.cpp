/* *题目：
 *  连续子数组的最大和
 */

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum = array[0];
        for(int i = 1; i < array.size(); ++i){
            if(array[i-1] > 0){ // 如果前一个大于0，有增益，则加到i上
                array[i] += array[i-1];
            }
            
            if(array[i] > sum){ // update max
                sum = array[i];
            }
        }
        
        return sum;
    }
};