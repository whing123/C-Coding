/* *题目：
 *  841
 *  Keys and Rooms
 */

class Solution {
public:
	bool canVisitAllRooms(vector<vector<int>>& rooms) {
		int N = rooms.size();
		vector<bool> visited(N, false); // check visited

		int cnt = 0;
		return dfs(rooms, visited, 0, cnt, N);
	}

	bool dfs(vector<vector<int>>& rooms, vector<bool>& v, int start, int& cnt, int target) {
		if (v[start]) // next room visited
			return false;

		if (!v[start]) { // next room not visited
			v[start] = true; // make it visited
			cnt++; // +1
			if (cnt == target) { // if all visited
				return true;
			}

			for (int i = 0; i < rooms[start].size(); i++) { // check its keys
				if (dfs(rooms, v, rooms[start][i], cnt, target)) {
					return true;
				}
			}
		}

		return false;
	}
};