/* *题目：
 *  669
 *  Trim a Binary Search Tree
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
    /*
    If the root value in the range [L, R]
      we need return the root, but trim its left and right subtree;
    else if the root value < L
      because of binary search tree property, the root and the left subtree are not in range;
      we need return trimmed right subtree.
    else
      similarly we need return trimmed left subtree.
    */
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == NULL){
            return NULL;
        }
        
        if(root->val < L){
            root = root->right;
            return trimBST(root, L, R);
        }else if(root->val > R){
            root = root->left;
            return trimBST(root, L, R);
        }
        
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        
        return root;
    }
};