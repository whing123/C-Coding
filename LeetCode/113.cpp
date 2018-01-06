/* *题目：
 *  111
 *  Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        return minD(root);
    }
    int minD(TreeNode* root);
    
};

int Solution::minD(TreeNode* root){
    if(root == NULL){
        return INT_MAX;
    }
    if(root->left == NULL && root->right == NULL){
        return 1;
    }
    int heightL = minD(root->left);
    int heightR = minD(root->right);
    return 1 + (heightL < heightR ? heightL : heightR);
}