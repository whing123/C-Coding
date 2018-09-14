/* *题目：
 *  93
 *  Restore IP Addresses
 */

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        if(s.length() < 4 || s.length() > 12) {
            return res;
        }
        
        int len = s.length()-1;
        vector<int> dots(len);
        for (int i = 0; i < len; i++) {
            dots[i] = i + 1;
        }
        
        vector<int> cur;
        dfs(s, dots, cur, 0, res);
        
        return res;
    }
    
    void dfs(string& s, vector<int>& dots, vector<int>& cur, int start, vector<string>& res) {
        if (cur.size() == 3) {
            string n1 = s.substr(0, cur[0]);
            string n2 = s.substr(cur[0], cur[1] - cur[0]);
            string n3 = s.substr(cur[1], cur[2] - cur[1]);
            string n4 = s.substr(cur[2]);

            if (check(n1) && check(n2) && check(n3) && check(n4)) {
                string tmp= n1 + "." + n2 + "." + n3 + "." + n4;
                res.push_back(tmp);
            }

            return;
        }
        else if (cur.size() > 3) {
            return;
        }

        for (int i = start; i < dots.size(); i++)
        {
            cur.push_back(dots[i]);
            dfs(s, dots, cur, i+1, res);
            cur.pop_back();
        }
    }
    
    bool check(string s) {
        if (s.length() > 1 && s[0] == '0') {
            return false;
        }
        
        int num = -1;
        try {
            num  = stoi(s);
        }catch (exception e) {
            return false;
        }
        
        if (num > 255) {
            return false;
        }

        return true;
    }
};