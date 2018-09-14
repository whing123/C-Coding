/* *题目：
 *  680
 *  Valid Palindrome II
 * *思路：

 */

class Solution {
public:
	bool validPalindrome(string s) {
		int size = s.length();
        
        // suppose it is no need to delete
        // left is in right
		if (isSubStr(s.substr(0, size / 2), reverse(s.substr((size + 1) / 2, size / 2)))) {
			return true;
		}
        
        // need to delete one
        
        // even num, left is in right
		if ((size - 1) % 2 == 0 && isSubStr(s.substr(0, (size - 1) / 2), reverse(s.substr((size - 1) / 2, size - (size - 1) / 2)))) {
			return true;
		}
        // even num, right is in left
		if ((size - 1) % 2 == 0 && isSubStr(reverse(s.substr((size - 1) / 2 + 1, (size - 1) / 2)), s.substr(0, size - (size - 1) / 2))) {
			return true;
		}
        
        // odd num, left is in right
		if ((size - 1) % 2 == 1 && isSubStr(s.substr(0, (size - 1) / 2), reverse(s.substr((size - 1) / 2 + 1, size - (size - 1) / 2 - 1)))) {
			return true;
		}
        
        // odd num, right is in left
		if ((size - 1) % 2 == 1 && isSubStr(reverse(s.substr((size - 1) / 2 + 2, (size - 1) / 2)), s.substr(0, size - (size - 1) / 2 - 1))) {
			return true;
		}
        
		return false;
	}

	// check if b contains a, continuity not needed
	bool isSubStr(string a, string b) {
		int start = 0;
		int j;
		for (int i = 0; i < a.length(); ++i) {
			for (j = start; j < b.length(); ++j) {
				if (a[i] == b[j]) {
					start = j + 1;
					break;
				}
			}

			if (j == b.length()) {
				return false;
			}
		}
		return true;
	}

	// reverse a string
	string reverse(string a) {
		for (int i = 0; i < a.length() / 2; ++i) {
			char tmp = a[i];
			a[i] = a[a.length() - 1 - i];
			a[a.length() - 1 - i] = tmp;
		}
		return a;
	}
};
