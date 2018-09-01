/* *题目：
 *  139
 *  Word Break
 */

// dfs
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
        set<string> hashSet;
        set<string> mp;
        for (int i = 0; i < wordDict.size(); i++) {
            mp.insert(wordDict[i]);
        }
		return dfs(s, wordDict, hashSet, mp);
	}

	bool dfs(string s, vector<string>& wordDict, set<string>& hashSet, set<string>& mp) {
		if (mp.find(s) != mp.end()) { // already exist
			return true;
		}
        if(hashSet.find(s) != hashSet.end()) { // reuse info
            return false;
        }

		for (int i = 0; i < wordDict.size(); i++) {
			if (s.find(wordDict[i]) == 0) {
				if (dfs(s.substr(wordDict[i].length()), wordDict, hashSet, mp)) {
					return true;
				}
			}
		}
        
        hashSet.insert(s);
		return false;
	}
};

// dp
// dp[i] is set to true if a valid word (word sequence) ends there
class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
        if(wordDict.size() == 0) {
            return false;
        }
        
        set<string> mp;
        for (int i = 0; i < wordDict.size(); i++) {
            mp.insert(wordDict[i]);
        }
		
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.length(); i++) {
            for (int j = i-1; j >= 0; j--) {
                if (dp[j]) {
                    string tmp = s.substr(j, i-j);
                    if (mp.find(tmp) != mp.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        
        return dp[s.length()]; 
	}
};