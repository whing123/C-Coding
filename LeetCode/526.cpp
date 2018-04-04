/* *题目：
 *  526
 *  Beautiful Arrangement
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    int countArrangement(int N) {
        int *arr;
        arr = new int [N];
        for(int i = 0;i < N;i++){  // 初始化
            arr[i] = i+1;
        }
        
        int res = 0;
        FullArray(arr,N,0,res);
        delete [] arr;
        
        return res;
    }
    
    template <typename T>
    inline void swap(T* array, unsigned int i, unsigned int j)
    {
    	T t = array[i];
    	array[i] = array[j];
    	array[j] = t;
    }
    
    /*
    * 递归输出序列的全排列
    */
    template <typename T>
    void FullArray(T* array, size_t array_size, unsigned int index, int &sum)
    {
    
    	if (index >= array_size)  // 搜索到最后位置时结束输出
    	{
    		++sum;
    		return;
    	}
    
    	for (unsigned int i = index; i < array_size; ++i)
    	{
    
    		if (array[i] % (index + 1)  && (index + 1) % array[i]) {  // 判断是否满足条件
    			continue;
    		}
    
    		swap(array, i, index);  // 将第i个位置换至index，index为当前子序列头部
    		FullArray(array, array_size, index + 1, sum);  // 将第index位置确定后，递归排列index+1之后的位置
    		swap(array, i, index);  // 将之前的交换返回，以备i+1位置的数交换至index
    	}
    }
};