/* *题目：
 *  756
 *  Pyramid Transition Matrix
 */

class Solution {
public:
	bool pyramidTransition(string bottom, vector<string>& allowed) {
		// make look-up table
		map<string, vector<char>> data;
		map<string, vector<char>>::iterator it;
		for (int i = 0; i < allowed.size(); i++) {
            string prefix = allowed[i].substr(0, 2);
			if ((it = data.find(prefix)) != data.end()) {
				it->second.push_back(allowed[i][2]);
			}
			else {
				vector<char> tmp;
				tmp.push_back(allowed[i][2]);
				data[prefix] = tmp;
			}
		}

		return helper(bottom, allowed, data);
	}

	bool helper(string bottom, vector<string>& allowed, map<string, vector<char>>& data) {
		if (bottom.length() == 1) {
			return true;
		}
        
        // early skip
        for (int i = 0; i < bottom.length() - 1; i++) {
			if (data.find(bottom.substr(i, 2)) == data.end()) {
				return false;
			}
        }
        
		vector<string> res;
        vector<char> newBottom;
        dfs(res, newBottom, bottom, allowed, data, 0);

		for (int i = 0; i < res.size(); i++) {
			if (helper(res[i], allowed, data)) {
				return true;
			}
		}

		return false;
	}

	// search all kinds of this level
	void dfs(vector<string> &res, vector<char>& newBottom, string bottom, vector<string>& allowed, map<string, vector<char>>& data, int start) {
		if (start == bottom.length() - 1) {
            string tmp(newBottom.begin(), newBottom.end());
			res.push_back(tmp);
			return;
		}

		map<string, vector<char>>::iterator it;
        it = data.find(bottom.substr(start, 2));
        for (int i = 0; i < it->second.size(); i++) {
            newBottom.push_back(it->second[i]);
            dfs(res, newBottom, bottom, allowed, data, start + 1);
            newBottom.pop_back();
        }
	}
};