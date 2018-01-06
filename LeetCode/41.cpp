/* *题目：
 *  167
 *  Two Sum II - Input array is sorted
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int size = numbers.size();
        int j;
        
        int tmp;
        vector<int> res;
        
        int newsize = size-1;
        for(int i = 0;i < newsize;i++){
            tmp = target - numbers[i];
            if(tmp < numbers[i+1]){   //第二个数如果比当前数还小，后面没有更小的了,后面再继续会加剧这个趋势
                return res;
            }
            for(j = i+1;j < size;j++){
                if(numbers[j] == tmp){  //找到的话
                    res.push_back(i+1);
                    res.push_back(j+1);
                    i = size;  //退出外层循环设置
                    break;
                }
            }
            if(i == size){  
                break;
            }
            while(i+1 < size && numbers[i] == numbers[i+1]){ //第一次发现这个数无效后，跳过后面与它相同的数
                i++;
            }
        }
        return res;
    }
};