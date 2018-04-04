/* *题目：
 *  337
 *  House Robber III
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
    int rob(TreeNode* root) {
        return helper(root, false);
    }
    
    int helper(TreeNode* root, bool isParentDone){
        if(root == NULL){
            return 0;
        }
        
        if(isParentDone){ // 父节点偷过
            return helper(root->left, false) + helper(root->right, false);
        }else{ // 父节点未偷过
            int yes = root->val + helper(root->left, true) + helper(root->right, true); // 偷当前节点
            int no = helper(root->left, false) + helper(root->right, false); // 不偷当前节点
            
            return max(yes, no);
        }
        
        return 0;
    }
};