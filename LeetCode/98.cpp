/* *题目：
 *  98
 *  Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        
        if(root->left != NULL && root->val <= maxL(root->left)){
            return false;
        }
        if(root->right != NULL && root->val >= minR(root->right)){
            return false;
        }
        
        return isValidBST(root->left) && isValidBST(root->right);
    }
           
    int minR(TreeNode* root){ // 右子树最小值
        while(root->left != NULL){
            root = root->left;
        }
        
        return root->val;
    }
           
    int maxL(TreeNode* root){ // 左子树最大值
        while(root->right != NULL){
            root = root->right;
        }

        return root->val;
    }
};