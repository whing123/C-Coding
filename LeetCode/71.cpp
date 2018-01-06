/* *题目：
 *  572
 *  Subtree of Another Tree
 * *思路：
 *  
 * *技法：
 *  
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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool res = false;
        subTree(s, t, res);
        return res;
    }
    
    // 遍历s的所有节点
    void subTree(TreeNode* s, TreeNode* t, bool &yes){
        if(s == NULL || yes){ //提前终止
            return ;
        }
        
        // 针对值相同的节点子树进行判断
        if(s->val == t->val){ 
            yes = yes || IsSameTree(s, t);
        }
        
        subTree(s->left, t, yes); subTree(s->right, t, yes);
    }
    
    //判断两个树是否相同
    bool IsSameTree(TreeNode* root1, TreeNode* root2) {
    	if (root1 == NULL && root2 == NULL) {
    		return true;
    	}
    	if ((root1 == NULL && root2 != NULL) || (root1 != NULL && root2 == NULL)) {
    		return false;
    	}
    	if (root1->val != root2->val) {//判断每个节点的值是否相等，如果去除此判断，则判断两个二叉树是否结构相等
    		return false;
    	}
    	return IsSameTree(root1->left, root2->left) && IsSameTree(root1->right, root2->right);
    }
};