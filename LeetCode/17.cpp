/* *题目：
 *  17
 *  Letter Combinations of a Phone Number
 */


class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;
        if (digits.length() == 0) {
            return res;
        }
        
		string cur;
		static string mappings[] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		dfs(digits, mappings, res, cur, 0);

		return res;
	}

	void dfs(const string& digits, string mappings[], vector<string>& res, string cur, int start) {
		if (cur.length() == digits.length()) {
			res.push_back(cur);

			return;
		}

		for (int i = start; i < digits.length(); i++) {
			for (int j = 0; j < mappings[digits[i] - '0' - 2].length(); j++) {
				dfs(digits, mappings, res, cur + mappings[digits[i] - '0' - 2][j], i + 1);
			}
		}
	}
};