/* *题目：
 *  二维数组排序
 */

class Solution
{
public:

	void buildHeap(float *arr, int size)
	{
		int i;

		for (i = size / 2 - 1; i >= 0; i--)
		{
			precolateDown(arr, i, size);
		}
	}

	// 最小化堆
	void precolateDown(float* arr, int hole, int size)
	{
		int child;
		float tmp = arr[hole];

		for (; hole * 2 + 1 < size; hole = child)
		{
			child = hole * 2 + 1;
			if (child != size - 1 && arr[child + 1] < arr[child])
				child++;
			if (arr[child] < tmp) arr[hole] = arr[child];
			else break;
		}
		arr[hole] = tmp;
	}

	// 输入数组，行数，每行的列数，输出的元素个数（无重复）
	float* SortD(float **D, int n, int* L, int *num)
	{
		int len = 0;
		for (int i = 0; i < n; i++)
		{
			buildHeap(D[i], L[i]);
			len += L[i];
		}

		float* res = new float[len]; // 输出
		int j = 0;

		while (1) {
			int minVal = INT_MAX;
			int index = 0;

			// 找第一列最小的
			for (int i = 0; i < n; ++i) {
				if (L[i] > 0) {
					if (D[i][0] < minVal) {
						minVal = D[i][0];
						index = i;
					}
				}
			}

			if (minVal == INT_MAX) { // 没找到
				break;
			}

			if (j == 0) {
				res[j++] = minVal;
			}
			else if (j > 0 && minVal > res[j - 1]) { // 去重
				res[j++] = minVal;
			}

			D[index][0] = D[index][L[index] - 1]; // 首尾交换
			L[index]--;
			precolateDown(D[index], 0, L[index]);
		}

		*num = j;
		return res;
	}
};