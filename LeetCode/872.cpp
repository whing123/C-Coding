/* *题目：
 *  872
 *  Leaf-Similar Trees
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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1, leaf2;

        collectLeaf(root1, leaf1);
        collectLeaf(root2, leaf2);

        if (leaf1.size() == leaf2.size()) {
            int i = 0;
            while (i < leaf1.size() && leaf1[i] == leaf2[i]) {
                i++;
            }
            
            if (i == leaf1.size()) {
                return true;
            }
        }
        
        return false;
    }
    
    void collectLeaf(TreeNode* root, vector<int>& leaf) {
        if (root != NULL) {
            if (root->left == NULL && root->right == NULL) {
                leaf.push_back(root->val);
                return;
            }
            
            if(root->left != NULL) {
                collectLeaf(root->left, leaf);
            }
            
            if(root->right != NULL) {
                collectLeaf(root->right, leaf);
            }
        }
    }
};