/* *题目：
 *  513
 *  Find Bottom Left Tree Value
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
    int findBottomLeftValue(TreeNode* root) {
        if(root->left == NULL && root->right == NULL)
            return root->val;
        int res;
        if(getHeight(root->left) >= getHeight(root->right)){ //左子树高于右子树时去找左边，左边优先级高
            res = findBottomLeftValue(root->left);           //左右一样高找左边，否则找最高的
        }else{
            res = findBottomLeftValue(root->right);
        }
        return res;
    }
    
    int getHeight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftH = getHeight(root->left);
        int rightH = getHeight(root->right);
        
        return 1 + (leftH > rightH ? leftH : rightH);
    }
};