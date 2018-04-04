/* *题目：
 *  450
 *  Delete Node in a BST
 * *思路：
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        
        if(root->val > key){ // 左子树查找
            root->left = deleteNode(root->left, key);
        }else if(root->val < key){ // 右子树查找
            root->right = deleteNode(root->right, key);
        }else{ // 如果已找到
            if (root->left && root->right) { // 左右均不空
                root->val = findMin(root->right);
                root->right = deleteNode(root->right, root->val);
            }else { // 左右至少空一个
                TreeNode* to_delete = root;
                if (root->left) root = root->left;
                else if (root->right) root = root->right;
                else root = NULL;
                delete to_delete;
            }
        }
        
        return root;
    }
    
    int findMin(TreeNode* root){
        while(root->left != NULL){
            root = root->left;
        }
        
        return root->val;
    }
};