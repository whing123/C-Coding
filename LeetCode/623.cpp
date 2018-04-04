/* *题目：
 *  623
 *  Add One Row to Tree
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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* tmp = new TreeNode(v);
            tmp->left = root;
            return tmp;
        }
        helper(root, v, d, 1);
        return root;
    }
    
    void helper(TreeNode* root, int v, int d, int level){
        if(root == NULL){
            return;
        }
        
        if(level == d-1){
            TreeNode *tmp = root->left;
            root->left = new TreeNode(v);
            root->left->left = tmp;
            
            tmp = root->right;
            root->right = new TreeNode(v);
            root->right->right = tmp;
            
            return;
        }
        
        helper(root->left, v, d, level+1);
        helper(root->right, v, d, level+1);
    }
};