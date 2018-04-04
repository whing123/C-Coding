/* *题目：
 *  734
 *  Sentence Similarity
 * *思路：
 *  
 */


class Solution {
public:
	bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
		if (words1.size() != words2.size()) { // 长度不匹配
			return false;
		}

		map<string, set<string>> pair_map; // pair中以每个str为键，构造对应的相似str集合 映射
		map<string, set<string>>::iterator it;
		for (int i = 0; i < pairs.size(); ++i) {
			if ((it = pair_map.find(pairs[i].first)) == pair_map.end()) { // map不存在str，构造新的映射
				set<string> tmp;
				tmp.insert(pairs[i].second);
				pair_map.insert(pair<string,set<string>>(pairs[i].first,tmp));
			}
			else { // 若map存在，添加对应的相似str
				it->second.insert(pairs[i].second);
			}
            
            // first 与 second 调换
			if ((it = pair_map.find(pairs[i].second)) == pair_map.end()) {
				set<string> tmp;
				tmp.insert(pairs[i].first);
				pair_map.insert(pair<string, set<string>>(pairs[i].second, tmp));
			}
			else {
				it->second.insert(pairs[i].first);
			}
		}

		int len = words1.size();
		for (int i = 0; i < len; ++i) {
			if (!isSimilar(words1[i], words2[i], pair_map)) {
				return false;
			}
		}

		return true;
	}
    
    // 相似度检查
	bool isSimilar(string a, string b, map<string, set<string>>& pair_map) {
		if (a == b) { // 若相等
			return true;
		}

		map<string, set<string>>::iterator it;
		if ((it = pair_map.find(a)) != pair_map.end()) {
			if (it->second.find(b) != it->second.end()) { // 匹配找到
				return true;
			}
		}

		return false;
	}
};