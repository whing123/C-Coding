/* *题目：
 *  42
 *  Trapping Rain Water
 * *思路：

 */

class Solution {
public:
    int trap(vector<int>& height) {
		stack<pair<int, int>> waters; // peak index, water

		// jump "up stage"
		int i = 0;
		while (i + 1 < height.size() && height[i] <= height[i + 1]) {
			i++;
		}
		waters.push(make_pair(i, 0));

		int highest = i; // index of highest
		while (i + 1 < height.size()) {

			// jump down
			while (i + 1 < height.size() && height[i] >= height[i + 1]) {
				i++;
			}

			// jump up and get peak
			while (i + 1 < height.size() && height[i] <= height[i + 1]) {
				i++;
			}

			while (height[waters.top().first] < height[highest] && height[i] > height[waters.top().first]) {
				waters.pop();
			}

			// sum water
			int sum = 0;
			int curHeight = min(height[i], height[highest]);
			for (int j = waters.top().first + 1; j < i; j++) {
				sum += curHeight > height[j] ? curHeight - height[j] : 0;
			}

			waters.push(make_pair(i, sum));
			highest = height[i] > height[highest] ? i : highest; // update
		}

		int res = 0;
		while (!waters.empty()) {
			res += waters.top().second;
			waters.pop();
		}

		return res;
	}
};