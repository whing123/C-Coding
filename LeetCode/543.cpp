/* *题目：
 *  543
 *  Diameter of Binary Tree
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

// The diameter of a binary tree is the length of the 
// longest path between any two nodes in a tree
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int dist = height(root->left) + height(root->right);
        int ldist = diameterOfBinaryTree(root->left);  //向左递归
        int rdist = diameterOfBinaryTree(root->right); //向右递归
        
        //比较最长
        if(ldist > dist){
            dist = ldist;
        }
        if(rdist > dist){
            dist = rdist;
        }
        
        return dist;
    }
    
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int lh = height(root->left);
        int rh = height(root->right);
        return 1 + (lh > rh ? lh : rh);
    }
};