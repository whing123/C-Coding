/* *题目：
 *  538
 *  Convert BST to Greater Tree
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
    int cur_sum = 0;
public:
    TreeNode* convertBST(TreeNode* root) {
        doIt(root);
        return root;
    }
    
    void doIt(TreeNode* root){
        if(root == NULL){
            return ;
        }
        
        if(root->right)
            doIt(root->right);
        
        root->val = (cur_sum += root->val);
        
        if(root->left){
            doIt(root->left);
        }
        
    }
};