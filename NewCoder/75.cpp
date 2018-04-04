/* *题目：
 *  旋转数组的最小数字
 */

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        for(int i = 0; i < rotateArray.size()-1; ++i){
            if(rotateArray[i] > rotateArray[i+1]){
                return rotateArray[i+1];
            }
        }
        
        return rotateArray[0];
    }
};

/*
采用二分法解答这个问题，mid = low + (high - low)/2
需要考虑三种情况：
(1)array[mid] > array[high]:
出现这种情况的array类似[3,4,5,6,0,1,2]，此时最小数字一定在mid的右边。
low = mid + 1
(2)array[mid] == array[high]:
出现这种情况的array类似 [1,0,1,1,1] 或者[1,1,1,0,1]，此时最小数字不好判断在mid左边
还是右边,这时只好一个一个试 ，
high = high - 1
(3)array[mid] < array[high]:
出现这种情况的array类似[2,2,3,4,5,6,6],此时最小数字一定就是array[mid]或者在mid的左
边。因为右边必然都是递增的。
high = mid
*/

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int low = 0, high = rotateArray.size()-1;
        while(low < high){
            int mid = low + (high-low)/2;
            if(rotateArray[mid] < rotateArray[high]){
                high = mid;
            }else if(rotateArray[mid] > rotateArray[high]){
                low = mid + 1;
            }else{
                --high;
            }
        }
        
        return rotateArray[low];
    }
};