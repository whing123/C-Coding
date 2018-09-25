/*
  71
  Simplify Path
*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> paths;
        size_t start = 0, pos;
        while ((pos = path.find_first_of('/', start)) != string::npos) {
            paths.push_back(path.substr(start, pos - start));
            start = pos + 1;
        }
        paths.push_back(path.substr(start));

        deque<string> st;
        set<string> hash = { "..", ".", "" };
        for (int i = 0; i < paths.size(); i++) {
            if (paths[i].compare("..") == 0 && !st.empty()) {
                st.pop_back();
            }
            else if (hash.find(paths[i]) == hash.end()) {
                st.push_back(paths[i]);
            }
        }

        string res = "";
        for (int i = st.size()-1; i >= 0; i--) {
            res = "/" + st[i] + res;
        }

        if (res.compare("") == 0) {
            return "/";
        }
        else {
            return res;
        }
    }
};