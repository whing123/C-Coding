/* *题目：
 *  897
 *  Increasing Order Search Tree
 
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
    TreeNode* increasingBST(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        
        TreeNode* tmp = new TreeNode(-1);
        TreeNode* cur = tmp;
        
        in_order(root, cur);
        
        cur = tmp->right;
        delete tmp;
            
        return cur;
    }
    
    void in_order(TreeNode* root, TreeNode* &cur) {
        if (root) {
            in_order(root->left, cur);
            
            cur->right = root;
            root->left = NULL;
            cur = cur->right;
            
            in_order(root->right, cur);
        }
    }
};