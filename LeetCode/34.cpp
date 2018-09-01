/* *题目：
 *  34
 *  Find First and Last Position of Element in Sorted Array
 * *思路：

 */

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> res(2);
		res[0] = getFirst(nums, 0, nums.size()-1, target);
		res[1] = getLast(nums, 0, nums.size() - 1, target);

		return res;
	}

	int getFirst(vector<int>& nums, int low, int high, int target) {
		if (low > high) {
			return -1;
		}

		int mid = low + (high - low) / 2;
		if (target > nums[mid]) {
			return getFirst(nums, mid+1, high, target);
		}
		else if (target < nums[mid]) {
			return getFirst(nums, low, mid - 1, target);
		}
		else if (mid-1 >= low && nums[mid - 1] == target) {
			return getFirst(nums, low, mid - 1, target);
		}
		
		return mid;
	}

	int getLast(vector<int>& nums, int low, int high, int target) {
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (target > nums[mid]) {
				low = mid + 1;
			}
			else if (target < nums[mid]) {
				high = mid - 1;
			}
			else if(mid+1 <= high && nums[mid+1] == target) {
				low = mid+1;
			}
			else {
				return mid;
			}
		}

		return -1;
	}
};