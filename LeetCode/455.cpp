/* *题目：
 *  455
 *  Assign Cookies
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		int sizeG = g.size(), sizeS = s.size();
		int cntPair = 0;
		quickSort(g,sizeG);
		quickSort(s,sizeS);
		int i = sizeS - 1, j = sizeG - 1; 
		while(i >= 0 && j >= 0) {
			if (s[i] >= g[j]) {
				cntPair++;
				i--;
				j--;
			}
			else {
				j--;
			}
		}
		return cntPair;
	}
	void quickSort(vector<int>& a, int size) {
		quickSort(a, 0, size - 1);
	}
	void quickSort(vector<int>& a, int low, int high) {
		int mid;
		if (low >= high) return;
		mid = divide(a, low, high);
		quickSort(a, low, mid - 1);
		quickSort(a, mid + 1, high);
	}
	int divide(vector<int>& a, int low, int high) {
		int k = a[low];
		do {
			while (low < high && a[high] >= k)--high;
			if (low < high) {
				a[low] = a[high];
				++low;
			}
			while (low < high && a[low] <= k)++low;
			if (low < high) {
				a[high] = a[low];
				--high;
			}
		} while (low != high);
		a[low] = k;
		return low;
	}
};

