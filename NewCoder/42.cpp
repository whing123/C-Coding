/* *题目：
 *  二叉树的镜像
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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL){
            return;
        }
        
        TreeNode* tmp = pRoot->right;
        pRoot->right = pRoot->left;
        pRoot->left = tmp;
        
        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};
