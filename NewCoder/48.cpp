/* *题目：
 *  从上往下打印二叉树，层序遍历
 * *思路：
 *  
 */

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> res;
        if(root == NULL){
            return res;
        }

        queue<TreeNode*> tmp;
        tmp.push(root);
        while(!tmp.empty()){
            
            int size = tmp.size();
            while(size--){
                TreeNode* p = tmp.front();
                res.push_back(p->val);
                tmp.pop();
                
                if(p->left != NULL){
                    tmp.push(p->left);
                }
                if(p->right != NULL){
                    tmp.push(p->right);
                }
            }
        }

        return res;
    }
};