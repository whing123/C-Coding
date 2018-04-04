/* *题目：
 *  和为S的两个数字
 */

/*
数列满足递增，设两个头尾两个指针i和j，
若ai + aj == sum，就是答案（相差越远乘积越小）
若ai + aj > sum，aj肯定不是答案之一（前面已得出 i 前面的数已是不可能），j -= 1
若ai + aj < sum，ai肯定不是答案之一（前面已得出 j 后面的数已是不可能），i += 1
O(n)
*/

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int low = 0, high = array.size()-1;
        
        vector<int> res;
        while(low < high){
            if(array[low]+array[high] > sum){
                --high;
            }else if(array[low]+array[high] < sum){
                ++low;
            }else{
                res.push_back(array[low]);
                res.push_back(array[high]);
                return res;
            }
        }
        
        return res;
    }
};