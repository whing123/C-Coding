/* *题目：
 *  105
 *  Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0){
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[0]);
        int index;
        for(int i = 0; i < inorder.size(); ++i){ // find root
            if(inorder[i] == preorder[0]){
                index = i;
            }
        }
        
        vector<int> preL(preorder.begin()+1, preorder.begin()+1+index), preR(preorder.begin()+1+index, preorder.end());
        vector<int> inL(inorder.begin(), inorder.begin()+index), inR(inorder.begin()+index+1, inorder.end());
        root->left = buildTree(preL, inL);
        root->right = buildTree(preR, inR);
        
        return root;
    }
};