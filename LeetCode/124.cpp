/* *题目：
 *  124
 *  Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int res = root->val;
        helper(root, res);
        
        return res;
    }
    
    int helper(TreeNode* root, int & res){
        if(root == NULL){
            return 0;
        }
        
        int L = helper(root->left, res);
        int R = helper(root->right, res);
        res = max(res, L+R+root->val); //if *root is the top node in the path
        return max(0, max(L, R) + root->val); //if *root is in the path, if this branch a burden or a plus
    }
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        help(root, result);
        return result;
    }
    
    int help(TreeNode* root, int& result){
        if(!root)    
            return 0;
        int left = max(0, help(root->left, result)); // max 0, if < 0, not to hurt root
        int right = max(0, help(root->right, result));
        result = max(result, left+right+root->val);
        return max(left, right)+root->val;
    }
};