/* *题目：
 *  110
 *  Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        return abs(height(root->left)-height(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
    
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int hLeft = height(root->left);
        int hRight = height(root->right);
        return 1 + (hLeft < hRight ? hRight : hLeft);  
    }
};