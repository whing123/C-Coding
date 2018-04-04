/* *题目：
 *  303
 *  Range Sum Query - Immutable
 * *思路：
 *  
 * *技法：
 *  
 */

class NumArray {
public:
    NumArray(vector<int> &nums) {
        num = nums;
        sum = vector<int>(nums.size(),0);
        for(int i = 0;i < nums.size();i++){
            if(i > 0){
                sum[i] = sum[i-1] + nums[i];
            }else{
                sum[i] = nums[i];
            }
        }
    }

    int sumRange(int i, int j) {
        int t;
        t = sum[j] - sum[i] + num[i];
        return t;
    }
private:
    vector<int> num;
    vector<int> sum;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);