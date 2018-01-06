/* *题目：
 *  532
 *  K-diff Pairs in an Array
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());  //排序
        int res = 0;
        
        if(k == 0){  //差值为0
            int i = 0;
            while(i < nums.size()){
                bool flag = false;
                while(i+1 < nums.size() && nums[i] == nums[i+1]){
                    i++;
                    if(!flag){  //对相同的只记录一次
                        flag = true;
                        res++;
                    }
                }
                i++;
            }
        }else{
            int i = 0;
            while(i < nums.size()){
                while(i+1 < nums.size() && nums[i] == nums[i+1]){
                    nums.erase(nums.begin()+i+1);  //擦除重复的
                }
                i++;
            }
            
            for(int j = 0;j < nums.size();j++){
                for(int m = j+1;m < nums.size();m++){
                    if(nums[m]-nums[j] == k){ //如果找到了
                        res++;
                        break;
                    }else if(nums[m]-nums[j] > k){ //找不到时，及时退出
                        break;
                    }
                }
            }
            
        }
        
        return res;
    }
};