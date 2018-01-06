/* *题目：
 *  384
 *  Shuffle an Array
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    Solution(vector<int> nums) {
        arr = nums;
        backup = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        arr.clear();
        arr = backup;
        return arr;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int size = arr.size();
        vector<int> visited(size,0);
        
        int pos;
        int cnt;
        int t = 0;
        for(int i = 0;i < size-1;i++){
            pos = rand()%(size-i);  //剩余位置中新的随机位置
            cnt = 0;
            for(int j = 0;j < size;j++){
                if(visited[j] == 0){  //忽略那些已经取过的位置
                    if(cnt == pos){   //数到随机位置时
                        arr[t++] = backup[j];
                        visited[j] = 1;
                        break;
                    }
                    cnt++;
                }
            }
        }
        
        for(int j = 0;j < size;j++){  //最后一个未取过的位置留给最后一个
            if(visited[j] == 0){
                arr[t] = backup[j];
            }
        }
        return arr;
    }
    
private:
    vector<int> arr;
    vector<int> backup;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */