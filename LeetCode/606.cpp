/* *题目：
 *  606
 *  Construct String from Binary Tree 
 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    string tree2str(TreeNode* t) {
		string res;
		int pos = 0;
		preoder(t, res, pos);

		res = res.substr(1, res.length() - 2);  // 去掉首尾括号

		return res;
	}

	void preoder(TreeNode* t, string& res, int& pos) {
		if (t == NULL) {
			res.insert(pos, "()");
			pos += 2;
			return;
		}

		string val_str = "(" + to_string(t->val) + ")";
		res.insert(pos, val_str);
		pos += val_str.length() - 1; // reach ')'

		preoder(t->left, res, pos);
		
		preoder(t->right, res, pos);

		// delete empty ()
		if (res[pos - 2] == '(' && res[pos - 1] == ')') {
			res.erase(pos-2, 2);
			pos -= 2;

			if (res[pos - 2] == '(' && res[pos - 1] == ')') {
				res.erase(pos - 2, 2);
				pos -= 2;
			}
		}

		pos++;  // 回到上一层，转移到下一级
	}
};

// java
public class Solution {
    public String tree2str(TreeNode t) {
        if (t == null) return "";
        
        String result = t.val + "";
        
        String left = tree2str(t.left);
        String right = tree2str(t.right);
        
        if (left == "" && right == "") return result;
        if (left == "") return result + "()" + "(" + right + ")";
        if (right == "") return result + "(" + left + ")";
        return result + "(" + left + ")" + "(" + right + ")";
    }
}