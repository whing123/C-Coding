/* *题目：
 *  最小的K个数
 */

// 冒泡排序
class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int N = input.size();
        if(k > N){
            return res;
        }
        if(k == N){
            return input;
        }
        
        for(int i = 1; i <= k; ++i){ // k趟冒泡
            for(int j = 0; j < N - i; ++j){
                if(input[j] < input[j+1]){
                    int tmp = input[j+1];
                    input[j+1] = input[j];
                    input[j] = tmp;
                }
            }
            res.push_back(input[N-i]);
        }
        
        return res;
    }
};

/*
思路二：利用堆排序，O(N logK)，适合处理海量数据
(1) 遍历输入数组，将前k个数插入到推中；（利用multiset来做为堆的实现）
(2) 继续从输入数组中读入元素做为待插入整数，并将它与堆中最大值比较：
如果待插入的值比当前已有的最大值小，则用这个数替换当前已有的最大值；
如果待插入的值比当前已有的最大值还大，则抛弃这个数，继续读下一个数。
这样动态维护堆中这k个数，以保证它只储存输入数组中的前k个最小的数，最后输出堆即可。
*/

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        int N = input.size();
        if(k > N){
            return res;
        }
        if(k == N){
            return input;
        }
        
        multiset<int, greater<int>> data;
        multiset<int, greater<int>>::iterator it;
        for(int i = 0; i < N; ++i){
            if(i < k){
                data.insert(input[i]);
            }else{
                it = data.begin();
                if(input[i] < *it){
                    data.erase(it);
                    data.insert(input[i]);
                }
            }
        }
        
        for(it = data.begin(); it != data.end(); ++it){
            res.push_back(*it);
        }
        
        return res;
    }
};