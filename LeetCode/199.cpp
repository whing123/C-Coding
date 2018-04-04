/* *题目：
 *  199
 *  Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        helper(root, 1, res);
        return res;
    }
    
    void helper(TreeNode* root, int level, vector<int> & vec){
        if(root == NULL){
            return;
        }
        
        if(vec.size() < level) vec.push_back(root->val); // 一层一个，每一层最右侧先遍历到
        helper(root->right, level+1, vec);
        helper(root->left, level+1, vec);
    }
    
};