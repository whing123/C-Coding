/* *题目：
 *  290
 *  Word Pattern
 * *思路：
 *  
 * *技法：
 *  
 */

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int size1 = pattern.size();
        vector<string> sub = subString(str);
        int size2 = sub.size();
        if(size1 != size2)
            return false;
    	vector<int> label1 = transferP(pattern);
    	vector<int> label2 = transferS(sub);
    
    	for (int i = 0; i < size1; i++) {
    		if (label1[i] != label2[i])
    			return false;
    	}
    	return true;
    }
private:
    vector<string> subString(string str){
        vector<string> sub;
        size_t pos;
        for(size_t i = 0;;){
            pos = str.find(' ',i);
            if(pos != string::npos){
                sub.push_back(str.substr(i,pos-i));
                i = pos + 1;
            }
            else{
                sub.push_back(str.substr(i,str.size()-i));
                break;
            }
        }
        return sub;
    }
    vector<int> transferP(string p) {
	    int size = p.size();
	    vector<int> label(size, -1);
	    for (int i = 0, j = 0; i < size; i++) {
		    if (label[i] == -1) {
			    label[i] = j;
			    for (int k = i + 1; k < size; k++) {
			    	if (label[k] == -1 && p[i] == p[k]) {
					    label[k] = j;
			    	}
		    	}
			    j++;
		    }
	    }
    	return label;
    }
    vector<int> transferS(vector<string> s) {
    	int size = s.size();
    	vector<int> label(size, -1);
    	for (int i = 0, j = 0; i < size; i++) {
    		if (label[i] == -1) {
    			label[i] = j;
    			for (int k = i + 1; k < size; k++) {
    				if (label[k] == -1 && s[i] == s[k]) {
    					label[k] = j;
    				}
    			}
    			j++;
    		}
    	}
    	return label;
    }
};