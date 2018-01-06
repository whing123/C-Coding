/* *题目：
 *  144
 *  Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        pre(root,res);
        return res;
    }
    
    void pre(TreeNode *root, vector<int> &tmp){
        if(root==NULL){
            return;
        }
        
        tmp.push_back(root->val);
        pre(root->left,tmp); //左
        pre(root->right,tmp); //右
    }
};