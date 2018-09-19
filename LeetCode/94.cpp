/* *题目：
 *  94
 *  Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root,res);
        return res;
    }
    
    void inorder(TreeNode* root, vector<int>& add){
        if(root == NULL){
            return;
        }
        inorder(root->left,add);
        add.push_back(root->val);
        inorder(root->right,add);
    }
};


// iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur || !st.empty()) {
            if (cur) {
                st.push(cur);
                cur = cur->left;
            } else {
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                
                cur = cur->right;
            }
        }
        
        return res;
    }
};