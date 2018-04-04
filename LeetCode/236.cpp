/* *题目：
 *  236
 *  Lowest Common Ancestor of a Binary Tree
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q){ // 找到其中一个就返回
            return root;
        }

        TreeNode* L = lowestCommonAncestor(root->left, p, q);
        TreeNode* R = lowestCommonAncestor(root->right, p, q);
        if(L && R){ // 如果在root的左右子树分别找到，则返回root
            return root;
        }
        
        return L ? L : R; // 如果只找到其中一个，说明在root同一个子树上，那么该节点就是公共祖先
    }

};