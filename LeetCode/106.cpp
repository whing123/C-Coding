/* *题目：
 *  106
 *  Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size() == 0){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(postorder[postorder.size()-1]);
        int index;
        for(int i = 0; i < inorder.size(); ++i){ // find root
            if(inorder[i] == root->val){
                index = i;
            }
        }
        
        vector<int> postL(postorder.begin(), postorder.begin()+index), postR(postorder.begin()+index, postorder.end()-1);
        vector<int> inL(inorder.begin(), inorder.begin()+index), inR(inorder.begin()+index+1, inorder.end());
        root->left = buildTree(inL, postL);
        root->right = buildTree(inR, postR);
        
        return root;
    }
};